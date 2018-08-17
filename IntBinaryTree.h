/*chapter 20 James Hsiao 8/13/17
This is the header file for the binary tree. This file includes the 
code for the operations to find the number of leaf nodes, tree height, and 
tree width. It also includes the functions that call those operations and 
display the results.*/

#pragma once
// Specification file for the IntBinaryTree class
#include <iostream>
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

using namespace std;

class IntBinaryTree
{
private:
	struct TreeNode
	{
		int value;         // The value in the node
		TreeNode *left;    // Pointer to left child node
		TreeNode *right;   // Pointer to right child node
	};

	TreeNode *root;       // Pointer to the root node

						  // Private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(int, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;
	

public:
	// Constructor
	IntBinaryTree()
	{
		root = NULL;
	}

	// Destructor
	~IntBinaryTree()
	{
		destroySubTree(root);
	}

	// Binary tree operations
	void insertNode(int);
	bool searchNode(int);
	void remove(int);

	//operation to determe how many leaves are in the tree
	int leafCount(TreeNode *nodePtr)
	{
		if (nodePtr == NULL)
		{
			return 0;
		}
		else if(nodePtr->left == NULL && nodePtr ->right == NULL)
		{
			return 1;
		}
		else
		{
			return leafCount(nodePtr->left) + leafCount(nodePtr->right);
		}
	}

	//Operation to determine the tree height recursively
	int treeHeight(TreeNode *nodePtr)
	{
		if (nodePtr == NULL)
		{
			return 0;
		}
		else
		{
			int lHeight = treeHeight(nodePtr->left);
			int rHeight = treeHeight(nodePtr->right);
			if (lHeight > rHeight)
			{
				return lHeight + 1;
			}
			else return(rHeight + 1);
		}
	}
		
	//operation to build an array of tree width at each height
	void widthArray(TreeNode *nodePtr, int width[], int height)
	{
		if(nodePtr)
		{
			width[height]++;
			widthArray(nodePtr->left, width, height + 1);
			widthArray(nodePtr->right, width, height + 1);
		}
	}

	//function to display the results from leafCount
    void displayLeafCount()
	{
		cout << "There are " << leafCount(root) << " leaves in the tree." << endl; 
	}

	//function to display the results form treeHeight
	void displayTreeHeight()
	{
		cout << "The tree height is " << treeHeight(root) << endl;
	}

	//function to display the max width of the tree
	void displayTreeWidth()
	{
		int wArray[99999] = {};
		int maxWidth = wArray[0];
		widthArray(root, wArray, 0);
		for(int i = 0; i<treeHeight(root); i++)
		{

			if (wArray[i] > maxWidth)
				maxWidth = wArray[i];
		}
		cout << "The width of the tree is " << maxWidth << endl;
	}

	void displayInOrder() const
	{
		displayInOrder(root);
	}

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}

	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
};
#endif
