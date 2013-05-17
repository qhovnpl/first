libraries = ['thrift', 'thriftnb', 'event', 'boost_system', 'boost_filesystem']
flags = ['-DHAVE_INTTYPES_H', '-DHAVE_NETINET_IN_H', '-std=c++11']
src = ['Server.cpp', 'PowerStorage.cpp', 'PowerStorage_types.cpp', 'PowerStorage_constants.cpp', 'FileObject.cpp', 'DataObject.cpp']
Program(target='server', source=src, LIBS=libraries, CCFLAGS=flags)
