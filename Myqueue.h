#pragma once
#include<iostream>

using namespace std;

//first Õ∑µÿ÷∑ - 1
//last Œ≤µÿ÷∑
template<class E>
class Myqueue
{
public:
	Myqueue(int Max = 100) {
		MaxNum = Max;
		ele = new E[MaxNum];
		first = -1;
		last = -1;
	}
	~Myqueue() {
		delete[] ele;
	}
	bool IsFull() {
		return first%MaxNum == (last + 1)%MaxNum;
	}
	bool IsEmpty() {
		return first == last;
	}
	Myqueue<E>& Enqueue(const E& e) {
		if (IsFull()) {
			cerr << "Overflow!" << endl;
			exit(1);
		}
		if (++last == MaxNum) last = 0;
		ele[last] = e;
		return *this;
	}
	Myqueue<E>& Dequeue(E& e) {
		if (IsEmpty()) {
			cerr << "No member!" << endl;
			exit(1);
		}
		if (++first == MaxNum) first = 0;
		e = ele[first];
		return *this;
	}
	void Output(ostream& cout) {
		if (first > last) last += MaxNum;
		for (int i = first + 1; i < last; i++)
			cout << ele[i%MaxNum] << ",";
		if (!IsEmpty()) cout << ele[last%MaxNum] << endl;
	}
private:
	int MaxNum;
	int first,last;
	E* ele;

};

