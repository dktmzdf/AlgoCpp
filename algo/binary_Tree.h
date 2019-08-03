#pragma once
#include"Node.h"


class BST
{
private:
	NodeTool::Node<int>* root;
public:
	BST();
	~BST();
	bool insert(int data);
	bool bSearchInsert(NodeTool::Node<int>* p, int data);
	NodeTool::Node<int>* search(int data);
	NodeTool::Node<int>* bSearch(NodeTool::Node<int>* p, int data);
	NodeTool::Node<int>* min();
	NodeTool::Node<int>* minNode(NodeTool::Node<int>* p);
	NodeTool::Node<int>* max();
	NodeTool::Node<int>* maxNode(NodeTool::Node<int>* p);
	NodeTool::Node<int>* parentNode(NodeTool::Node<int>* p, NodeTool::Node<int>* dest);
	bool bDelete(int data);
	bool deleteNode(NodeTool::Node<int>* p, int data);
	bool change(int data, int dest);

	void nodeAllPrint_preOrder();
	void nodeAllPrint_inOrder();
	void preOrder(NodeTool::Node<int> *p);
	void inOrder(NodeTool::Node<int> *p);

};

