template <typename DataType>
class Element
{
public:
	Element(DataType D);
	DataType Data;
	Element<DataType> * Next;
};

template <typename DataType>
Element<DataType>::Element(DataType D)
{
	Data = D;
	Next = nullptr;
} 
/*
template <typename DataType>
class Element {
public:
	DataType data;
	Element<DataType>* Next;
	Element(DataType data):data(value),next(nullptr)
	{}
};
*/