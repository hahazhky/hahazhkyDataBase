#include <iostream>
#include "DataStructure.h"
#include "AuxiliaryFunction.h"

using namespace std;

template<class T>
arrayList<T>::arrayList(int iniLength)
{
	if (iniLength < 1)
		throw illegalParameterValue("Initial Capacity Must be >0!");
	arrayLength = iniLength;
	element = new T[arrayLength];
	listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	this->arrayLength = theList.arrayLength;
	this->listSize = theList.listSize;
	this->element = new T[arrayLength];
	copy(theList.element,theList.element+listSize,element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{//检查索引值是否符合要求
	if (theIndex < 0 || theIndex >= listSize)
		throw illegalParameterValue("The index is not proper!");
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{//找到返回索引值，否则返回-1
	int theIndex=(int)(find(element, element + listSize, theElement) - element);
	if (theIndex == -1)
		return -1;
	else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{//
	checkIndex(theIndex);
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();//调用析构函数
}

template<class T>
void arrayList<T>::insert(const int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
		throw illegalParameterValue("The index is not proper!");
	if (listSize == arrayLength)//不够加容量
	{
		changeLength1D(element, arrayLength, arrayLength * 2);
		arrayLength *= 2;
	}

	copy_backward(element + theIndex, element + listSize, element + listSize + 1);//元素右移

	element[theIndex] = theElement;
	listSize++;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{
	copy(element,element+listSize,ostream_iterator<T>(cout,"  "));
}

template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
	x.output(out); return out;
}