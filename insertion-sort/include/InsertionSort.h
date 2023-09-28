#pragma once
#include <iostream>
#include <utility>

namespace Sorting
{
    template <typename T, size_t N>
    class InsertionSort
    {
    public:
        InsertionSort(T (&data)[N]) : data(data) {}

        void sort()
        {
            for (size_t i = 1; i < N; ++i)
            {
                for (size_t j = i; j > 0 && data[j] < data[j - 1]; --j)
                    std::swap(data[j], data[j - 1]);
            }
        }

    private:
        T *const data;
    };
}
