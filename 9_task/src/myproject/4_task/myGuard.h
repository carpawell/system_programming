#include <iostream>


struct MyGuard {
    std::ostream& stream;
    std::ios::fmtflags stream_flags;
    char stream_fill;
    std::ios::iostate stream_exceptions;

    MyGuard(std::ostream& str): stream(str) {
        stream_flags = stream.flags();
        stream_fill = stream.fill();
        stream_exceptions = str.exceptions();
    }

    ~MyGuard() {
        stream.flags(stream_flags);
        stream.fill(stream_fill);
        stream.exceptions(stream_exceptions);
    }
};