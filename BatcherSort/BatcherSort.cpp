﻿#include <iostream>
#include <vector>

template <class T>
void compexch(T& a, T& b)
{
    if (a > b)
        std::swap(a, b);
}

template <class T>
void merge(std::vector<T>& a, int l, int n, int r)
{
    int m = r * 2;
    if (m < n)
    {
        merge(a, l, n, m);      // even subsequence
        merge(a, l + r, n, m);    // odd subsequence
        for (int i = l + r; i + r < l + n; i += m)
            compexch(a[i], a[i + r]);
    }
    else
        compexch(a[l], a[l + r]);
}

template <class T>
void OddEvenMergeSort(std::vector<T>& a, int l, int n)
{
    if (n > 1)
    {
        int m = n / 2;
        OddEvenMergeSort(a, l, m);
        OddEvenMergeSort(a, l + m, m);
        merge(a, l, n, 1);
    }
}

int main()
{
    std::vector<int> sort = { 3, 7, 4, 8, 6, 2, 1, 5 };
    OddEvenMergeSort(sort, 0, sort.size());
    for (size_t i = 0; i < sort.size(); i++)
    {
        std::cout << sort[i] << " ";
    }
    
}

