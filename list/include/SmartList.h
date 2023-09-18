#pragma once
#include <memory>
#include <stdexcept>
#include <iostream>

namespace AbstractDataTypes
{
    template <typename T>
    class SmartList
    {
    public:
        SmartList() : count(0), items(nullptr) {}

        T get(int index);
        void insert(int index, T value);
        int search(int value);
        void remove(int index);
        int size() { return count; }

    private:
        int count;
        std::unique_ptr<T[]> items;
    };

    template <typename T>
    inline T SmartList<T>::get(int index)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("Index out of bounds");
        return items[index];
    }

    template <typename T>
    inline void SmartList<T>::insert(int index, T value)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("Index out of bounds");

        auto newItems = std::make_unique<T[]>(++count);
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

        items = std::move(newItems);
    }

    template <typename T>
    inline int SmartList<T>::search(int value)
    {
        for (int i = 0; i < count; i++)
        {
            if (value == items[i])
                return i;
        }
        throw std::runtime_error("Value not found");
    }

    template <typename T>
    inline void SmartList<T>::remove(int index)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("Index out of bounds");

        auto newItems = std::make_unique<T[]>(--count);
        for (int i = 0, j = 0; i < count; ++i, ++j)
        {
            if (index == j)
                ++j;
            newItems[i] = items[j];
        }

        items = std::move(newItems);
    }
}
