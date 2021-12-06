#include "pch.h"
#include "CppUnitTest.h"
#include "../כנ¹2 אטסה/sortsearch.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int mass_size_one = 3;
const int mass_size_two = 9;
const int mass_size_three = 5;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Test_BogoSort)
		{
			int* mass_bogo = new int[mass_size_one] {4, 3, 1};
			SortandSearch::BogoSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 1 && mass_bogo[1] == 3 && mass_bogo[2] == 4);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {4, 3, 1, 0, 6, 5, 2, 1, 8};
			SortandSearch::BogoSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 0 && mass_bogo[1] == 1 && mass_bogo[2] == 1 && mass_bogo[3] == 2 && mass_bogo[4] == 3 && mass_bogo[5] == 4
				&& mass_bogo[6] == 5 && mass_bogo[7] == 6
				&& mass_bogo[8] == 8);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {4, 3, 1, 0, 6};
			SortandSearch::BogoSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 0 && mass_bogo[1] == 1 && mass_bogo[2] == 3 && mass_bogo[3] == 4 && mass_bogo[4] == 6);
			delete[] mass_bogo;
		}
		TEST_METHOD(Test_QuickSort)
		{
			int* mass_bogo = new int[mass_size_one] {4, 3, 1};
			SortandSearch::QuickSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 1 && mass_bogo[1] == 3 && mass_bogo[2] == 4);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {4, 3, 1, 0, 6, 5, 2, 1, 8};
			SortandSearch::QuickSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 0 && mass_bogo[1] == 1 && mass_bogo[2] == 1 && mass_bogo[3] == 2 && mass_bogo[4] == 3 && mass_bogo[5] == 4
				&& mass_bogo[6] == 5 && mass_bogo[7] == 6
				&& mass_bogo[8] == 8);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {4, 3, 1, 0, 6};
			SortandSearch::QuickSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 0 && mass_bogo[1] == 1 && mass_bogo[2] == 3 && mass_bogo[3] == 4 && mass_bogo[4] == 6);
			delete[] mass_bogo;
		}
		TEST_METHOD(Test_InsertionSort)
		{
			int* mass_bogo = new int[mass_size_one] {4, 3, 1};
			SortandSearch::InsertionSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 1 && mass_bogo[1] == 3 && mass_bogo[2] == 4);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {4, 3, 1, 0, 6, 5, 2, 1, 8};
			SortandSearch::InsertionSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 0 && mass_bogo[1] == 1 && mass_bogo[2] == 1 && mass_bogo[3] == 2 && mass_bogo[4] == 3 && mass_bogo[5] == 4
				&& mass_bogo[6] == 5 && mass_bogo[7] == 6
				&& mass_bogo[8] == 8);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {4, 3, 1, 0, 6};
			SortandSearch::InsertionSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == 0 && mass_bogo[1] == 1 && mass_bogo[2] == 3 && mass_bogo[3] == 4 && mass_bogo[4] == 6);
			delete[] mass_bogo;
		}
		TEST_METHOD(Test_BinarySort)
		{
			int* mass_bogo = new int[mass_size_one] {1, 3, 4};
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_one, 1) == 0);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_one, 3) == 1);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_one, 4) == 2);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 7) == -1);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {0, 1, 1, 2, 3, 4, 5, 6, 8};
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 0) == 0);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 1) == 1 ||
				SortandSearch::BinarySearch(mass_bogo, mass_size_two, 1) == 2);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 2) == 3);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 3) == 4);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 4) == 5);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 5) == 6);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 6) == 7);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_two, 8) == 8);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 7) == -1);
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_three] {0, 1, 3, 4, 6};
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 0) == 0);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 1) == 1);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 3) == 2);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 4) == 3);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 6) == 4);
			Assert::IsTrue(SortandSearch::BinarySearch(mass_bogo, mass_size_three, 7) == -1);
			delete[] mass_bogo;
		}
		TEST_METHOD(Test_CountingSort)
		{
			char* mass_bogo = new char[mass_size_one] {'4', '3', '1'};
			SortandSearch::CountingSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == '1' && mass_bogo[1] == '3' && mass_bogo[2] == '4');
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {'4', '3', '1', '0', '6', '5', '2', '1', '8'};
			SortandSearch::CountingSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == '0' && mass_bogo[1] == '1' && mass_bogo[2] == '1' && mass_bogo[3] == '2' && mass_bogo[4] == '3' 
				&& mass_bogo[5] == '4' && mass_bogo[6] == '5' && mass_bogo[7] == '6' && mass_bogo[8] == '8');
			delete[] mass_bogo;

			int* mass_bogo = new int[mass_size_two] {'4', '3', '1', '0', '6'};
			SortandSearch::CountingSort(mass_bogo, mass_size_one);
			Assert::IsTrue(mass_bogo[0] == '0' && mass_bogo[1] == '1' && mass_bogo[2] == '3' && mass_bogo[3] == '4' && mass_bogo[4] == '6');
			delete[] mass_bogo;
		}
	};
}
