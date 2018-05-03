#include "DoubleElement.h"
#include <iostream>

template <typename DataType>
class Deque
{
public:
	Deque();
	~Deque();
	void PushLeft(DataType D);
	void PushRight(DataType D);
	DataType PullLeft();
	DataType PullRight();
	void PrintStateLeft();
	void PrintStateRight();
private:
	DoubleElement<DataType> * Left;
	DoubleElement<DataType> * Right;
};

template <typename DataType>
Deque<DataType>::Deque()
{
	Left = nullptr;
	Right = nullptr;
}

template <typename DataType>
Deque<DataType>::~Deque()
{
	while (Left != nullptr) {
		PullLeft();
	}
}

template <typename DataType>
void Deque<DataType>::PushLeft(DataType D)
{
	DoubleElement<DataType> * NewElement = new DoubleElement<DataType>(D);
	if (Left != nullptr) {
		Left->Left = NewElement;
		NewElement->Right = Left;
	}
	else
	{
		Right = NewElement;
	}
	Left = NewElement;
}

template <typename DataType>
void Deque<DataType>::PushRight(DataType D)
{
	DoubleElement<DataType> * NewElement = new DoubleElement<DataType>(D);
	if (Right != nullptr) {
		Right->Right = NewElement;
		NewElement->Left = Right;
	}
	else
	{
		Left = NewElement;
	}
	Right = NewElement;
}

template <typename DataType>
DataType Deque<DataType>::PullLeft() {
	if (Left == nullptr) {
		throw "Deque is empty";
	}
	DoubleElement<DataType> * NewLeft = Left->Right;
	DataType RetunValue = Left->Data;
	delete Left;
	Left = NewLeft;
	if (Left != nullptr) {
		Left->Left = nullptr;
	}
	else {
		Right = nullptr;
	}
	return RetunValue;
}

template <typename DataType>
DataType Deque<DataType>::PullRight() {
	if (Right == nullptr) {
		throw "Deque is empty";
	}
	DoubleElement<DataType> * NewRight = Right->Left;
	DataType RetunValue = Right->Data;
	delete Right;
	Right = NewRight;
	if (Right != nullptr) {
		Right->Right = nullptr;
	}
	else {
		Left = nullptr;
	}
	return RetunValue;
}

template <typename DataType>
void Deque<DataType>::PrintStateLeft() {
	if (Left == nullptr) {
		std::cout << "Deque is empty" << std::endl;
		return;
	}
	DoubleElement<DataType> * Elem = Left;
	std::cout << "List of elements left to right:" << std::endl;
	do
	{
		std::cout << Elem->Data << " ";
		Elem = Elem->Right;
	} while (Elem != nullptr);
	std::cout << std::endl;

}

template <typename DataType>
void Deque<DataType>::PrintStateRight() {
	if (Right == nullptr) {
		std::cout << "Deque is empty" << std::endl;
		return;
	}
	DoubleElement<DataType> * Elem = Right;
	std::cout << "List of elements right to left:" << std::endl;
	do
	{
		std::cout << Elem->Data << " ";
		Elem = Elem->Left;
	} while (Elem != nullptr);
	std::cout << std::endl;

}