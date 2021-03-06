#
# Autogenerated by Thrift Compiler (0.9.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py
#

from thrift.Thrift import TType, TMessageType, TException, TApplicationException

from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol, TProtocol
try:
  from thrift.protocol import fastbinary
except:
  fastbinary = None


class EdgeState:
  Positive = 0
  Negative = 3
  Removed = 1
  Archived = 2

  _VALUES_TO_NAMES = {
    0: "Positive",
    3: "Negative",
    1: "Removed",
    2: "Archived",
  }

  _NAMES_TO_VALUES = {
    "Positive": 0,
    "Negative": 3,
    "Removed": 1,
    "Archived": 2,
  }


class Edge:
  """
  Attributes:
   - srcID
   - dstID
   - pos
   - status
  """

  thrift_spec = (
    None, # 0
    (1, TType.I64, 'srcID', None, None, ), # 1
    (2, TType.I64, 'dstID', None, None, ), # 2
    (3, TType.I64, 'pos', None, None, ), # 3
    (4, TType.I32, 'status', None, None, ), # 4
  )

  def __init__(self, srcID=None, dstID=None, pos=None, status=None,):
    self.srcID = srcID
    self.dstID = dstID
    self.pos = pos
    self.status = status

  def read(self, iprot):
    if iprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastbinary is not None:
      fastbinary.decode_binary(self, iprot.trans, (self.__class__, self.thrift_spec))
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.I64:
          self.srcID = iprot.readI64();
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.I64:
          self.dstID = iprot.readI64();
        else:
          iprot.skip(ftype)
      elif fid == 3:
        if ftype == TType.I64:
          self.pos = iprot.readI64();
        else:
          iprot.skip(ftype)
      elif fid == 4:
        if ftype == TType.I32:
          self.status = iprot.readI32();
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if oprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and self.thrift_spec is not None and fastbinary is not None:
      oprot.trans.write(fastbinary.encode_binary(self, (self.__class__, self.thrift_spec)))
      return
    oprot.writeStructBegin('Edge')
    if self.srcID is not None:
      oprot.writeFieldBegin('srcID', TType.I64, 1)
      oprot.writeI64(self.srcID)
      oprot.writeFieldEnd()
    if self.dstID is not None:
      oprot.writeFieldBegin('dstID', TType.I64, 2)
      oprot.writeI64(self.dstID)
      oprot.writeFieldEnd()
    if self.pos is not None:
      oprot.writeFieldBegin('pos', TType.I64, 3)
      oprot.writeI64(self.pos)
      oprot.writeFieldEnd()
    if self.status is not None:
      oprot.writeFieldBegin('status', TType.I32, 4)
      oprot.writeI32(self.status)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def validate(self):
    return


  def __repr__(self):
    L = ['%s=%r' % (key, value)
      for key, value in self.__dict__.iteritems()]
    return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

  def __eq__(self, other):
    return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

  def __ne__(self, other):
    return not (self == other)
