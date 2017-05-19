#include <iostream>
#include "DataStructure.h"
#include "AuxiliaryFunction.h"

using namespace std;

template<class T>
vectorList<T>::vectorList(int iniLength)
{
	if (iniLength < 1)
		throw illegalParameterValue("Initial Capacity Must be >0!");
	element = new vector<T>;
	element->reserve(iniLength);
}

template<class T>
vectorList<T>::vectorList(const vectorList<T>& theList) 
{
	element = new vector<T>(*theList.element);//需要的是元素
}

template<class T>
void vectorList<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex > (int)element->size())
		throw illegalParameterValue("The index is not proper!");
}

template<class T>
T& vectorList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
//	return (*element)[theIndex];
	return *(element->begin() + theIndex);//二选一
}

template<class T>
int vectorList<T>::indexOf(const T& theELement) const
{
	int theIndex = (int)(find(element->begin(), element->begin() + size(), theELement) - element->begin());
	if (theIndex == size())
		return -1;
	else return theIndex;
}

template<class T>
void vectorList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	element->erase(begin() + theIndex);
}

template<class T>
void vectorList<T>::insert(int theIndex,const T& theELement)
{
	if (theIndex<0 || theIndex>size())
		throw illegalParameterValue("The index is not proper!");
	element->insert(element->begin() + theIndex, theELement);
}

template<class T>
void vectorList<T>::output(ostream& out) const
{
	copy(element->begin(), element->begin() + size(), ostream_iterator<T>(cout, "  "));
}

template<class T>
ostream& operator<<(ostream& out, const vectorList<T>& x)
{
	x.output(out); return out;
}