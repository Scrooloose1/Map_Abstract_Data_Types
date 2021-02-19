#pragma once

// Structure to store key and value data
template <typename KEY, typename VALUE>
struct SKeyValue
{
	KEY   mKey;
	VALUE mValue;
};

// ----------------------------------------------------------------------
// CLASS	:	CMap
// DESC		:	Template class. Can take in various data types. Map
//              is auto extended (doubled in size) if needed. Various 
//              functions available including Add, Delete and Count, 
//              along with search, return first and last value and clear. 
// ----------------------------------------------------------------------

template <typename KEY, typename VALUE>
class CMap
{
private:
	SKeyValue<KEY, VALUE>* mpData;
	int mSize;
	int mFreeSlot;

	// --------------------------------------------------------------------------------
    // Function Name	:	ExtendArraySize
    // Desc	            :	Creates a new array twice in size and copies the values 
	//                      over. Returns true if successful or false if array is empty
    // --------------------------------------------------------------------------------

	bool ExtendArraySize()
	{
		// Create new array for data
		SKeyValue<KEY, VALUE>* mpNewData; 

		// Set new array size to twice as big using current mSize
		mpNewData = new SKeyValue<KEY, VALUE>[mSize + mSize];

		if (mpNewData == 0) // Is array empty?
		{
			return false;
		}
		else
		{
			// Create array to hold original data to be copied
			SKeyValue<KEY, VALUE>* mpOldData;

			// Set a new pointer to current data (mpData)
			mpOldData = mpData;

			// Copy data
			for (int i = 0; i < mFreeSlot; ++i)
			{
				mpNewData[i] = mpOldData[i];
			}

			// Resize array
			mpData = mpNewData;
			mpNewData = 0;
			delete[] mpOldData;
			mpOldData = 0;
			mSize += mSize;

			return true;
		}
	}

public:

	// --------------------------------------------------------------------------------
    // Function Name	:	CMap (Constructor)
    // Desc	            :	Takes in array size and creates new array. Sets first free
	//                      slot to zero
    // --------------------------------------------------------------------------------

	CMap(const int size)
	{
		mSize = size;
		mpData = new SKeyValue<KEY, VALUE>[size];
		mFreeSlot = 0;
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	CMap (Destructor)
    // Desc	            :	Deletes the array to clear memory
    // --------------------------------------------------------------------------------

	~CMap()
	{
		delete[] mpData;
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	Add
    // Desc	            :	Add new data to the array. Uses ExtendArraySize function
	//                      to extend size if there is not enough space in array.
    // --------------------------------------------------------------------------------

	void Add(KEY key, VALUE value)
	{
		// Check if there is enough space
		if (mFreeSlot < mSize)
		{
			// Check if the key we are going to add does not already exist in the array
			for (int i = 0; i < mFreeSlot; ++i)
			{
				if (key == mpData[i].mKey)
				{
					return; // Exit function
				}
			}

			// Create a new key value data
			SKeyValue<KEY, VALUE> sKeyValue;

			// Assign values
			sKeyValue.mKey = key;
			sKeyValue.mValue = value;

			// Add data to map array
			mpData[mFreeSlot] = sKeyValue;

			// Update next add position in array
			mFreeSlot++;
		}
		else if (mFreeSlot == mSize) // Is the array too small?
		{
			if (ExtendArraySize()) // Call Extend array function
			{
				// Check if the key we are going to add does not already exist in the array
				for (int i = 0; i < mFreeSlot; ++i)
				{
					if (key == mpData[i].mKey)
					{
						return; // Exit function
					}
				}

				// Create a new key value data
				SKeyValue<KEY, VALUE> sKeyValue;

				// Assign values
				sKeyValue.mKey = key;
				sKeyValue.mValue = value;

				// Add data to map array
				mpData[mFreeSlot] = sKeyValue;

				// Update next add position in array
				mFreeSlot++;
			}
		}
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	Count
    // Desc	            :	Returns number of data values in the array (using the next
    //                      free slot value)
    // --------------------------------------------------------------------------------

	int Count()
	{
		return mFreeSlot;
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	Delete
    // Desc	            :	Takes in a key as a paramenter and deletes the key and
    //                      value stored with that key. Checks to see if there is data 
	//                      in the array first, if not will throw an exception and display 
	//                      and error to the user
    // --------------------------------------------------------------------------------

	void Delete(KEY key)
	{
		if (mFreeSlot > 0) // Has to be at least one data entry to delete something
		{
			for (int i = 0; i < mFreeSlot; ++i) // Cycle through array
			{
				if (key == mpData[i].mKey)
				{
					mpData[i] = mpData[mFreeSlot - 1]; // move values down the array
					mpData[mFreeSlot - 1] = SKeyValue<KEY, VALUE>{}; 
					mFreeSlot--; // Reduce next free slot value

					return;
				}
			}

			// Is item not in array? - Exception
			throw std::exception("Unable to delete. Item not found in array");
		}
		else
		{
			// Is the array empty? - Exception
			throw std::exception("Unable to delete. Array position contains no data");
		}
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	Size
    // Desc	            :	Returns the size of the array to the user
	// --------------------------------------------------------------------------------

	int Size()
	{
		return mSize;
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	First
    // Desc	            :	Returns the first value in the array. Throws and exception
	//                      if the array is empty
    // --------------------------------------------------------------------------------

	VALUE First()
	{
		if (mFreeSlot > 0)
		{
			return mpData[0].mValue;
		}
		else
		{
			throw std::exception("Error - Array empty");
		}
		
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	Last
    // Desc	            :	Returns the first last in the array. Throws and exception
    //                      if the array is empty
    // --------------------------------------------------------------------------------

	VALUE Last()
	{
		if (mFreeSlot > 0)
		{
			return mpData[mFreeSlot - 1].mValue;
		}
		else
		{
			throw std::exception("Error - Array empty");
		}

	}

	// --------------------------------------------------------------------------------
    // Function Name	:	Find
    // Desc	            :	Searches through the array for the key sent into the 
	//                      function and if found, returns the value associated with 
	//                      that key. Throws an exception if key can't be found
    // --------------------------------------------------------------------------------

	VALUE Find(KEY key)
	{
		// Search through array
		for (int i = 0; i < mFreeSlot; ++i)
		{
			if (key == mpData[i].mKey) // Is key in the array?
			{
				return mpData[i].mValue; // Return value
			}
		}
		
		// Is key not in array? - Exception
		throw std::exception("Cannot find value for key");

		//return ' '; // If it cant find a key, return empty value;
		// Not sure what to return here?
	}

	// --------------------------------------------------------------------------------
    // Function Name	:	Clear
    // Desc	            :	Delete the array and create a fresh new one. Reset first
	//                      free slot.
    // --------------------------------------------------------------------------------

	void Clear()
	{
		delete[] mpData;
		mpData = new SKeyValue<KEY, VALUE>[mSize];
		mFreeSlot = 0;
	}
};