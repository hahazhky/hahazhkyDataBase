#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <iostream>
#include <vector>

using namespace std;

#pragma region 线性表的数组描述
template<class T>
class arrayList
{
	friend ostream& operator<< <T>(ostream& out, const arrayList<T>&);//重载使<<可以输出用户自定义类型

public:
	arrayList(int iniLength=10);//构造函数
	arrayList(const arrayList<T>&);//复制构造函数
	~arrayList(){ delete[] element; }//析构函数

	bool empty() const { return listSize == 0; }//const放在函数体前
	int size() const{ return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(const int theIndex, const T& theElement);
	void output(ostream& out) const;

	int capacity() const{ return arrayLength; }//当前数组长度

protected:
	void checkIndex(int theIndex) const;//若索引无效，则抛出异常
	T* element;//存储线性表元素的一维数组(见构造函数)
	int arrayLength;//数组长度
	int listSize;//线性表元素个数
};
#pragma endregion 

#pragma region vector实现线性表的数组描述
template<class T>
class vectorList
{
	friend ostream& operator<< <T>(ostream& out, const arrayList<T>&);

public:
	vectorList(int iniLength = 10);//构造函数
	vectorList(const vectorList<T>&);//复制构造函数
	~vectorList(){ delete element; }//析构函数

	bool empty() const{ return element->empty(); }
	int size() const{ return element->size(); }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(const int theIndex, const T& theElement);
	void output(ostream& out) const;

	int capacity() const{ return element->capacity(); }

 	typedef typename vector<T>::iterator iterator;
 	iterator begin() { return element->begin(); }//为什么要定义
	iterator end() { return element->end(); }  

protected:
	void checkIndex(int theIndex) const;
	vector<T>* element;

};

#pragma endregion

#pragma region 线性表的链式描述(单向链表)
template<class T>
struct chainNode//链表节点的结构定义
{
	//数据成员
	T element;
	chainNode *next;

	//方法
	chainNode(){};
	chainNode(const T& Element){ element = Element; }
	chainNode(const T& Element, chainNode<T>* Next) { element = Element; next = Next; }
};

template<class T>
class chain
{
	friend ostream& operator<< <T>(ostream& out, const chain<T>&);
public:
	chain(int iniLength=10);
	chain(const chain<T>&);
	~chain();

	bool empty() const { return listSize == 0; }
	int size() const{ return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(const int theIndex, const T& theElement);
	void output(ostream& out) const;

private:
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;
	int listSize;
};

#pragma endregion

#endif
