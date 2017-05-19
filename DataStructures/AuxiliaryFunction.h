#ifndef AUXILIARYFUNCTION_H
#define AUXILIARYFUNCTION_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
//自定义异常类
class illegalParameterValue
{
public:
	illegalParameterValue() :message("Illegal Parameter Value"){}
	illegalParameterValue(char* theMessage)
	{ message = theMessage; }
	void output(){ cout << message << endl; }
private:
	string message;
};

//改变一维数组长度
template<class T>
void changeLength1D(T*&a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("New Length Must be >0!");
	T* temp = new T[newLength];
	int number = min(oldLength,newLength);
	copy(a, a + number, temp);
	delete [] a;
	a = temp;
}

#endif