#pragma once
#include <type_traits>
#include <functional>
#include <iostream>
#include <sstream>

namespace Utility
{
    template <typename T>
    class OutputStream;

    template <>
    class OutputStream<char>
    {
    public:
        static std::basic_ostream<char> &stream() { return std::cout; }
    };

    template <>
    class OutputStream<wchar_t>
    {
    public:
        static std::basic_ostream<wchar_t> &stream() { return std::wcout; }
    };

    template <typename T, typename = std::enable_if_t<std::is_same_v<T, char> || std::is_same_v<T, wchar_t>>>
    class StreamCapture
    {
    public:
        static std::basic_string<T> capture(std::function<void()> function)
        {
            auto &stream = OutputStream<T>::stream();
            StreamCapture<T> restore{stream};
            std::basic_ostringstream<T> oss;
            stream.rdbuf(oss.rdbuf());
            function();
            return oss.str();
        }

    private:
        StreamCapture(std::basic_ostream<T> &out)
            : out(out), old(out.rdbuf())
        {
        }

        ~StreamCapture()
        {
            out.rdbuf(old);
        }

        StreamCapture(const StreamCapture &) = delete;
        StreamCapture(StreamCapture &&) = delete;

        std::basic_ostream<T> &out;
        std::basic_streambuf<T> *old;
    };
}
