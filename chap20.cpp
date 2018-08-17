/*James Hsiao chapter 20 8/13/17
This file contains the menu driven program to demonstrate the IntBinaryTree class
and its various functions. It also includes function for integer input validation*/

#include "stdafx.h"
#include "IntBinaryTree.h"


int displayMenu();
int intVal();
int main()
{
	IntBinaryTree tree;
	int choice = 0;
	int intIn = 0;
	//switch that controls which function to execute based on user inputs.
	while (choice !=6 )
	{
		choice = displayMenu();
		switch (choice)
		{
		case 1:
			intIn = intVal();
			tree.insertNode(intIn);
			break;
		case 2:
			tree.displayInOrder();
			break;
		case 3:
			tree.displayLeafCount();
			break;
		case 4:
			tree.displayTreeHeight();
			break;
		case 5:
			tree.displayTreeWidth();
			break;

		case 6:
			exit(0);
			break;
			//default message diplayed to prompt users to enter valid input option
		default:
			cout << "wrong menu choice\n";
		}
	}
}
//function for menu input
int displayMenu()
{
	int choiceNum = 0;
	cout << "\n1. Insert number\n";
	cout << "2. Display the tree in order\n";
	cout << "3. Display leaf count\n";
	cout << "4. Display tree height\n";
	cout << "5. Display tree width\n";
	cout << "6. Exit\n";
	cout << "Enter your choice:";
	cin >> choiceNum;
	return choiceNum;
}
// function for integer input validation
int intVal()
{
	int input;
	cout << "Please enter an integer:";
	cin >> input;
	while (cin.fail())
	{
		cout << "Input was not an integer. Please try again." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}
	return input;
}
