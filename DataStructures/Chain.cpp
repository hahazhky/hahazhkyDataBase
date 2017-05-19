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
		sourceNode = targetNode->next;
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