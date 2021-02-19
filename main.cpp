// CO3402: Object-Oriented Methods in Computing (2019/20)
// Assignment: Implementing a map class
// Last Edited: 13-12-19

#include <iostream>
#include <istream>
#include "CMap.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::boolalpha;


// Main Function
int main()
{
	cout << "\n\n CO3402: Object-Oriented Methods in Computing";
	cout << "\n Test Program started:\n\n";

	// **************************************************************************
	// TEST 1 - INTEGER AND CHAR
	// **************************************************************************

	CMap<int, char>   myIntCharMap   (5);
	myIntCharMap.Add(1, 'A');
	myIntCharMap.Add(2, 'B');
	myIntCharMap.Add(3, 'C');
	myIntCharMap.Add(4, 'D');
	myIntCharMap.Add(5, 'E');
	myIntCharMap.Add(6, 'F');

	cout << " First:               " << myIntCharMap.First() << "\n";
    cout << " Last:                " << myIntCharMap.Last()  << "\n";
	cout << " Search for key '3' : " << myIntCharMap.Find(3) << "\n";
	cout << " Number of items:     " << myIntCharMap.Count() << "\n";
	cout << " Array Size:          " << myIntCharMap.Size()  << "\n";
	cout << " Deleting key '3'..\n";
	myIntCharMap.Delete(3);
    cout << " Number of items:     " << myIntCharMap.Count() << "\n";
	cout << " Clearing array..\n";
	myIntCharMap.Clear();
	cout << " Number of items:     " << myIntCharMap.Count() << "\n\n\n";


	// **************************************************************************
	// TEST 2 - INT AND INT
	// **************************************************************************

	CMap<int, int>   myIntIntMap(5);
	
	myIntIntMap.Add(1, 100);
	myIntIntMap.Add(2, 200);
	myIntIntMap.Add(3, 300);
	myIntIntMap.Add(4, 400);
	myIntIntMap.Add(5, 500);
	myIntIntMap.Add(6, 600);

	cout << " First:               " << myIntIntMap.First() << "\n";
	cout << " Last:                " << myIntIntMap.Last()  << "\n";
	cout << " Search for key '3' : " << myIntIntMap.Find(3) << "\n";
	cout << " Number of items:     " << myIntIntMap.Count() << "\n";
	cout << " Array Size:          " << myIntIntMap.Size()  << "\n";
	cout << " Deleting key '3'..\n";
	myIntIntMap.Delete(3);
	cout << " Number of items:     " << myIntIntMap.Count() << "\n";
	cout << " Clearing array..\n";
	myIntIntMap.Clear();
	cout << " Number of items:     " << myIntIntMap.Count() << "\n\n\n";

	// **************************************************************************
	// TEST 3 - INT AND FLOAT
	// **************************************************************************

	CMap<int, float> myIntfloatMap(5);
	
	myIntfloatMap.Add(1, 1.9999f);
	myIntfloatMap.Add(2, 2.9999f);
	myIntfloatMap.Add(3, 3.9999f);
	myIntfloatMap.Add(4, 4.9999f);
	myIntfloatMap.Add(5, 5.9999f);
	myIntfloatMap.Add(6, 6.9999f);

	cout << " First:               " << myIntfloatMap.First() << "\n";
	cout << " Last:                " << myIntfloatMap.Last()  << "\n";
	cout << " Search for key '3' : " << myIntfloatMap.Find(3) << "\n";
	cout << " Number of items:     " << myIntfloatMap.Count() << "\n";
	cout << " Array Size:          " << myIntfloatMap.Size()  << "\n";
	cout << " Deleting key '3'..\n";
	myIntfloatMap.Delete(3);
	cout << " Number of items:     " << myIntfloatMap.Count() << "\n";
	cout << " Clearing array..\n";
	myIntfloatMap.Clear();
	cout << " Number of items:     " << myIntfloatMap.Count() << "\n\n\n";

	// **************************************************************************
	// TEST 4 - FLOAT AND DOUBLE
	// **************************************************************************

	CMap<float, double> myFloatDoubleMap(5);
	
	myFloatDoubleMap.Add(1.0f, 1.9999);
	myFloatDoubleMap.Add(2.0f, 2.9999);
	myFloatDoubleMap.Add(3.0f, 3.9999);
	myFloatDoubleMap.Add(4.0f, 4.9999);
	myFloatDoubleMap.Add(5.0f, 5.9999);
	myFloatDoubleMap.Add(6.0f, 6.9999);
	
	cout << " First:                  " << myFloatDoubleMap.First()    << "\n";
	cout << " Last:                   " << myFloatDoubleMap.Last()     << "\n";
	cout << " Search for key '3.0f' : " << myFloatDoubleMap.Find(3.0f) << "\n";
	cout << " Number of items:        " << myFloatDoubleMap.Count()    << "\n";
	cout << " Array Size:             " << myFloatDoubleMap.Size()     << "\n";
	cout << " Deleting key '3.0f'..\n";
	myFloatDoubleMap.Delete(3.0f);
	cout << " Number of items:        " << myFloatDoubleMap.Count()    << "\n";
	cout << " Clearing array..\n";
	myFloatDoubleMap.Clear();
	cout << " Number of items:        " << myFloatDoubleMap.Count()    << "\n\n\n";

	// **************************************************************************
	// TEST 5 - CHAR AND STRING
	// **************************************************************************

	CMap<char, string> myCharStringMap(5);
	
	myCharStringMap.Add('A', "Apple");
	myCharStringMap.Add('B', "Banana");
	myCharStringMap.Add('C', "Cherry");
	myCharStringMap.Add('D', "Date");
	myCharStringMap.Add('E', "Elderberry");
	myCharStringMap.Add('F', "Fig");
	
	cout << " First:               " << myCharStringMap.First()   << "\n";
	cout << " Last:                " << myCharStringMap.Last()    << "\n";
	cout << " Search for key 'C' : " << myCharStringMap.Find('C') << "\n";
	cout << " Number of items:     " << myCharStringMap.Count()   << "\n";
	cout << " Array Size:          " << myCharStringMap.Size()    << "\n";
	cout << " Deleting key 'C'..\n";
	myCharStringMap.Delete('C');
	cout << " Number of items:     " << myCharStringMap.Count()   << "\n";
	cout << " Clearing array..\n";
	myCharStringMap.Clear();
	cout << " Number of items:     " << myCharStringMap.Count()   << "\n\n\n";

	// **************************************************************************
	// TEST 5 - CHAR AND BOOL
	// **************************************************************************

	CMap<char, bool> myCharBoolMap(5);
	
	myCharBoolMap.Add('A', true);
	myCharBoolMap.Add('B', false);
	myCharBoolMap.Add('C', true);
	myCharBoolMap.Add('D', false);
	myCharBoolMap.Add('E', true);
	myCharBoolMap.Add('F', false);
	
	cout << " First:                  " << boolalpha << myCharBoolMap.First()   << "\n";
	cout << " Last:                   " << myCharBoolMap.Last()    << "\n";
	cout << " Search for key '3.0f' : " << myCharBoolMap.Find('C') << "\n";
	cout << " Number of items:        " << myCharBoolMap.Count()   << "\n";
	cout << " Array Size:             " << myCharBoolMap.Size()    << "\n";
	cout << " Deleting key 'C'..\n";
	myCharBoolMap.Delete('C');
	cout << " Number of items:        " << myCharBoolMap.Count()   << "\n";
	cout << " Clearing array..\n";
	myCharBoolMap.Clear();
	cout << " Number of items:        " << myCharBoolMap.Count()   << "\n";


	// Test Exceptions
	try
	{
		myIntCharMap.Delete(2);
	}
	catch(std::exception e)
	{
		cout << "\n Testing Exceptions:\n " << e.what();
	}


	std::cout << "\n Program finished.\n";
	std::cout << " Press Enter to quit...";
	cin.get();
	return 0;

} // End of main Function

