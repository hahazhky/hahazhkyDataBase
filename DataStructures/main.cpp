#include "DataStructure.h"
#include "ArrayList.cpp"
#include "VectorList.cpp"
#include "Chain.cpp"
#include "AuxiliaryFunction.h"

#include <iostream>

using namespace std;

int main()
{
	arrayList<int> array1(5);
	for (int i = 0; i <= 4; i++)
		array1.insert(i, i*i);
    array1.erase(4);
 	cout << array1<<endl;
	cout << array1.size() << endl;
	cout << array1.get(3) << endl;
	cout << array1.indexOf(1) << endl;
	vectorList<int> vector1(5);
	for (int i = 0; i <= 4; i++)
		vector1.insert(i, i*i*i);
	vectorList<int> vector2(vector1);
 	vector1.erase(3);
	cout << vector1 << endl;
	cout << vector2.size() << endl;
	cout << vector2.get(3) << endl;
	cout << vector2.indexOf(1) << endl;

	chain<int> chain1(5);
	for (int i = 0; i < 5; i++)
	{
		chain1.insert(i, i*i*i*i);
	}
	chain<int> chain2(chain1);
 	chain1.erase(2);
	cout << chain1 << endl;
	cout << chain2 << endl;
	cout << chain1.size() << endl;
	cout << chain1.get(3) << endl;
	cout << chain1.indexOf(1) << endl;
	return 0;
}

