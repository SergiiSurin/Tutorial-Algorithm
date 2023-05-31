// Ravesli_3.cpp : binary search in sorted array < big O(log n) >

#include <iostream>

const int arr[] = { 1, 4, 8, 11, 17, 23, 24, 37, 40, 48, 49, 55, 56, 57, 58, 59, 60 };
int binarySearch(const int* arr, int len, int searchNum);

int main()
{
    int searchNum;
    std::cout << "Enter a number to search between 0 and 60:\n";

    while (true)
    {
        std::cin >> searchNum;
        if ((searchNum < 0) || (searchNum > 60))
        {
            std::cout << "Please enter a valid search number between 0 and 60:\n";
            continue;
        }
        break;
    }
    int len = sizeof(arr) / sizeof(int);
    int res = binarySearch(arr, len, searchNum);
    if (res != -1)
        std::cout << "Number " << searchNum << " found in array by index " << res << std::endl;
    else
        std::cout << "The number " << searchNum << " does't exist in the array " << std::endl;
}


int binarySearch(const int* arr, int len, int searchNum)
{
    int low = 0;
    int high = len - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int guess = arr[mid];
        if (guess == searchNum)
            return mid;
        else if (guess > searchNum)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
