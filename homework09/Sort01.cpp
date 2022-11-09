// Code was taken from https://www.geeksforgeeks.org/merge-sort/ and slightly changed

#include <iostream>
#include <array>

template <typename T1, typename T2> // unresolved overloaded function type if we try to use it later
bool SimpleBinComparator(const T1& first, const T2& second)
{
    return first <= second;
}

auto SimpleIntBinComparator(const int first, const int second) // ok to use
{
    return first <= second;
}

template <typename T, typename Compare>
void merge(T& array, int const left, int const mid, int const right, Compare comp)
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

template <typename T, std::size_t size, typename Compare> // is it possible to make default typename Compare with SimpleIntBinComparator?
void mergeSort(T (& array) [size], Compare comp, std::size_t const begin=0, std::size_t const end=size)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, comp, begin, mid);
    mergeSort(array, comp, mid + 1, end);
    merge(array, begin, mid, end, comp);
}

template <typename T, typename Compare>
void mergeSort(T* array, Compare comp, std::size_t size, std::size_t const begin=0, std::size_t const end=size) // error: parameter 'size' may not appear in this context
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, comp, begin, mid);
    mergeSort(array, comp, mid + 1, end);
    merge(array, begin, mid, end, comp);
}


template <typename T, std::size_t size> 
void printArray(T (& array) [size])
{
    for (auto i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

// doesn't work when called without size. For example, error: no matching function for call to 'printArray(int*&)'...
template <typename T> 
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
 
    mergeSort(arr, SimpleIntBinComparator);
 
    std::cout << "Sorted array is \n";
    printArray(arr);

    std::cout << std::endl;
/*
    std::size_t size = 6;
    int *arr_dyn = new int[size];
    for (auto i = 0; i < size; ++i)
        arr_dyn[i] = 6 - i;
    std::cout << "Given array is \n";
    // doesn't work: error: no matching function for call to 'printArray(int*&)'
    printArray(arr_dyn);
 
    mergeSort(arr_dyn, SimpleIntBinComparator);
 
    std::cout << "Sorted array is \n";
    printArray(arr_dyn);
*/
}
