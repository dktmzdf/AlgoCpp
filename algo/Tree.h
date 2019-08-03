#pragma once

#include"Node.h"
class Tree
{
private:
	NodeTool::generalNode<int>* root;
	NodeTool::generalNode<int>* pn;
public:
	Tree();
	~Tree();
	void setRoot(int data);
	void setPN(NodeTool::generalNode<int>* n);

	NodeTool::generalNode<int> *getRoot();
	NodeTool::generalNode<int> *getPN();
	void NodeChangeData(int data);
	void parentInsertChild(int data);
	int parentDeleteChild(int data);

	int returnChild();
};

