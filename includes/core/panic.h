#pragma once


namespace core {
    void FPanic(const char* msg, const char * file, int line);
}


#define Panic(msg) core::FPanic(msg, __FILE__, __LINE__)
