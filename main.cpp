#include<iostream>
#include<string>
#include"InfixCalculator.h"

using namespace std;

int main()
{
	int results;
	InfixCalculator infixCalculator;

	infixCalculator.setInfixExpression("(2+5)+6");
	cout << "calculating: ' (2 + 5) + 6 '" << endl;
	infixCalculator.evaluateExpression();
	cout << "the result is: " << infixCalculator.getResults() << endl;

	cout << endl;
	cout << "press <Enter> to exit the program...";
	cin.get();
	return 0;
}