#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <iostream>
#include <vector>

using namespace std;

#pragma region ���Ա����������
template<class T>
class arrayList
{
	friend ostream& operator<< <T>(ostream& out, const arrayList<T>&);//����ʹ<<��������û��Զ�������

public:
	arrayList(int iniLength=10);//���캯��
	arrayList(const arrayList<T>&);//���ƹ��캯��
	~arrayList(){ delete[] element; }//��������

	bool empty() const { return listSize == 0; }//const���ں�����ǰ
	int size() const{ return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(const int theIndex, const T& theElement);
	void output(ostream& out) const;

	int capacity() const{ return arrayLength; }//��ǰ���鳤��

protected:
	void checkIndex(int theIndex) const;//��������Ч�����׳��쳣
	T* element;//�洢���Ա�Ԫ�ص�һά����(�����캯��)
	int arrayLength;//���鳤��
	int listSize;//���Ա�Ԫ�ظ���
};
#pragma endregion 

#pragma region vectorʵ�����Ա����������
template<class T>
class vectorList
{
	friend ostream& operator<< <T>(ostream& out, const arrayList<T>&);

public:
	vectorList(int iniLength = 10);//���캯��
	vectorList(const vectorList<T>&);//���ƹ��캯��
	~vectorList(){ delete element; }//��������

	bool empty() const{ return element->empty(); }
	int size() const{ return element->size(); }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(const int theIndex, const T& theElement);
	void output(ostream& out) const;

	int capacity() const{ return element->capacity(); }

 	typedef typename vector<T>::iterator iterator;
 	iterator begin() { return element->begin(); }//ΪʲôҪ����
	iterator end() { return element->end(); }  

protected:
	void checkIndex(int theIndex) const;
	vector<T>* element;

};

#pragma endregion

#pragma region ���Ա����ʽ����(��������)
template<class T>
struct chainNode//����ڵ�Ľṹ����
{
	//���ݳ�Ա
	T element;
	chainNode *next;

	//����
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
