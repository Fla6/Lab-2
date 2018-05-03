#include "Element.h"
#include <iostream>

template <typename DataType>
class Queue
{
public:
	Queue();
	~Queue();
	void Push(DataType D);
	DataType Pull();
	void PrintState();
private:
	Element<DataType> * Start;
	Element<DataType> * End;
};

template <typename DataType>
Queue<DataType>::Queue()
{
	Start = nullptr;
	End = nullptr;
}

template <typename DataType>
Queue<DataType>::~Queue()
{
	while (Start != nullptr) {
		PrintState();
		Pull();
	}
	PrintState();
}

template <typename DataType>
void Queue<DataType>::Push(DataType D) {
	Element<DataType> * NewElement = new Element<DataType>(D);
	if (Start == nullptr) {
		Start = NewElement;
	}
	else
	{
		End->Next = NewElement;
	}
	End = NewElement;
}

template <typename DataType>
DataType Queue<DataType>::Pull() {
	if (Start == nullptr) {
		throw "Queue is empty";
	}
	Element<DataType> * NewStart = Start->Next;
	DataType RetunValue = Start->Data;
	delete Start;
	Start = NewStart;
	return RetunValue;
}

template <typename DataType>
void Queue<DataType>::PrintState() {
	if (Start == nullptr) {
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	Element<DataType> * Elem = Start;
	std::cout << "List of elements:" << std::endl;
	do
	{
		std::cout << Elem->Data << " ";
		Elem = Elem->Next;
	} while (Elem != nullptr);
	std::cout << std::endl;
}