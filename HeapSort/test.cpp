#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "HeapSort.h"

// 检查排序是否正确
template <typename T>
bool check(const std::vector<T>& arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < arr[i - 1]) // 如果存在逆序，返回 false
        {
            return false;
        }
    }
    return true;
}

// 生成随机序列
std::vector<int> generate_random_sequence(size_t size)
{
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = dis(gen);
    }
    return arr;
}

// 测试排序函数
template <typename T>
void testSorting(std::vector<T>& arr, const std::string& sequence_type)
{
    std::cout << "Testing " << sequence_type << "...\n";
    
    // 记录堆排序时间
    auto start = std::chrono::high_resolution_clock::now();
    HeapSort(arr);  // 使用堆排序
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "HeapSort time: " << duration.count() << "s\n";

    // 检查排序是否正确
    if (check(arr))
    {
        std::cout << "Sorting is correct.\n";
    }
    else
    {
        std::cout << "Sorting is incorrect.\n";
    }

    // 使用 std::sort_heap 进行对比
    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(arr.begin(), arr.end());
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "std::sort_heap time: " << duration.count() << "s\n\n";
}

int main()
{
    const size_t SIZE = 1000000;  // 最小长度

    // 测试随机序列
    std::vector<int> randomArr = generate_random_sequence(SIZE);
    testSorting(randomArr, "Random Sequence");

    // 测试有序序列
    std::vector<int> orderedArr(SIZE);
    for (size_t i = 0; i < SIZE; ++i)
    {
        orderedArr[i] = i;  // 顺序填充
    }
    testSorting(orderedArr, "Ordered Sequence");

    // 测试逆序序列
    std::vector<int> reverseArr(SIZE);
    for (size_t i = 0; i < SIZE; ++i)
    {
        reverseArr[i] = SIZE - i - 1;  // 逆序填充
    }
    testSorting(reverseArr, "Reverse Sequence");

    // 测试部分元素重复序列
    std::vector<int> repetitiveArr(SIZE, 5);  // 所有元素初始化为 5
    testSorting(repetitiveArr, "Repetitive Sequence");

    // 额外测试：空序列和单元素序列
    std::vector<int> emptyArr;
    testSorting(emptyArr, "Empty Sequence");

    std::vector<int> singleArr = { 42 };  // 单元素序列
    testSorting(singleArr, "Single Element Sequence");

    return 0;
}
