// HwBpLib.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <cstddef>

namespace HwBp
{
    class Breakpoint
    {};

    Breakpoint Set(void* onPointer, std::size_t size)
    {
        return {};
    }

    void Remove(const Breakpoint&)
    {}
}
// TODO: Reference additional headers your program requires here.
