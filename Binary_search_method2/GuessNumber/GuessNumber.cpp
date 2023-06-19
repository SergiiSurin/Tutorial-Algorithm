// GuessNumber.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()

int getRandomNumber(const int min, const int max);
int getValue();
void coincidenceAnalysis(int guess, int hidden, int & countRightPlace, int & countGuessDigit);

enum Constanta
{
	SIZE = 3
};

int main()
{
	const int MIN = 0;	// minimum value of array's element
    const int MAX = 999; // maximum value of array's element

    srand(static_cast<unsigned int>(time(0))); // set value of system timer into srand()  
    rand(); // throw away the first result

	int hidden = getRandomNumber(MIN, MAX);
	//std::cout << hidden << "\n";
		
	while (1)
	{
		int guess = getValue();
		if (guess == hidden)
		{
			std::cout << "Guessed: 3. In their places: 3 \n";
			std::cout << "***You guess!!! The hidden number is " << guess << " !!! ***\n";
			break;
		}
		
		int outCountRightPlace = 0;
		int outCountGuessDigit = 0;

		coincidenceAnalysis(guess, hidden, outCountRightPlace, outCountGuessDigit);
		
		std::cout << "Guessed: " << outCountGuessDigit << ". In their places: " << outCountRightPlace << " \n";
	}

    return 0;
}
int getRandomNumber(const int min, const int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int getValue()
{
	while (true)
	{
		std::cout << "Enter a positive integer number between 000 to 999: ";
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
			std::cout << "\nYour try: ";
			std::cout.fill('0');
			std::cout << std::setw(3) << a << '\n';
			return a;
		}
	}
}

void coincidenceAnalysis(int guess, int hidden, int& countRightPlace, int& countGuessDigit)
{
	int arrayGuessDigit[Constanta::SIZE]{ 0 };
	int arrayHiddenDigit[Constanta::SIZE]{ 0 };

	for (int i = 2; i >= 0; --i)
	{
		arrayGuessDigit[i] = guess % 10;
		arrayHiddenDigit[i] = hidden % 10;
		if (arrayGuessDigit[i] == arrayHiddenDigit[i])
		{ 
			++countRightPlace;
			++countGuessDigit;
			arrayGuessDigit[i] = -1;
			arrayHiddenDigit[i] = -1;
		}
		guess /= 10;
		hidden /= 10;		
	}
	
	for (int i = 0; i < 3; ++i)
	{ 
		int guessDigit = arrayGuessDigit[i];
		if (guessDigit == -1) 
			continue;
		for (int j = 0; j < 3; ++j)
		{
			if (guessDigit == arrayHiddenDigit[j])
			{ 
				arrayHiddenDigit[j] = -1;
				++countGuessDigit;
				break;
			}
		}
	}
}
