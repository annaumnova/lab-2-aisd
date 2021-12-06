//alhorithms of sort and search
#include <stdio.h>
#include<iostream>
#include<stdexcept>
//BinarySearch
//QuickSort
//InsertionSort
//BogoSort
//CountingSort for char
const int for_char_saving = 256;//for char values

class SortandSearch
{
private:

	static void replacing(int& first, int& second)//to replace elements of our massive
	{
		int temp;
		temp = first;
		first = second;
		second = temp;
	}

public:

	static int BinarySearch(int* massive, size_t size_of_massive, int N_our_number)
	{
		int first = 0; //the index of the first element in our massive (left element)
		int last = size_of_massive - 1; //the index of the last element in our massive (right element)
		while (first < last)
		{
			int temp_middle_index = first + (last - first) / 2; //the index of the temp element in middle
			if (massive[temp_middle_index] == N_our_number)//if it is the found element
				return temp_middle_index;
			else if (massive[temp_middle_index] > N_our_number)//moving search zone to the left
				last = temp_middle_index - 1; 
			else if (massive[temp_middle_index] < N_our_number)//moving search zone to the right
				first = temp_middle_index + 1;
		}
		if (massive[first] == N_our_number)//if it is the first element
			return first;
		else return -1; //if it isn't found
	}

	static void QuickSort(int *massive, size_t size_of_massive)//QuickSort
	{
		if (size_of_massive > 0)
		{
			int first_index = 0;//the index of the first element in our massive
			int last_index = size_of_massive - 1;//the index of the last element in our massive
			int median_pivot_index = massive[(first_index+last_index)/2];//the pivot element (median)
			do
			{
				while (massive[first_index] < median_pivot_index)
					first_index++;
				while (massive[last_index] > median_pivot_index)
					last_index--;
				if (first_index <= last_index) //replacing elements two variants: one is in comment, other is void replacing()
				{
					/*size_of_massive = massive[first_index];
					massive[first_index] = massive[last_index];
					massive[last_index] = size_of_massive;*/
					replacing(massive[first_index], massive[last_index]);
					first_index++;
					last_index--;
				}

			} while (first_index <= last_index);
			
			if (last_index > 0)
				QuickSort(massive, last_index);
			if (size_of_massive > first_index)
				QuickSort(massive + first_index, size_of_massive - first_index);
		}
		else std::cout << "Sorting is impossible" << std::endl;
	}

	static void InsertionSort(int* massive, size_t size_of_massive)//InsertionSort
	{
		if (size_of_massive > 0)
		{
			int index_of_current_element, temp_elem;//the elements of massive
			for (int i = 0; i < size_of_massive - 1; i++)//from first to last
			{
				index_of_current_element = i + 1;//the next
				temp_elem = massive[index_of_current_element];
				for (int j = i + 1; j > 0; j--)
				{
					if (temp_elem < massive[j - 1])
					{
						massive[j] = massive[j - 1];
						index_of_current_element = j - 1;
					}
				}
				massive[index_of_current_element] = temp_elem;
			}
		}
		else std::cout << "Sorting is impossible" << std::endl;
	}

	static void BogoSort(int* massive, size_t size_of_massive)
	{
		if (size_of_massive > 0)
		{
			bool sorting_flag = false;//the flag for not sorted massive
			while (!sorting_flag) 
			{
				for (int i = 0; i < size_of_massive; i++)
					replacing(massive[i], massive[rand() % size_of_massive]);//replace the current element to the random element
				sorting_flag = true;
				for (int i = 0; i  < size_of_massive- 1 && sorting_flag; i++)
					sorting_flag = massive[i] <= massive[i + 1];//if next element is bigger or equivalent than previous then sorting_flag = true
			}
		}
		else std::cout << "Sorting is impossible" << std::endl;
	}

	static void CountingSort(char* massive, size_t size_of_massive)//for char massive
	{
		if (size_of_massive > 0)
		{
			int* counting_index_massive = new int [for_char_saving] {};//the massive with indexes
			for (int i = 0; i < size_of_massive; i++)//forming the massive with indexes
				counting_index_massive[(int)(unsigned char)massive[i]]++;
			for (int i = 0, j = 0; j < for_char_saving; j++)
			{
				for (int n = 0; n < counting_index_massive[j]; n++)
					massive[i++] = (char)(unsigned char)j;
			}
			delete[] counting_index_massive;
		}
		else std::cout << "Sorting is impossible" << std::endl;
	}
};
