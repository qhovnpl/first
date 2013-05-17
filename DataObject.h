#ifndef DATA_OBJECT_H
#define DATA_OBJECT_H

#include <cstdint>
#include "PowerStorage_types.h"

using namespace ::PowerStorage;

class DataObject {
public:		
	DataObject();
	DataObject(int64_t src, int64_t dst, int64_t p, EdgeState::type s);
	
	int64_t srcID;
	int64_t dstID;
	int64_t pos;
	EdgeState::type status;
};

#endif
