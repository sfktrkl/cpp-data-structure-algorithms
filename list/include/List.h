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

    template <typename T>
    inline void List<T>::insert(int index, T value)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("Index out of bounds");

        ++count;
        auto newItems = new T[count];

        for (int i = 0, j = 0; i < count; ++i)
        {
            if (index == i)
                newItems[i] = value;
            else
            {
                newItems[i] = items[j];
                ++j;
            }
        }

        delete[] items;
        items = newItems;
    }

    template <typename T>
    inline int List<T>::search(int value)
    {
        for (int i = 0; i < count; i++)
        {
            if (value == items[i])
                return i;
        }
        throw std::runtime_error("Value not found");
    }
}
