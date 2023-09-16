#pragma once
#include <stdexcept>

namespace AbstractDataTypes
{
    template <typename T>
    class List
    {
    public:
        List() : count(0), items(nullptr) {}

        ~List()
        {
            delete[] items;
            items = nullptr;
        }

        T get(int index);
        void insert(int index, T value);
        int search(int value);
        void remove(int index);
        int size() { return count; }

    private:
        int count;
        T *items;
    };

    template <typename T>
    inline T List<T>::get(int index)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("Index out of bounds");
        return items[index];
    }
}
