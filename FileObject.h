#ifndef FILE_OBJECT_H
#define FILE_OBJECT_H

#include <cstdio>
#include <string>
#include <mutex>
#include <vector>

#include "PowerStorage.h"
#include "DataObject.h"

using namespace std;
using namespace ::PowerStorage;

class FileObject {
public:
	FileObject();
	
	void add(int64_t srcID, int64_t dstID, int64_t pos);
	void remove(int64_t srcID, int64_t dstID);
	vector<Edge> selectOne(int64_t srcID, int64_t dstID);
	vector<Edge> selectFrom(int64_t srcID);
	vector<Edge> selectTo(int64_t dstID);
	
private:
	mutex mutexLock;
	string filename;
};

#endif
