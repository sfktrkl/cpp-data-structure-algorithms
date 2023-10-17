#pragma once
#include <iostream>
#include <utility>

namespace Sorting
{
    template <typename T, size_t N>
    class MergeSort
    {
    public:
        MergeSort(T (&data)[N]) : data(data) {}

        void sort()
        {
            mergeSort(0, N - 1);
        }

    private:
        void merge(int left, int middle, int right)
        {
            int count = right - left + 1;
            T *temp = new T[count];

            int leftPointer = left;
            int rightPointer = middle + 1;

            int merged = 0;
            while (leftPointer <= middle && rightPointer <= right)
            {
                if (data[leftPointer] <= data[rightPointer])
                    temp[merged++] = data[leftPointer++];
                else
                    temp[merged++] = data[rightPointer++];
            }

            while (leftPointer <= middle)
                temp[merged++] = data[leftPointer++];

            while (rightPointer <= right)
                temp[merged++] = data[rightPointer++];

            for (int i = 0; i < count; ++i)
                data[left + i] = temp[i];
            delete[] temp;
        }

        void mergeSort(int left, int right)
        {
            if (left < right)
            {
                int middle = left + (right - left) / 2;
                mergeSort(left, middle);
                mergeSort(middle + 1, right);
                merge(left, middle, right);
            }
        }

        T *const data;
    };
}
