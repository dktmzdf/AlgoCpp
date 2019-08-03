#include "binary_Tree.h"
#include<iostream>


BST::BST()
{
	root = nullptr;
	
}


BST::~BST()
{
	delete root;
}

bool BST::insert(int data)
{
	
	if (root == nullptr)
	{
		root = new NodeTool::Node<int>(data);
		
		return true;
	}
	else return bSearchInsert(root, data);
}

bool BST::bSearchInsert(NodeTool::Node<int>* p, int data)
{
	
	if (p->GetData() > data) {
		if (p->GetLeft() == nullptr)
		{

			p->SetLeft(new NodeTool::Node<int>(data));
			NodeTool::Node<int> *tmp = p->GetLeft();
			return true;
		}
		else return bSearchInsert(p->GetLeft(), data);
	}
	else {
		if (p->GetRight() == nullptr)
		{
	
			p->SetRight(new NodeTool::Node<int>(data));
			return true;
		}
		else return bSearchInsert(p->GetRight(), data);
	}

	return false;
}

NodeTool::Node<int>* BST::search(int data)
{
	return bSearch(this->root, data);
}

NodeTool::Node<int>* BST::bSearch(NodeTool::Node<int>* p, int data)
{
	if(p == nullptr) return nullptr;
	if (p->GetData() == data) return p;
	if (p->GetData() > data) return bSearch(p->GetLeft(), data);
	else return bSearch(p->GetRight(), data);
}

NodeTool::Node<int>* BST::min()
{
	return minNode(root);
}

NodeTool::Node<int>* BST::minNode(NodeTool::Node<int>* p)
{
	if (p == nullptr) return nullptr;
	if (p->GetLeft() == nullptr) return p;
	return minNode(p->GetLeft());
}

NodeTool::Node<int>* BST::max()
{
	return maxNode(root);
}

NodeTool::Node<int>* BST::maxNode(NodeTool::Node<int>* p)
{
	if (p == nullptr) return nullptr;
	if (p->GetRight() == nullptr) return p;
	return maxNode(p->GetRight());
}

NodeTool::Node<int>* BST::parentNode(NodeTool::Node<int>* p, NodeTool::Node<int>* dest)
{
	NodeTool::Node<int> *left, *right;
	if (p == nullptr) return nullptr;
	if (p->GetLeft() != nullptr) { if (p->GetLeft() == dest) return p; }
	if (p->GetRight() != nullptr) { if (p->GetRight() == dest) return p; }
	if (p->GetLeft() == nullptr && p->GetRight() == nullptr) return nullptr;
	left = parentNode(p->GetLeft(), dest);
	right = parentNode(p->GetRight(), dest);
	if (left != nullptr) return left;
	else if (right != nullptr) return right;
	else return nullptr;

	return nullptr;
}

bool BST::bDelete(int data)
{
	NodeTool::Node<int>* max, *p_max, *tmp;
	if (root == nullptr) return false;
	if (root->GetData() == data) {
		if (root->GetLeft() != nullptr) {
			tmp = root;
			max = maxNode(max->GetLeft());
			p_max= parentNode(root, max);
			if (p_max->GetLeft() == max) p_max->SetLeft(max->GetLeft());
			else p_max->SetRight(max->GetLeft());
			max->SetLeft(tmp->GetLeft());
			max->SetRight(tmp->GetRight());
			root = max;
			delete tmp;
			return true;
		}
		else if (root->GetRight() != nullptr) {
			tmp = root;
			root = tmp->GetRight();
			delete tmp;
			return true;
		}
		else
		{
			delete root;
			root = nullptr;
			return true;
		}
	}
	else return deleteNode(root, data);
}

bool BST::deleteNode(NodeTool::Node<int>* p, int data)
{
	NodeTool::Node<int>* max, *p_max, *tmp, *p_tmp;
	if ((tmp = bSearch(p, data)) == nullptr) return false;


	p_tmp = parentNode(p, tmp);
	if (tmp->GetLeft() != nullptr) {
		max = maxNode(tmp->GetLeft());
		p_max = parentNode(p, max);
		if (p_max->GetLeft() == max) {
			p_max->SetLeft(max->GetLeft());
		}
		else if(p_max->GetRight() == max) {
			p_max->SetRight(max->GetRight());
		}
		max->SetLeft(tmp->GetLeft());
		max->SetRight(tmp->GetRight());
		if (p_tmp->GetLeft() == tmp) p_tmp->SetLeft(max);
		if (p_tmp->GetRight() == tmp) p_tmp->SetRight(max);

		delete tmp;
		return true;
	}
	else if (tmp->GetRight() != nullptr) {
		if (p_tmp->GetLeft() == tmp)p_tmp->SetLeft(tmp->GetRight());
		else p_tmp->SetRight(tmp->GetRight());
		delete tmp;
	}
	else {
		if (p_tmp->GetLeft() == tmp) p_tmp->SetLeft(nullptr);
		else p_tmp->SetRight(nullptr);
		delete tmp;
		return true;
	}

	return false;
}

bool BST::change(int data, int dest)
{
	if (search(data) == nullptr) return false;
	insert(dest);
	return false;
}


void BST::nodeAllPrint_preOrder()
{
	preOrder(root);
	std::cout << "\n";
	
}

void BST::nodeAllPrint_inOrder()
{
	inOrder(root);
	std::cout << "\n";
}

void BST::preOrder(NodeTool::Node<int> *p)
{
	if (p == nullptr) return;
	std::cout << p->GetData() << " ";
	preOrder(p->GetLeft());
	preOrder(p->GetRight());
}

void BST::inOrder(NodeTool::Node<int>* p)
{
	if (p == nullptr) return;
	inOrder(p->GetLeft());
	std::cout << p->GetData() << " ";
	inOrder(p->GetRight());
}
