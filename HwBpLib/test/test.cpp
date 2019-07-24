#include "HwBpLib.h"
#include <iostream>

#include <Windows.h>

/*
PVOID AddVectoredContinueHandler(
  ULONG                       First,
  PVECTORED_EXCEPTION_HANDLER Handler
);
*/
namespace
{
    static bool bpFound = false;
}

LONG MyHandler(_EXCEPTION_POINTERS* ExceptionInfo)
{
    if (ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT)
    {
        bpFound = true;
    }

    return EXCEPTION_CONTINUE_SEARCH;
}

void AssertTrue(const char* str, bool result, int line, const char* file)
{
    if (!result)
    {
        std::cout << "Assertion failed (" << file << ": " << line << "): " << str << "\n";
        
        std::exit(EXIT_FAILURE);
    }
}

#define ASSERT(Expr_) \
    AssertTrue(#Expr_, (Expr_), __LINE__, __FILE__);

int main()
{
    int var = 42;
    auto bp = HwBp::Set(&var, sizeof(42));

    var = 33;
    DebugBreak();
    ASSERT(bpFound);

    HwBp::Remove(bp);

    std::cout << "Success!\n";
    return 0;
}