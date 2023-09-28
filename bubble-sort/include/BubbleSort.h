#pragma once
#include <iostream>
#include <utility>

namespace Sorting
{
    template <typename T, size_t N>
    class BubbleSort
    {
    public:
        BubbleSort(T (&data)[N]) : data(data) {}

        void sort()
        {
            for (size_t i = 0; i < N - 1; ++i)
            {
                for (size_t j = 0; j < N - i - 1; j++)
                {
                    if (data[j] > data[j + 1])
                        std::swap(data[j], data[j + 1]);
                }
            }
        }

    private:
        T *const data;
    };
}
