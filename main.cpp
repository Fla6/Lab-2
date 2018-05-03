#include "stdafx.h"
#include "Stack.h"
//#include "Queue.h"
//#include "Deque.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	Stack<char> * OperationStack = new Stack<char>;
	Stack<int> * OperandStack = new Stack<int>;
	ifstream file("Input.txt");
	if (!file)
	{
		return 1;
	}
	while (!file.eof())
	{
		char c;
		file >> c;
		switch (c) {
		case 'M':
			OperandStack->Push('M');
			break;
		case 'N':
			OperandStack->Push('N');
			break;
		case '(':
			break;
		case ')':
			c = OperandStack->Pull();
			int op1;
			int op2;
			op1 = OperationStack->Pull();
			op2 = OperationStack->Pull();
			if (c == 'M') 
			{
				op1 = max(op1,op2);
			}
			else if (c == 'N')
			{
				op1 = min(op1, op2);
			}
			OperationStack->Push((op1));
			break;
		default:
			OperationStack->Push((int)c);
			break;
		}
	}
	file.close();
	ofstream outfile("Output.txt");
	outfile << OperationStack->Pull();
	outfile.close();
	delete OperandStack;
	delete OperationStack;
	return 0;
}
