/*
 * File: table1.h
 * TEMPLATE CLASS PROVIDED: table<RecordType> (a table of records with keys)
 * 	This class is a container template class for a table of records. The template parameter, RecordType, is the data type of the records in the table. It may be any of the built-in C++ types (int, char, ect.), or a class with a default constructor, an assignment operator, and an integer member variable called key.
 *
 * VALUE SEMANTICS for the table<RecordType> template class:
 * 	Assignments and the copy constructor may be used with table<RecordType> objects.
 */

#ifndef _WMACNAB_TABLE_H_
#define _WMACNAB_TABLE_H_
//#include <cstdlib> // Provides size_t

namespace wmacnab_12
{
	template <class RecordType>
	class table
	{
		public:
			// MEMBER CONSTANT
			static const std::size_t CAPACITY = 811; // prime of form 4k + 3
			// CONSTRUCTOR
			table();
			// MODIFICATION MEMBER FUNCTIONS
			void insert(const RecordType& entry);
			void remove(int key);
			// CONSTANT MEMBER FUNCTIONS
			bool is_present(int key) const;
			void find(int key, bool& found, RecordType& result) const;
			std::size_t size() const { return used; }
		private:
			// MEMBER CONSTANTS-These are used in the key field of special records
			static const int NEVER_USED = -1;
			static const int PREVIOUSLY_USED = -2;
			// MEMBER VARIABLES
			RecordType data[CAPACITY];
			std::size_t used;
			// HELPER FUNCTIONS
			std::size_t hash(int key) const;
			std::size_t next_index(std::size_t index) const;
			void find_index(int key, bool& found, std::size_t& index) const;
			bool never_used(std::size_t index) const;
			bool is_vacant(std::size_t index) const;
	};
}

#include "table1.template" // Include the implementation
#endif

