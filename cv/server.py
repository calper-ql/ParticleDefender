import socket
import sys
from threading import Thread, Lock
from particles_pb2 import *

class Server:
    def __init__(self, PORT):
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print ('Socket created')
        HOST = ''
        #Bind socket to local host and port
        try:
            self.s.bind((HOST, PORT))
        except socket.error as msg:
            print ('Bind failed. Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
            sys.exit()

        print ('Socket bind complete')
        
        self.lock = Lock()
        self.data = ProtoParticleSet()
        self.count = 0

        t = Thread(target = self.listen)
        t.start()

    def listen(self):

        #Start listening on socket
        self.s.listen(10)
        print ('Socket now listening')

        #now keep talking with the client
        while 1:
            #wait to accept a connection - blocking call
            conn, addr = self.s.accept()
            print ('Connected with ' + addr[0] + ':' + str(addr[1]))

            t = Thread(target = self.client_thread, args = (conn,))
            t.start()
        self.s.close()

    def set_new_data(self, data):
        self.lock.acquire()
        n = self.data.particles.add()
        n.position.x = data.position.x
        n.position.y = data.position.y
        n.velocity.x = data.velocity.x
        n.velocity.y = data.velocity.y
        self.count += 1
        self.lock.release()

    def client_thread(self, conn):
        print("serving client")
      
        def send_ack(conn, pos):
            pa = ProtoAcknowledge()
            pa.count = 10
            if(pos):
                pa.state = ProtoAcknowledge.POSITIVE
            else:
                pa.state = ProtoAcknowledge.NEGATIVE
            conn.send(pa.SerializeToString())
        
        buff = ''
        last_count = 0
        while(1):
            rv = conn.recv(1000)
            pr = ProtoRequest()
            pr.ParseFromString(rv)
            if pr.value == ProtoRequest.HAS_NEW:
                pos = False
                self.lock.acquire()
                if(self.count > last_count):
                    last_count = self.count
                    data = self.data
                    pos = True
                    buff = self.data.SerializeToString()
                    self.data = ProtoParticleSet() 
                self.lock.release()
                send_ack(conn, pos)
            if pr.value == ProtoRequest.SIZE:
                ps = ProtoSize()
                ps.value = len(buff)
                conn.send(ps.SerializeToString())
            if pr.value == ProtoRequest.SET:
                conn.send(buff)
                buff = ''.encode()



