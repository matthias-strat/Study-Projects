#include <iostream>
#include <chrono>

int main()
{
	// Simple bubble-sort algorithm implementation, just testing stuff!
	
	int num;
	std::cout << "number of items: ";
	std::cin >> num;

	// number of items between 1 and 1000? 
	if (num < 1 || num > 1000) return -1;

	// let the user input all items
	auto numbers{ new float[num] };
	for (auto i{ 0 }; i < num; i++)
	{
		std::cout << i + 1 << ". number: ";
		std::cin >> numbers[i];
	}

	// now sort
	auto tpStart{ std::chrono::high_resolution_clock::now() };
	for (auto i{ 0 }; i < num - 1; i++)
	{
		for (auto j{ 0 }; j < num - i - 1; j++)
		{
			if (numbers[j] > numbers[j + 1]) std::swap(numbers[j], numbers[j + 1]);
		}
	}
	auto tpEnd{ std::chrono::high_resolution_clock::now() };

	// output result
	std::cout << "sorted numbers:" << std::endl;
	for (auto i{ 0 }; i < num; i++) std::cout << numbers[i] << std::endl;

	auto elapsed{ std::chrono::duration_cast<std::chrono::nanoseconds>(tpEnd - tpStart) };
	std::cout << "sorting took " << elapsed.count() << " ns" << std::endl;

	delete[] numbers;
	return 0;
}