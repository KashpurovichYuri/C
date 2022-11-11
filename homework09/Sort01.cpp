// Code was taken from https://www.geeksforgeeks.org/merge-sort/ and slightly changed

#include <iostream>
#include <array>

template <typename T1, typename T2> // unresolved overloaded function type if we try to use it later as default template argument
bool SimpleBinComparator(const T1& first, const T2& second)
{
    return first <= second;
}

auto SimpleIntBinComparator(int first, int second)
{
    return first <= second;
}

template <typename T, typename Compare=decltype(SimpleIntBinComparator)>
void merge(T& array, int left, int mid, int right, Compare comp=SimpleIntBinComparator)
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

template <typename T, std::size_t size, typename Compare=decltype(SimpleIntBinComparator)>
void mergeSort(T (& array) [size], std::size_t begin=0, std::size_t end=size, Compare comp=SimpleIntBinComparator)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

template <typename T, typename Compare=decltype(SimpleIntBinComparator)>
void mergeSort(T* array, std::size_t begin, std::size_t end, Compare comp=SimpleIntBinComparator)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

template <typename T, std::size_t size> 
void printArray(T (& array) [size])
{
    for (auto i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
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
    int arr[] = { 12, 11, 13, 5, 6, 7 };
 
    std::cout << "Given array is \n";
    printArray(arr);
 
    mergeSort(arr);
 
    std::cout << "Sorted array is \n";
    printArray(arr);

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
