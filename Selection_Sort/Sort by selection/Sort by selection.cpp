#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()
#include <iomanip>
#include <limits.h>



int getRandomNumber(int min, int max);
int* firstArrayInition(const int SIZE, const int MIN, const int MAX);
void printArray(const int* arr, const int SIZE, const int ROW);
int findNextSmallest(const int* array, const int SIZE, int* oldSmallestIndex, int* oldSmallest);

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
	
	int* newArray = new int[SIZE];
		
	int oldSmallestIndex = 0;
	int oldSmallest = INT_MIN;
	

	for (int i = 0; i < SIZE; ++i)
	{
		newArray[i] = array[findNextSmallest(array, SIZE, & oldSmallestIndex, &oldSmallest)];
	}
		
	std::cout << std::endl;

	printArray(newArray, SIZE, ROW);
	

	delete[] array;
	delete[] newArray;
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

int findNextSmallest(const int* array, const int SIZE, int* oldSmallestIndex, int* oldSmallest)
{
	int smallestIndex = 0;
	int smallest = INT_MAX;
	for (int currentIndex = 0; currentIndex < SIZE; ++currentIndex)
	{
		// search for the next minimum in the array
		if ((array[currentIndex] < smallest) && (*oldSmallest <= array[currentIndex]))
		{   // processing if there is more than one identical element in the array
			if ((*oldSmallest == array[currentIndex]) && (currentIndex <= *oldSmallestIndex))
				continue;
			else
			{
				smallest = array[currentIndex];
				smallestIndex = currentIndex;
			}
		}

	}
	*oldSmallest = smallest;
	*oldSmallestIndex = smallestIndex;

	return smallestIndex;
}