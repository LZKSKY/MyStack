#pragma once
#include<iostream>

using namespace std;

template<class E>
class MyStack
{
public:
	MyStack(int Max = 100) {
		MaxNum = Max;
		ele = new E[MaxNum];
		top = -1;
	}
	~MyStack() {
		delete[] ele;
	}
	E* Top() {
		return ele[top];
	}
	bool IsEmpty() {
		return top == -1;
	}
	bool IsFull() {
		return top == MaxNum - 1;
	}
	MyStack<E>& Push(const E& e) {
		if (IsFull()) {
			cerr << "Overflow!" << endl;
			exit(1);
		}
		ele[++top] = e;
		return *this;
	}
	MyStack<E>& Pop(E& e) {
		if (IsEmpty()) {
			cerr << "No member!" << endl;
			exit(1);
		}
		e = ele[top--];
		return *this;
	}
	void Output(ostream& cout) {
		for (int i = 0; i < top; i++)
			cout << ele[i] << ",";
		if (top != -1)
			cout << ele[top] << endl;
	}
private:
	int MaxNum;
	int top;
	E* ele;
};

