# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: particles.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='particles.proto',
  package='',
  syntax='proto3',
  serialized_pb=_b('\n\x0fparticles.proto\".\n\x0bProtoVector\x12\t\n\x01x\x18\x01 \x01(\x02\x12\t\n\x01y\x18\x02 \x01(\x02\x12\t\n\x01z\x18\x03 \x01(\x02\"O\n\rProtoParticle\x12\x1e\n\x08position\x18\x01 \x01(\x0b\x32\x0c.ProtoVector\x12\x1e\n\x08velocity\x18\x02 \x01(\x0b\x32\x0c.ProtoVector\"a\n\x10ProtoAcknowledge\x12$\n\x05state\x18\x01 \x01(\x0e\x32\x15.ProtoAcknowledge.ACK\"\'\n\x03\x41\x43K\x12\x08\n\x04NONE\x10\x00\x12\x0c\n\x08\x43ONTINUE\x10\x01\x12\x08\n\x04STOP\x10\x02\"5\n\x10ProtoParticleSet\x12!\n\tparticles\x18\x01 \x03(\x0b\x32\x0e.ProtoParticleb\x06proto3')
)



_PROTOACKNOWLEDGE_ACK = _descriptor.EnumDescriptor(
  name='ACK',
  full_name='ProtoAcknowledge.ACK',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='NONE', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='CONTINUE', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='STOP', index=2, number=2,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=206,
  serialized_end=245,
)
_sym_db.RegisterEnumDescriptor(_PROTOACKNOWLEDGE_ACK)


_PROTOVECTOR = _descriptor.Descriptor(
  name='ProtoVector',
  full_name='ProtoVector',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='x', full_name='ProtoVector.x', index=0,
      number=1, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='y', full_name='ProtoVector.y', index=1,
      number=2, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='z', full_name='ProtoVector.z', index=2,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=19,
  serialized_end=65,
)


_PROTOPARTICLE = _descriptor.Descriptor(
  name='ProtoParticle',
  full_name='ProtoParticle',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='position', full_name='ProtoParticle.position', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='velocity', full_name='ProtoParticle.velocity', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=67,
  serialized_end=146,
)


_PROTOACKNOWLEDGE = _descriptor.Descriptor(
  name='ProtoAcknowledge',
  full_name='ProtoAcknowledge',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='state', full_name='ProtoAcknowledge.state', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _PROTOACKNOWLEDGE_ACK,
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=148,
  serialized_end=245,
)


_PROTOPARTICLESET = _descriptor.Descriptor(
  name='ProtoParticleSet',
  full_name='ProtoParticleSet',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='particles', full_name='ProtoParticleSet.particles', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=247,
  serialized_end=300,
)

_PROTOPARTICLE.fields_by_name['position'].message_type = _PROTOVECTOR
_PROTOPARTICLE.fields_by_name['velocity'].message_type = _PROTOVECTOR
_PROTOACKNOWLEDGE.fields_by_name['state'].enum_type = _PROTOACKNOWLEDGE_ACK
_PROTOACKNOWLEDGE_ACK.containing_type = _PROTOACKNOWLEDGE
_PROTOPARTICLESET.fields_by_name['particles'].message_type = _PROTOPARTICLE
DESCRIPTOR.message_types_by_name['ProtoVector'] = _PROTOVECTOR
DESCRIPTOR.message_types_by_name['ProtoParticle'] = _PROTOPARTICLE
DESCRIPTOR.message_types_by_name['ProtoAcknowledge'] = _PROTOACKNOWLEDGE
DESCRIPTOR.message_types_by_name['ProtoParticleSet'] = _PROTOPARTICLESET
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ProtoVector = _reflection.GeneratedProtocolMessageType('ProtoVector', (_message.Message,), dict(
  DESCRIPTOR = _PROTOVECTOR,
  __module__ = 'particles_pb2'
  # @@protoc_insertion_point(class_scope:ProtoVector)
  ))
_sym_db.RegisterMessage(ProtoVector)

ProtoParticle = _reflection.GeneratedProtocolMessageType('ProtoParticle', (_message.Message,), dict(
  DESCRIPTOR = _PROTOPARTICLE,
  __module__ = 'particles_pb2'
  # @@protoc_insertion_point(class_scope:ProtoParticle)
  ))
_sym_db.RegisterMessage(ProtoParticle)

ProtoAcknowledge = _reflection.GeneratedProtocolMessageType('ProtoAcknowledge', (_message.Message,), dict(
  DESCRIPTOR = _PROTOACKNOWLEDGE,
  __module__ = 'particles_pb2'
  # @@protoc_insertion_point(class_scope:ProtoAcknowledge)
  ))
_sym_db.RegisterMessage(ProtoAcknowledge)

ProtoParticleSet = _reflection.GeneratedProtocolMessageType('ProtoParticleSet', (_message.Message,), dict(
  DESCRIPTOR = _PROTOPARTICLESET,
  __module__ = 'particles_pb2'
  # @@protoc_insertion_point(class_scope:ProtoParticleSet)
  ))
_sym_db.RegisterMessage(ProtoParticleSet)


# @@protoc_insertion_point(module_scope)