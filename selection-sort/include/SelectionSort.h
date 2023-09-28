#pragma once
#include <iostream>
#include <utility>

namespace Sorting
{
    template <typename T, size_t N>
    class SelectionSort
    {
    public:
        SelectionSort(T (&data)[N]) : data(data) {}

        void sort()
        {
            for (size_t i = 0; i < N - 1; ++i)
            {
                size_t minIndex = i;
                for (size_t j = i + 1; j < N; j++)
                {
                    if (data[j] < data[minIndex])
                        minIndex = j;
                }
                std::swap(data[i], data[minIndex]);
            }
        }

    private:
        T *const data;
    };
}
