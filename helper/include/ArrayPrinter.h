#pragma once
#include <iostream>

namespace Utility
{
    template <typename T, size_t N>
    class ArrayPrinter
    {
    public:
        ArrayPrinter(const T (&data)[N]) : data(data) {}

        friend std::ostream &operator<<(std::ostream &os, const ArrayPrinter<T, N> &printer)
        {
            for (size_t i = 0; i < N; i++)
                os << printer.data[i] << " ";
            return os;
        }

    private:
        const T *const data;
    };
}
