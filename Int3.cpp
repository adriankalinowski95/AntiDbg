#include "Int3.h"
#include <iostream>

namespace anti_debug{ 
/*
    Whenever a software interrupt exception occurs, the
    exception address, and the EIP register value, will
    point to the instruction after the one that caused the
    exception. A breakpoint exception is treated as a
    special case. When an EXCEPTION_BREAKPOINT
    (0x80000003) exception occurs, Windows assumes that it
    was caused by the one-byte "CC" opcode ("INT 3"
    instruction). Windows decrements the exception
    address to point to the assumed "CC" opcode, and then
    passes the exception to the exception handler. The
    EIP register value is not affected. Thus, if the "CD
    03" opcode (long form "INT 03" instruction) is used,
    the exception address will point to the "03" when the
    exception handler receives control.
*/
bool Int3::execute() {
    try
    {
        __debugbreak();
    }
    catch(...) {
        return true;
    }

    return false;
}

std::string_view Int3::getMethodName() {
    return "Int3";
}
}