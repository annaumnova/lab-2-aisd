//0301 Umnova variant 1
#include <ctime>
#include <iostream>
#include <stdio.h>
#include "search and sort.cpp"
const int size_massive = 10;

//the function that may be used if user wants to create any massive by himself 
/*template <typename T> 
void creating_your_massive(T* massive, size_t size) 
{
	std::cout << "Enter the elements: " << std::endl;
	for (int i = 0; i < size; i++)
		std::cin >> massive[i];
}*/

void INT_creating_random_massive(int* massive, size_t size)
{
	for (int i = 0; i < size; i++)
		massive[i] = rand() % 200;
}

void CHAR_creating_random_massive(char* massive, size_t size)
{
	for (int i = 0; i < size; i++)
		massive[i] = rand() % 256;
}

template <typename T>
void out_massive(T* massive, size_t size_of_massive) 
{
	for (int i = 0; i < size_of_massive; i++)
		std::cout << massive[i] << " ";
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "English"); 
	int* massive = new int[size_massive];//memory allocation for massive

	//bogo is very slow...
	/*Bogo sort*/
	INT_creating_random_massive(massive, size_massive);
	std::cout << "This is not sorted massive: " << std::endl;
	out_massive(massive, size_massive);
	std::cout << "Bogo sort: " << std::endl;
	SortandSearch::BogoSort(massive, size_massive);
	out_massive(massive, size_massive);
	std::cout << std::endl;

	//QS isn't sorting all massive! :(
	//it sorts the right and the left 
	/*Quick sort*/
	INT_creating_random_massive(massive, size_massive);
	std::cout << "This is not sorted massive: " << std::endl;
	out_massive(massive, size_massive);
	std::cout << "Quick sort: " << std::endl; 
	SortandSearch::QuickSort(massive, size_massive);
	out_massive(massive, size_massive);
	std::cout << std::endl;

	/*Insertion sort*/
	INT_creating_random_massive(massive, size_massive);
	std::cout << "This is not sorted massive: " << std::endl;
	out_massive(massive, size_massive);
	std::cout << "Insertion sort: " << std::endl;
	SortandSearch::InsertionSort(massive, size_massive);
	out_massive(massive, size_massive);
	
	/*Binary search*/
	std::cout << "Binary search for this massive: " << std::endl;
	std::cout << "What is your found number (element)?" << std::endl;
	int number;//it's that you want to find in this massive
	std::cin >> number;
	std::cout << "The index is: " << SortandSearch::BinarySearch(massive, size_massive, number) << std::endl;
	std::cout << std::endl;

	delete[] massive;//delete the massive

	/*Counting sort for char*/
	char* massive_ch = new char[size_massive];
	CHAR_creating_random_massive(massive_ch, size_massive);
	std::cout << "This is not sorted massive: " << std::endl;
	out_massive(massive_ch, size_massive);
	std::cout << "Counting sort for char: " << std::endl;
	SortandSearch::CountingSort(massive_ch, size_massive);
	out_massive(massive_ch, size_massive);
	delete[] massive_ch;
	std::cout << std::endl;

	//compare time hardness
	//Quick sort vs Insertion sort
	std::cout << "Quick sort vs Insertion sort" << std::endl;
	std::cout << "\nFirst is Quick sort: " << std::endl;
	for (int amount_elements = 10; amount_elements <= 100000; amount_elements = amount_elements * 10)
	{
		int* massive_qck_srt = new int[amount_elements];
		INT_creating_random_massive(massive_qck_srt, amount_elements);
		double qsrt_timer = 0;//fix the timer
		for (int i = 0; i < 10; i++)//launches
		{
			clock_t begin = clock();
			SortandSearch::QuickSort(massive_qck_srt, amount_elements);
			clock_t end = clock();
			qsrt_timer = qsrt_timer + (end - begin);
		}
		std::cout <<"For these elements "<< amount_elements<< ", time is  " << qsrt_timer/ 10 / CLOCKS_PER_SEC << " (sec)" << std::endl;
		delete[] massive_qck_srt;
	}

	std::cout << "\nSecond is Insertion sort: " << std::endl;
	for (int amount_elements = 10; amount_elements <= 100000; amount_elements = amount_elements * 10)
	{
		int* massive_insert_srt = new int[amount_elements];
		INT_creating_random_massive(massive_insert_srt, amount_elements);
		double inssrt_timer = 0;//fix the timer
		for (int i = 0; i < 10; i++)//launches
		{
			clock_t begin = clock();
			SortandSearch::QuickSort(massive_insert_srt, amount_elements);
			clock_t end = clock();
			inssrt_timer = inssrt_timer + (end - begin);
		}
		std::cout << "For these elements " << amount_elements << ", time is  " << inssrt_timer / 10 / CLOCKS_PER_SEC << " (sec)" << std::endl;
		delete[] massive_insert_srt;
	}

	return 0;
}