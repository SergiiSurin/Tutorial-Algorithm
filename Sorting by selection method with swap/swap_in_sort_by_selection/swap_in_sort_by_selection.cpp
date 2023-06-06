// swap_in_sort_by_selection.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()
#include <iomanip>
#include <limits.h>

int getRandomNumber(int min, int max);
int* firstArrayInition(const int SIZE, const int MIN, const int MAX);
void printArray(const int* arr, const int SIZE, const int ROW);
void swap(int * value1, int* value2);
void sortArray(int* arr, const int SIZE);


int main()
{
const int SIZE = 30; // size of an array of int values
const int ROW = 15;
const int MIN = 0;	// minimum value of array's element
const int MAX = 500; // maximum value of array's element

srand(static_cast<unsigned int>(time(0))); // set value of system timer into srand()  
rand(); // throw away the first result

int* array = firstArrayInition(SIZE, MIN, MAX);

printArray(array, SIZE, ROW);

sortArray(array, SIZE);

std::cout << std::endl;

printArray(array, SIZE, ROW);


delete[] array;
return 0;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int* firstArrayInition(const int SIZE, const int MIN, const int MAX)
{
	int* arr = new int[SIZE]; // array 15xN 

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = getRandomNumber(MIN, MAX);
	}
	return arr;
}

void printArray(const int* arr, const int SIZE, const int ROW)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << std::setw(3) << std::right << arr[i] << " ";
		if (!((i + 1) % ROW))
			std::cout << std::endl;
	}
}

void swap(int* value1, int* value2)
{
	int tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;
}

void sortArray(int* arr, const int SIZE)
{
	for (int startIndex = 0; startIndex < SIZE - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < SIZE; ++currentIndex)
		{
			if (arr[currentIndex] < arr[smallestIndex])
				smallestIndex = currentIndex;
		}
		swap(&(arr[startIndex]), &(arr[smallestIndex]));
	}
}