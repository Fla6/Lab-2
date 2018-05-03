template <typename DataType>
class DoubleElement
{
public:
	DoubleElement(DataType D);
	DataType Data;
	DoubleElement<DataType> * Left;
	DoubleElement<DataType> * Right;
private:
};

template <typename DataType>
DoubleElement<DataType>::DoubleElement(DataType D)
{
	Data = D;
	Left = nullptr;
	Right = nullptr;
}
