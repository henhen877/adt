#include "stdafx.h"
#include <stack>
#include <iostream>
#include<vector>
#include <string>

using namespace std;

bool isOpen(char symbol);
bool isClosed(char symbol);
bool matches(char symbol, stack<char>& openSymbols);

int main()
{
	//using namespace std; /* Scoping within function */
	vector<char> symbols = { '(',')', '(', ')', '[', '{', '}', ']', '[', '[' };
	bool balanced = true;
	stack<char> openSymbols;
	string test;

	for (auto sym : symbols)
	{
		test += sym;
		if (isOpen(sym))
		{
			openSymbols.push(sym);
		}
		else if (isClosed(sym))
		{
			if (openSymbols.empty())
			{
				balanced = false;
			}
			else
			{
				balanced = matches(sym, openSymbols);
			}
		}
	}

	if (openSymbols.size() > 0)
	{
		balanced = false;
	}

	cout << "X02150, do the symbols " << test << " match?" << endl;
	cout << "X02150: " << balanced << endl;

	return 0;
}

bool isOpen(char symbol)
{
	return ((symbol == '(' || symbol == '{' || symbol == '['));
}

bool isClosed(char symbol)
{
	return ((symbol == ')' || symbol == '}' || symbol == ']'));
}

bool matches(char symbol, stack<char>& openSymbols)
{
	char topSymbol = openSymbols.top();
	openSymbols.pop();
	return (((topSymbol == '(' && symbol == ')') || (topSymbol == '{' && symbol == '}') || (topSymbol == '[' && symbol == ']')));
}
