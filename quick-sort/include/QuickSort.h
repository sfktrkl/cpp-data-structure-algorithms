#pragma once
#include <iostream>
#include <utility>

namespace Sorting
{
    template <typename T, size_t N>
    class QuickSort
    {
    public:
        QuickSort(T (&data)[N]) : data(data) {}

        void sort()
        {
            quickSort(0, N - 1);
        }

    private:
        int partition(int left, int right)
        {
            int pivot = data[left];

            int middle = left;
            for (int i = left + 1; i <= right; ++i)
            {
                if (data[i] < pivot)
                    std::swap(data[i], data[++middle]);
            }
            std::swap(data[left], data[middle]);

            return middle;
        }

        void quickSort(int left, int right)
        {
            if (left < right)
            {
                int pivot = partition(left, right);
                quickSort(left, pivot - 1);
                quickSort(pivot + 1, right);
            }
        }

        T *const data;
    };
}
