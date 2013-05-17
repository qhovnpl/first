#include "FileObject.h"
#include <fstream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost;

FileObject::FileObject() {
	filename = "datafile";
	if (!filesystem::exists(filename)) {
		fstream file(filename.c_str(), ios::out | ios::binary);
		file.close();
	}
}

void FileObject::add(int64_t srcID, int64_t dstID, int64_t pos) {
	mutexLock.lock();
	
	fstream file(filename.c_str(), ios::out | ios::app | ios::binary);
	DataObject obj(srcID, dstID, pos, EdgeState::type::Positive);
	file.write((char*) &obj, sizeof(obj));
	file.close();
	
	mutexLock.unlock();
}

void FileObject::remove(int64_t srcID, int64_t dstID) {
	mutexLock.lock();
	
	DataObject obj;
	fstream file(filename.c_str(), ios::in | ios::out | ios::binary);
	while (true) {
		file.read((char*) &obj, sizeof(obj));
		if (file.good()) {
			if (obj.srcID == srcID && obj.dstID == dstID && 
				(obj.status == EdgeState::type::Positive || obj.status == EdgeState::type::Negative)) 
			{
				file.seekg(-sizeof(DataObject), ios_base::cur);
				obj.status = EdgeState::type::Removed;
				file.write((char*) &obj, sizeof(obj));
			}
		} else {
			break;
		}
	}
	file.close();
	
	mutexLock.unlock();
}

vector<Edge> FileObject::selectOne(int64_t srcID, int64_t dstID) {
	mutexLock.lock();
	
	vector<Edge> _return;
	DataObject obj;
	fstream file(filename.c_str(), ios::in | ios::binary);
	while (true) {
		file.read((char*) &obj, sizeof(obj));
		if (file.good()) {
			if (obj.srcID == srcID && obj.dstID == dstID && obj.status == EdgeState::type::Positive) {
				_return.push_back(Edge(obj.srcID, obj.dstID, obj.pos));
				file.close();
				mutexLock.unlock();
				return _return;
			}
		} else {
			break;
		}
	}
	file.close();
	
	mutexLock.unlock();
	return _return;
}

vector<Edge> FileObject::selectFrom(int64_t srcID) {
	mutexLock.lock();
	
	vector<Edge> _return;
	DataObject obj;
	fstream file(filename.c_str(), ios::in | ios::binary);
	while (true) {
		file.read((char*) &obj, sizeof(obj));
		if (file.good()) {
			if (obj.srcID == srcID && obj.status == EdgeState::type::Positive) {
				_return.push_back(Edge(obj.srcID, obj.dstID, obj.pos));
			}
		} else {
			break;
		}
	}
	file.close();
	
	mutexLock.unlock();
	return _return;
}

vector<Edge> FileObject::selectTo(int64_t dstID) {
	mutexLock.lock();
	
	vector<Edge> _return;
	DataObject obj;
	fstream file(filename.c_str(), ios::in | ios::binary);
	while (true) {
		file.read((char*) &obj, sizeof(obj));
		if (file.good()) {
			if (obj.dstID == dstID && obj.status == EdgeState::type::Positive) {
				_return.push_back(Edge(obj.srcID, obj.dstID, obj.pos));
			}
		} else {
			break;
		}
	}
	file.close();
	
	mutexLock.unlock();
	return _return;
}

