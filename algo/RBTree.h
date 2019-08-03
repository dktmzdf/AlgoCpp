#pragma once
#include"Node.h"
#include<functional>
#include<iostream>
class RBTree
{
private:
	NodeTool::Node<int>* root;


	void leftRotate(NodeTool::Node<int>* x);
	void rightRotate(NodeTool::Node<int>* x);
	void swapColors(NodeTool::Node<int>* x1, NodeTool::Node<int>* x2);
	void swapValues(NodeTool::Node<int>* x1, NodeTool::Node<int>* x2);
	void fixRedRed(NodeTool::Node<int>* x);
	
	NodeTool::Node<int>* successor(NodeTool::Node<int>* x);
	NodeTool::Node<int>* BSTreplace(NodeTool::Node<int>* x);
	void treeDeleteNode(NodeTool::Node<int>* x);
	void fixDoubleBlack(NodeTool::Node<int>* x);
	void levelOrder(NodeTool::Node<int>* x);
	void inOrder(NodeTool::Node<int>* x);
public:
	RBTree();
	void insert(int data);
	NodeTool::Node<int>* getRoot();
	NodeTool::Node<int>* search(int data);
	void deleteByVal(int data);
	void printInOrder();
	void printLevelOrder();
};

