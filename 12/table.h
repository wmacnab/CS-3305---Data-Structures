#include <vector>

namespace wmacnab_12_2
{
	template <class RecordType, size_t TABLE_SIZE, int hashkey(const RecordType&>
	class table
	{
	public:
		// CONSTRUCTORS (no destructor needed, uses automatic copy constructor)
		table();
		// MODIFICATION MEMBER FUNCTIONS
		void insert(const RecordType& entry);
		void remove(int key);
		// CONSTANT MEMBER FUNCTIONS
		void find(int key, bool& found, RecordType& result) const;
		bool is_present(int key) const;
		size_t size() const { return total_records; }
	private:
		vector<RecordType> data[TABLE_SIZE];
		size_t total_records;
		// HELPER MEMBER FUNCTION
		size_t hash(int key) const;
	};
}
