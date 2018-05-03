#include "Element.h"
#include <iostream>

template<typename DataType>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(DataType D);
	DataType Pull();
	void PrintState();
private:
	Element<DataType> * End;
};

template<typename DataType>
Stack<DataType>::Stack()
{
	End = nullptr;
}

template<typename DataType>
Stack<DataType>::~Stack()
{
	while (End != nullptr) {
		Pull();
	}
}

template<typename DataType>
void Stack<DataType>::Push(DataType D) {
	Element <DataType>* NewElement = new Element<DataType>(D);
	if (End != nullptr) {
		NewElement->Next = End;
	}
	End = NewElement;
}

template<typename DataType>
DataType Stack<DataType>::Pull() {
	if (End == nullptr) {
		throw "Stack is empty";
	}
	DataType RetunValue = End->Data;
	Element <DataType>* NewEnd = End->Next;
	delete End;
	End = NewEnd;
	return RetunValue;
}

template<typename DataType>
void Stack<DataType>::PrintState() {
	if (End == nullptr) {
		std::cout << "Stack is empty" << std::endl;
		return;
	}
	Element<DataType> * Elem = End;
	std::cout << "List of elements:" << std::endl;
	do
	{
		std::cout << Elem->Data << " ";
		Elem = Elem->Next;
	} while (Elem != nullptr);
	std::cout << std::endl;
}
