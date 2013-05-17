/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef PowerStorage_TYPES_H
#define PowerStorage_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>



namespace PowerStorage {

struct EdgeState {
  enum type {
    Positive = 0,
    Negative = 3,
    Removed = 1,
    Archived = 2
  };
};

extern const std::map<int, const char*> _EdgeState_VALUES_TO_NAMES;

typedef struct _Edge__isset {
  _Edge__isset() : srcID(false), dstID(false), pos(false), status(false) {}
  bool srcID;
  bool dstID;
  bool pos;
  bool status;
} _Edge__isset;

class Edge {
 public:

  static const char* ascii_fingerprint; // = "4065EDEF6EACF4EBD9E43C9AB52197F9";
  static const uint8_t binary_fingerprint[16]; // = {0x40,0x65,0xED,0xEF,0x6E,0xAC,0xF4,0xEB,0xD9,0xE4,0x3C,0x9A,0xB5,0x21,0x97,0xF9};

  Edge() : srcID(0), dstID(0), pos(0), status((EdgeState::type)0) {
  }
  
  Edge(int64_t src, int64_t dst, int64_t p) : srcID(src), dstID(dst), pos(p), status(EdgeState::type::Positive) {
  }

  virtual ~Edge() throw() {}

  int64_t srcID;
  int64_t dstID;
  int64_t pos;
  EdgeState::type status;

  _Edge__isset __isset;

  void __set_srcID(const int64_t val) {
    srcID = val;
  }

  void __set_dstID(const int64_t val) {
    dstID = val;
  }

  void __set_pos(const int64_t val) {
    pos = val;
  }

  void __set_status(const EdgeState::type val) {
    status = val;
  }

  bool operator == (const Edge & rhs) const
  {
    if (!(srcID == rhs.srcID))
      return false;
    if (!(dstID == rhs.dstID))
      return false;
    if (!(pos == rhs.pos))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const Edge &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Edge & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Edge &a, Edge &b);

} // namespace

#endif