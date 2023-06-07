// Ravesli_3.cpp : binary search in sorted array < big O(log n) >

#include <iostream>

const int arr[] = { 1, 4, 8, 11, 17, 23, 24, 37, 40, 48, 49, 55, 56, 57, 58, 59, 60 };

int binarySearch(const int* arr, int len, int target);
int getValue();

int main()
{
    int targetValue = getValue();
        
    int len = sizeof(arr) / sizeof(int);
    int res = binarySearch(arr, len, targetValue);
    if (res != -1)
        std::cout << "Number " << targetValue << " found in array by index " << res << std::endl;
    else
        std::cout << "The number " << targetValue << " does't exist in the array " << std::endl;
}


int binarySearch(const int* arr, int len, int target)
{
    int l = 0;
    int r = len - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
     
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int getValue()
{
    while (true)
    {
        
        std::cout << "Enter any integer value between 0 and 60:\n";
        int a;
        std::cin >> a;


        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return a;
        }
    }
}
