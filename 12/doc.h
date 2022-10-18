/*
 * File: doc.h
 *
 * Table: a container of records with operations for inserting, deleting, and locating records
 * A table is similar to a bag, but each operation is controlled by a key rather than the entire item value
 * Hash table: when a table is implemented with a hash function
 * RecordType must have a public integer member called key that holds the key for each record
 */

template <class RecordType>
// RecordType must have a public integer member called key that holds the key for each record
// Each key must be a non-negative integer and every key must be distinct
class table
{
public:
	// TYPEDEFS and MEMBER CONSTANT for the table<RecordType> class:
	static const size_t CAPACITY = 811;
	// table<RecordType>::CAPACITY is the maximum number of records held by a table
	
	// CONSTRUCTOR for the table<RecordType> template class:
	table();
	// Postcondition: The table has been initialized as an empty table

	// MODIFICATION MEMBER FUNCTIONS
	void insert(const RecordType& entry);
	// Precondition: entry.key >= 0. Also if entry.key is not already a key in the table,
	// then the table has space for another record (that is, size() < CAPACITY)
	// Postcondition: If the table already had a record with a key equal to entry.key,
	// then that record is replaced by entry.
	// Otherwise entry has been added as a new record of the table
	
	void remove(int key);
	// Postcondition: If a record was in the table with the specified key, then that
	// record has been removed. Otherwise the table is unchanged.
	
	// CONSTANT MEMBER FUNCTIONS
	
	bool is_present(int key) const;
	// Postcondition: The return value is true if the table contains a record with the
	// specified key. Otherwise the return value is false.
	
	void find(int key, bool& found, RecordType& result) const;
	// Postcondition: If the table contains a record with the specified key, then result
	// is a copy of the record with that key, and found is true.
	// Otherwise found is false, and the result contains garbage.
	
	size_t size() const;
	// Postcondition: Return value is the total number of records in the table.
private:
	//
};
