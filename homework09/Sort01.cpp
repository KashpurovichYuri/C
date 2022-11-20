// Code was taken from https://www.geeksforgeeks.org/merge-sort/ and slightly changed

#include <iostream>
#include <array>
#include <functional>

template <typename T, typename Compare=std::less<>>
void merge(T& array, int left, int mid, int right, Compare comp=std::less{})
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; ++i)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; ++j)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0;
    auto indexOfSubArrayTwo = 0;
    auto indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (comp(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo]))
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T, typename Compare=std::less<>>
void mergeSort(T* array, std::size_t begin, std::size_t end, Compare comp=std::less{})
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

template <typename T>
auto FixToDyn(T* array, std::size_t size)
{
    T* new_array = new T[size];
    for (auto i = 0; i < size; ++i)
        new_array[i] = array[i];

    return new_array;
}

template < typename T >
void printArray(T* array, std::size_t size)
{   
    for (auto i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
 
int main()
{
    std::size_t size_arr = 6;
    int arr[size_arr] = { 12, 11, 13, 5, 6, 7 };
 
    std::cout << "Given array is \n";
    printArray(arr, size_arr);

    int* arr1 = new int[size_arr];
    arr1 = FixToDyn(arr, size_arr);
    mergeSort(arr1, 0, size_arr);
 
    std::cout << "Sorted array is \n";
    printArray(arr1, size_arr);

    std::cout << std::endl;

    std::size_t size = 6;
    int *arr_dyn = new int[size];
    for (auto i = 0; i < size; ++i)
        arr_dyn[i] = 6 - i;
    std::cout << "Given array is \n";
    printArray(arr_dyn, size);
 
    mergeSort(arr_dyn, 0, size);
 
    std::cout << "Sorted array is \n";
    printArray(arr_dyn, size);
}
