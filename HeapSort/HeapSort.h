#ifndef HS 
#define HS

#include<iostream>
#include<algorithm>
#include<vector>

template <typename Sortable>
void adjust_max_Heap(std::vector<Sortable>& arr, int i, int n) 
{
    int largest = i; // 假设根节点是最大的
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点
    //从0开始

    // 如果左子节点存在且大于根节点，则更新最大值
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // 如果右子节点存在且大于当前最大值，则更新最大值
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // 如果最大值不是根节点，交换它们，并继续调整堆
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        adjust_max_Heap(arr, largest, n);
    }
}

template <typename Sortable>
void HeapSort(std::vector<Sortable>& arr)
{
    int n = arr.size();
    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        adjust_max_Heap(arr, i, n);
    }

    // 排序
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(arr[0], arr[i]);
        adjust_max_Heap(arr, 0, i);
    }
}

#endif