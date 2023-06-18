#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "core/panic.h"


void core::FPanic(const char* msg, const char * file, int line) {
    std::cout << "panicked at " 
        << file << ":" << line << std::endl
        << "msg: " << msg << std::endl
        << "errno: " << ::strerror(errno) << std::endl;
    ::exit(errno);
}
