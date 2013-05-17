#include "DataObject.h"

DataObject::DataObject() :
	srcID(0), dstID(0), pos(0), status(EdgeState::type::Positive)
{
}

DataObject::DataObject(int64_t src, int64_t dst, int64_t p, EdgeState::type s) :
	srcID(src), dstID(dst), pos(p), status(s)
{
}
