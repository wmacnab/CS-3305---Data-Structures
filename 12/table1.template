/*
 * FILE: table1.template
 * TEMPLATE CLASS IMPLEMENTED: table (see table1.h for documentation)
 * INVARIANT for the table class:
 * 	1. the number of records in the table is in the member variable used.
 * 	2. the actual records of the table are stored in the array data, with a maximum
 * 	   of CAPACITY entries. Each used spot in the array as a non-negative key. Any unused
 * 	   record in the array has a key field of NEVER_USED (if it has never been used) or
 * 	   PREVIOUSLY_USED (if it once was used, but is now vacant).
 */
#include <cassert> // Provides assert
#include <cstdlib> // Provides size_t

namespace wmacnab_12
{
	template <class RecordType>
	const std::size_t table<RecordType>::CAPACITY;

	template <class RecordType>
	const int table<RecordType>::NEVER_USED;

	template <class RecordType>
	const int table<RecordType>::PREVIOUSLY_USED;

	template <class RecordType>
	table<RecordType>::table()
	{
		used = 0;
		for (std::size_t i = 0; i < CAPACITY; ++i)
			data[i].key = NEVER_USED; // Indicates a spot that's never been used.
	}

	template <class RecordType>
	void table<RecordType>::insert(const RecordType& entry)
	{
		bool already_present; // True if entry.key is already in the table
		size_t index; // data[index] is location for the new entry

		assert(entry.key >= 0);

		// Set index so that data[index] is the spot to place the new entry
		find_index(entry.key, already_present, index);

		// If the key wasn't already there, then find the location for the new entry
		if (!already_present)
		{
			assert(size() < CAPACITY);
			index = hash(entry.key);
			while (!is_vacant(index))
				index = next_index(index);
			++used;
		}

		data[index] = entry;
	}

	template <class RecordType>
	void table<RecordType>::remove(int key)
	{
		//
		bool found; // True if the key occurs somewhere in the table
		size_t index; // spot where data[index].key == key

		assert(key >= 0);

		find_index(key, found, index);
		if (found)
		{
			data[index].key = PREVIOUSLY_USED;
			--used;
		}
	}

	template <class RecordType>
	bool table<RecordType>::is_present(int key) const
	// Postcondition: The return value is true if there is a record in the table with
	// the specified key. Otherwise, the return value is false
	{
		for (unsigned int i = 0; i < CAPACITY; ++i)
		{
			if (data[i].key == key) return true;
		}
		return false;
	}

	template <class RecordType>
	void table<RecordType>::find(int key, bool& found, RecordType& result) const
	// Postcondition: If a record is in the table with the specified key, then found is
	// true, and result is set to a copy of the record with that key. Otherwise, found is
	// false, and the result contains garbage.
	{
		if (!is_present(key)) found = false;
		else
		{
			found = true;
			result = data[hash(key)];
		}
	}

	template <class RecordType>
	inline std::size_t table<RecordType>::hash(int key) const
	// Postcondition: The return value is the has value for the given key.
	{
		return (key % CAPACITY);
	}

	template <class RecordType>
	inline std::size_t table<RecordType>::next_index(std::size_t index) const
	// Precondition: index < CAPACITY
	// Postcondition: The return value is either index + 1 (if this is less than CAPACITY)
	// or zero (if index + 1 equals CAPACITY).
	{
		return ((index + 1) % CAPACITY);
	}

	template <class RecordType>
	void table<RecordType>::find_index(int key, bool& found, std::size_t& i) const
	{
		size_t count; // Number of entries that have been examined

		count = 0;
		i = hash(key);
		while((count < CAPACITY) && (!never_used(i)) && (data[i].key != key))
		{
			++count;
			i = next_index(i);
		}
		found = (data[i].key == key);
	}

	template <class RecordType>
	inline bool table<RecordType>::never_used(size_t index) const
	// Self-Test Exercise 14
	// Returns true if data[index] has never been used
	{
		return (data[index] == -1);
	}
	
	template <class RecordType>
	inline bool table<RecordType>::is_vacant(size_t index) const
	// Self-Test Exercise 14
	// Returns true if data[index] is not currently being used
	{
		return (data[index] < 0);
	}
}
