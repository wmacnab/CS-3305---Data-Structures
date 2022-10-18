/*
 * File: main.cpp
 * Description: a test program for my exercises from 'Chapter 12 - Searching' from the book 'Data Structures and Other Objects with C++'
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "search.cpp"

void t2()
// Uses <algorithm> for operations to find elements in sorted and unsorted ranges.
// [first...last)
{
	// bool binary_search(Iterator first, Iterator last, const Item& target);
	// Iterator lower_bound(Iterator first, Iterator last, const Item& target);
	// Iterator upper_bound(Iterator first, Iterator last, const Item& target);
	// lower_bound: leftmost spot in the sequence before which the target can be inserted with the numbers still staying in order
	// upper_bound: rightmost spot in the sequence before which the target can be inserted with the numbers staying in order
	// lower_bound and upper_bound use binary search. Only return same iterator when target is not in the range
	//
	std::vector<std::string> pets;
	pets.push_back("cat");
	pets.push_back("dog");
	pets.push_back("dog");
	pets.push_back("fish");
	pets.push_back("snake");
	pets.push_back("turtle");

	// first occurrence of "dog"
	std::vector<std::string>::iterator first_dog = lower_bound(pets.begin(), pets.end(), "dog");

	// "fish
	std::vector<std::string>::iterator after_dog = upper_bound(pets.begin(), pets.end(), "dog");
	std::cout << *first_dog << *after_dog << std::endl;
	
}

void t1()
{
	std::cout << "Beginning test program." << std::endl;

	size_t location = 99;
	bool found = true;
	std::string s[] = { "aaa", "bbbb", "ccc", "eeee", "ffff", "g" };
	search(s, 0, 6, std::string("ffff"), found, location);
	std::cout << "Location is " << location << " and found is " << found << ".\n";
	
	bool idk = s[0] == std::string("ffff");
	std::cout << idk << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		std::cout << sizeof(s[i]) << "\t";
	}

	std::cout << "Exiting test program." << std::endl;
}

int main()
{
	t2();
	return EXIT_SUCCESS;
}
