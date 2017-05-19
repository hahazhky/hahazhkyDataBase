#include <iostream>
#include "DataStructure.h"
#include "AuxiliaryFunction.h"

using namespace std;

template<class T>
chain<T>::chain(int iniLength)
{
	if (iniLength < 1)
		throw illegalParameterValue("Initial Capacity Must be >0!");
	firstNode = NULL;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theChain)//´ý¶¨
{
	listSize = theChain.listSize;
	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}
	chainNode<T>* sourceNode = theChain.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}

template<class T>
chain<T>::~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);

	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{
	int theIndex = 0;
	chainNode<T>* currentNode = firstNode;
	while (currentNode->next!=NULL && currentNode->element!=theElement)
	{
		currentNode = currentNode->next;
		theIndex++;
	}
	if (currentNode == NULL)
		theIndex = -1;
	return theIndex;
}

template<class T>
void chain<T>::erase(int theIndex)
{
 	checkIndex(theIndex);

	chainNode<T>* deleteNode;
	if (theIndex==0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p=firstNode;
		for (int i = 0; i < theIndex-1; i++)
		{
			p = p->next;
		}

		deleteNode = p->next;
		p->next = p->next->next;
		/*chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex ; i++)
		{
			p = p->next;
		}

		deleteNode = p;
		p = p->next;*/
	}
	listSize--;
	delete deleteNode;
}

template<class T>
void chain<T>::insert(const int theIndex, const T& theElement)
{
	if (theIndex<0||theIndex>listSize)
	{
		throw illegalParameterValue("The index is not proper!");
	}
	if (theIndex == 0)
	{
		firstNode = new chainNode<T>(theElement,firstNode);
	}
	else
	{
		chainNode<T>* currentNode = firstNode;
		for (int i = 0; i < theIndex-1; i++)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = new chainNode<T>(theElement, currentNode->next);
	}
	listSize++;
}

template<class T>
void chain<T>::output(ostream& out) const
{
	for (chainNode<T>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
	{
		out << currentNode->element << " ";
	}
}

template<class T>
ostream& operator<< (ostream& out, const chain<T>& x)
{
	x.output(out);
	return out;
}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{
	if (theIndex<0 || theIndex>=listSize)
	{
		throw illegalParameterValue("The index is not proper!");
	}
}
