#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H
#include"StackADT.h"
#include<string>

class InfixCalculator
{
private:
	StackList<char> opStack; // this stack holds operators, + - / * etc
	StackList<int> valStack; // this stacks holds integer values
	string infixExp;  // this holds the infix expression to be evaluated
	int operand1;
	int operand2;
	int result;  // this will hold the final results of the calculation
	char ch;

protected:
	// execute is protected to prevent this function from being called outside of the class
	// execute() is sent an operator in the form of a character, and based on what the character is
	// the function will process two <int>'s from the valStack with the choosen operator
	void execute(char operators)
	{
		if (operators == '*')
		{
			operand2 = valStack.peek();
			valStack.pop();
			operand1 = valStack.peek();
			valStack.pop();
			opStack.pop();
			result = (operand1 * operand2);
			valStack.push(result);
		}
		else if (operators == '/')
		{
			operand2 = valStack.peek();
			valStack.pop();
			operand1 = valStack.peek();
			valStack.pop();
			opStack.pop();
			result = (operand1 / operand2);
			valStack.push(result);
		}
		else if (operators == '+')
		{
			operand2 = valStack.peek();
			valStack.pop();
			operand1 = valStack.peek();
			valStack.pop();
			opStack.pop();
			result = (operand1 + operand2);
			valStack.push(result);
		}
		else if (operators == '-')
		{
			operand2 = valStack.peek();
			valStack.pop();
			operand1 = valStack.peek();
			valStack.pop();
			opStack.pop();
			result = (operand1 - operand2);
			valStack.push(result);
		}
		else
		{
			// do nothing for safety
		}
	}

public:
	InfixCalculator()
	{
	}

	~InfixCalculator()
	{
	}

	// this function gets and sets the infix expression
	void setInfixExpression(string expression)
	{
		infixExp = expression;
	}


	// clifford: this needs documention
	void evaluateExpression()
	{
		for (int count = 0; count < infixExp.size(); count++)
		{
			ch = infixExp[count];

			switch (ch)
			{
			case '1':
			{
				valStack.push(1);
				break;
			}
			case '2':
			{
				valStack.push(2);
				break;
			}
			case '3':
			{
				valStack.push(3);
				break;
			}
			case '4':
			{
				valStack.push(4);
				break;
			}
			case '5':
			{
				valStack.push(5);
				break;
			}
			case '6':
			{
				valStack.push(6);
				break;
			}
			case '7':
			{
				valStack.push(7);
				break;
			}
			case '8':
			{
				valStack.push(8);
				break;
			}
			case '9':
			{
				valStack.push(9);
				break;
			}


			// the number was stacked, now stack the operators starting with '('
			case '(':
			{
				opStack.push('(');
				break;
			}


			// process the multiplication operator by checking for any * or / sitting on the top of the stack
			case '*':
			{
				// if the operator stack is empty, push this operator on to the stack
				if (opStack.isEmpty())
				{
					opStack.push('*');
				}
				
				// there is no else if because multiplication has highest precedence	

				else
				{
					// check the top of the stack for * or /
					// if * or / is on top of the stack, proccess them
					while (!opStack.isEmpty() && (opStack.peek() == '/' || opStack.peek() == '*'))
					{
						if (opStack.peek() == '*')
						{
							execute('*');
						}
						else if (opStack.peek() == '/')
						{
							execute('/');
						}
						else
						{
							// do nothing for safety
						}

					}  // end of while loop

					// if there are no more * or / on top of the stack, push '*' on to the stack
					opStack.push(ch);
				}
				break;
			}  // end of case '*':


			// process the division operator by checking for any * or / sitting on the top of the stack
			case '/':
			{
				// if the operator stack is empty, push this operator on to the stack
				if (opStack.isEmpty())
				{
					opStack.push('/');
				}

				// there is no else if because division has highest precedence	

				// check the top of the stack for * or /
				// if * or / is on top of the stack, proccess them
				else
				{
					while (!opStack.isEmpty() && (opStack.peek() == '*' || opStack.peek() == '/'))
					{
						if (opStack.peek() == '*')
						{
							execute('*');
						}
						else if (opStack.peek() == '/')
						{
							execute('/');
						}
						else
						{
							// do nothing for safety
						}

					}  // end of while loop

					// if there are no more * or / on top of the stack, push '/' on to the stack
					opStack.push(ch);
				}
				break;
			}  // end of case '/':


			// process the addition operator by checking for any *  /  +  - sitting on the top of the stack
			case '+':
			{
				// if the operator stack is empty, push this operator on to the stack
				if (opStack.isEmpty())
				{
					opStack.push(ch);
				}

				// + has higher precendence over (
				else if (opStack.peek() == '(')
				{
					opStack.push(ch);
				}

				// check the top of the stack for *  /  +  - 
				// if *  /  +  -  is on top of the stack, continue to proccess them until the stack is empty or '(' is popped
				// when a '(' is found on top of the stack, push + on top
				else
				{
					while (!opStack.isEmpty() && (opStack.peek() != '('))
					{
						if (opStack.peek() == '*')
						{
							execute('*');
						}
						else if (opStack.peek() == '/')
						{
							execute('/');
						}
						else if (opStack.peek() == '+')
						{
							execute('+');
						}
						else if (opStack.peek() == '-')
						{
							execute('-');
						}
						else
						{
							// do nothing for safety
						}

					}  // end of while loop

					// if there are no more *  /  +  - on top of the stack, push '+' on to the stack
					opStack.push(ch);
				}
				break;
			}  // end of case '+':


			// process the subtraction operator by checking for any *  /  +  - sitting on the top of the stack
			case '-':
			{
				// if the operator stack is empty, push this operator on to the stack
				if (opStack.isEmpty())
				{
					opStack.push(ch);
				}

				// - has higher precendence over (
				else if (opStack.peek() == '(')
				{
					opStack.push(ch);
				}

				// check the top of the stack for *  /  +  - 
				// if *  /  +  - is on top of the stack, continue to proccess them until the stack is empty or '(' is popped
				// when a '(' is found on top of the stack, push - on top
				else
				{
					while (!opStack.isEmpty() && (opStack.peek() != '('))
					{
						if (opStack.peek() == '*')
						{
							execute('*');
						}
						else if (opStack.peek() == '/')
						{
							execute('/');
						}
						else if (opStack.peek() == '+')
						{
							execute('+');
						}
						else if (opStack.peek() == '-')
						{
							execute('-');
						}
						else
						{
							// do nothing for safety
						}

					}  // end of while loop

					// if there are no more *  /  +  - on top of the stack, push '+' on to the stack
					opStack.push(ch);
				}
				break;
			}  // end of case '-':


			// if ')' is found, process all operators until a matching '(' is found
			// when '(' is found, pop that from the stack
			case ')':
			{
				// do not push the ')' on to the stack
				// process all *  /  +  - operators until the closing '(' is found
				while (opStack.peek() != '(')
				{
					if (opStack.peek() == '*')
					{
						execute('*');
					}
					else if (opStack.peek() == '/')
					{
						execute('/');
					}
					else if (opStack.peek() == '+')
					{
						execute('+');
					}
					else if (opStack.peek() == '-')
					{
						execute('-');
					}
					else
					{
						// do nothing for safety
					}

				}

				// when all the operators have been processed, pop '(' from the stack
				opStack.pop();
				break;

			}  // end of case ')':

			default:
			{
				// safety valve here, incase if an un-resolvable character is found
				break;
			}

			}  // end of the switch(ch) test and all characters have been processed from the infixExpression string

		}  // end of the for loop testing each character from the infixExpression string

		
		// now the infix expression has been proccessed into a postfix expression
		// check the operator stack for any operators, if found proccess the operations until the operator stack is empty
		while (!opStack.isEmpty())
		{
			if (opStack.peek() == '*')
			{
				execute('*');
			}
			else if (opStack.peek() == '/')
			{
				execute('/');
			}
			else if (opStack.peek() == '+')
			{
				execute('+');
			}
			else if (opStack.peek() == '-')
			{
				execute('-');
			}
			else
			{
				// do nothing for safety
			}

		}  // the operator stack should be empty and the value stack will contain one number, the final result of the expression

		// all of the operators and operands have been used, update result with the final number
		result = valStack.peek();
	}

	// get the results of the evaluated expression
	int getResults()
	{
		return result;
	}

};

#endif