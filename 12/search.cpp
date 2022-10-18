template <typename Item>
void search(const Item a[], size_t first, size_t size, 
		Item target, bool& found, size_t& location);
// Precondition: The array segment starting at a[first] and containing size elements is
// sorted from smallest to largest.
// Postcondition: The array segment starting at a[first] and containing size elements has
// been searched for the target. If the target was present, then found is true, and location
// is set so that target == a[location].
// Otherwise, found is set to false.


template <typename Item>
void search(const Item a[], size_t first, size_t size, 
		Item target, bool& found, size_t& location)
// Precondition: The array segment starting at a[first] and containing size elements is
// sorted from smallest to largest.
// Postcondition: The array segment starting at a[first] and containing size elements has
// been searched for the target. If the target was present, then found is true, and location
// is set so that target == a[location].
// Otherwise, found is set to false.
// Library facilities used: cstdlib (provides size_t from namespace std)
{
	size_t middle;

	if (size == 0) found = false;
	else
	{
		middle = first + size/2;
		if (target == a[middle])
		{
			location = middle;
			found = true;
		}
		else if (target < a[middle])
			// The target is less than a[middle, so search before the middle
			search(a, first, (size+1)/2, target, found, location);
		else
			// The target must be greater than a[middle], so search after the mid
			search(a, middle+1, (size-1)/2, target, found, location);
	}
}

// My own attempt at an implementation of a serial search from given pseudocode
// Serial search
template <typename Item>
std::size_t serial_search(Item a[], Item target, std::size_t n, std::size_t first)
{
	std::size_t i = 0;
	bool found = false;
	while ((i + first < n) && !found)
	{
		if (a[first + i] == target) found = true;
		else ++i;
	}
	if (found) return first + i;
	else return -1;
}
