#include "RBTree.h"
#include<iostream>
using namespace NodeTool;

void RBTree::leftRotate(NodeTool::Node<int>* x)
{
	Node<int> *nParent = x->GetRight();
	Node<int> *tmp;

	if (x == root) root = nParent;

	x->moveDown(nParent);
	x->SetRight(nParent->GetLeft());

	if (nParent->GetLeft() != nullptr) 
	{
		tmp = nParent->GetLeft();
		tmp->SetParent(x);
	}
	nParent->SetLeft(x);
}

void RBTree::rightRotate(NodeTool::Node<int>* x)
{
	Node<int> *nParent = x->GetLeft();
	Node<int> *tmp;

	if (x == root) root = nParent;

	x->moveDown(nParent);
	x->SetLeft(nParent->GetRight());
	if (nParent->GetRight() != nullptr)
	{
		tmp = nParent->GetRight();
		tmp->SetParent(x);
	}
	nParent->SetRight(x);
}

void RBTree::swapColors(NodeTool::Node<int>* x1, NodeTool::Node<int>* x2)
{
	COLOR tmp;
	tmp = x1->GetColor();
	x1->SetColor(x2->GetColor());
	x2->SetColor(tmp);
}

void RBTree::swapValues(NodeTool::Node<int>* x1, NodeTool::Node<int>* x2)
{
	int tmp;
	tmp = x1->GetData();
	x1->SetData(x2->GetData());
	x2->SetData(tmp);
}

void RBTree::fixRedRed(NodeTool::Node<int>* x)
{
	if (x == root)
	{
		x->SetColor(BLACK); return;
	}
	Node<int> *parent = x->GetParent(), *grandparent = parent->GetParent(),
		*uncle = x->GetUncle();

	if (parent->GetColor() != BLACK)
	{
		
		if (uncle != nullptr && uncle->GetColor() == RED) 
		{
			// uncle red, perform recoloring and recurse
			parent->SetColor(BLACK);
			uncle->SetColor(BLACK);
			grandparent->SetColor(RED);
			fixRedRed(grandparent);
		}
		else 
		{
			// Else perform LR, LL, RL, RR
			if (parent->isOnLeft())
			{
				if (x->isOnLeft()) {
					//for Left left(I write abbreviation that 
					// means children below code. in short LL)
					swapColors(parent, grandparent);
				}
				else {
					//LR
					leftRotate(parent);
					swapColors(x, grandparent);
				}
				//LL and LR
				rightRotate(grandparent);
			}
			else 
			{
				if (x->isOnLeft()) 
				{
					rightRotate(parent);
					swapColors(x, grandparent);
				}
				else
				{
					swapColors(parent, grandparent);
				}
				leftRotate(grandparent);
			}
		}
	}
}

NodeTool::Node<int>* RBTree::successor(NodeTool::Node<int>* x)
{
	Node<int> *temp = x;

	while (temp->GetLeft() != nullptr)
		temp = temp->GetLeft();

	return temp;
	
}
// find node that replaces a deleted node in BST
NodeTool::Node<int>* RBTree::BSTreplace(NodeTool::Node<int>* x)
{
	// when node have 2 children
	if (x->GetLeft() != nullptr && x->GetRight() != nullptr)
		return successor(x->GetRight());

	// when leaf
	if (x->GetLeft() == nullptr && x->GetRight() == nullptr)
		return nullptr;

	// when single child
	if (x->GetLeft() != nullptr)
		return x->GetLeft();
	else
		return x->GetRight();
}

void RBTree::treeDeleteNode(NodeTool::Node<int>* x)
{
	// deletes the given node
	Node<int> *y = BSTreplace(x);
	//True when  y and x are both bloack
	bool xyBlack((y == nullptr || y->GetColor() == BLACK) && (x->GetColor() == BLACK));
	Node<int> * parent = x->GetParent();

	if (y == nullptr) {
		//y is null therefore v is leaf
		if (x == root) {
			//v is root , make root null
			root = nullptr;
		}
		else 
		{
			if (xyBlack) {
				//x and y are both black
				//x is leaf, fix double black at v
				fixDoubleBlack(x);
			}
			else
			{
				//x or v is red
				if (x->GetSibling() != nullptr)
				{
					//sibling is not null. make it red
					Node<int>* tmp = x->GetSibling();
					tmp->SetColor(RED);
				}
			}
			//delete x from th tree
			if (x->isOnLeft()) 
			{
				parent->SetLeft(nullptr);
			}
			else {
				parent->SetRight(nullptr);
			}
			
		}
		x->DeleteNode(x);
		return;

	}
	if (x->GetLeft() == nullptr || x->GetRight() == nullptr)
	{
		// x has 1 child
		if (x == root)
		{
			//x is root. so, data for x node changes data for y node and delete y node
			x->SetData(y->GetData());
			x->SetLeft(nullptr);
			x->SetRight(nullptr);
			y->DeleteNode(y);
		}
		else
		{
			//Detach x from tree and move y up
			if (x->isOnLeft())
			{
				parent->SetLeft(y);
			}
			else {
				parent->SetRight(y);
			}
			x->DeleteNode(x);
			y->SetParent(parent);
			if (xyBlack) 
			{
				//x and y both black, fix double black at y
				fixDoubleBlack(y);
			}
			else {

				y->SetColor(BLACK);
			}

		}
		return;
	}
	// v has 2 children, swap values with successor and recurse
	swapValues(x, y);
	treeDeleteNode(y);
}

void RBTree::fixDoubleBlack(NodeTool::Node<int>* x)
{
	if (x == root) return;// reached root
	Node<int> *sibling = x->GetSibling(), *parent = x->GetParent();
	if (sibling == nullptr)
	{
		//no sibling, double black pushed up
		fixDoubleBlack(parent);
	}
	else 
	{
		if (sibling->GetColor() == RED)
		{
			//sibling red
			parent->SetColor(RED);
			sibling->SetColor(BLACK);
			if (sibling->isOnLeft())
			{
				//left case
				rightRotate(parent);
			}
			else {
				//right case
				leftRotate(parent);
			}
			fixDoubleBlack(x);
		}
		else
		{
			if(sibling->hasRedChild())
			{
				Node<int> *siblingLeft = sibling->GetLeft();
				//at lieast 1 red children
				if (sibling->GetLeft() != nullptr &&  siblingLeft->GetColor() == RED)
				{
					if (sibling->isOnLeft())
					{
						//LL
						siblingLeft->SetColor(sibling->GetColor());
						sibling->SetColor(parent->GetColor());
						rightRotate(parent);
					}
					else {
						//RL
						siblingLeft->SetColor(parent->GetColor());
						rightRotate(sibling);
						leftRotate(parent);
					}

				}
				else
				{
					Node<int> * siblingRight = sibling->GetRight();
					if (sibling->isOnLeft())
					{
						//LR
						siblingRight->SetColor(parent->GetColor());
						leftRotate(sibling);
						rightRotate(parent);

					}
					else
					{
						siblingRight->SetColor(sibling->GetColor());
						sibling->SetColor(parent->GetColor());
						leftRotate(parent);
					}
				}
				parent->SetColor(BLACK);
			}
			else
			{
				//2BLACK CHILDREN
				sibling->SetColor(RED);
				if (parent->GetColor() == BLACK) fixDoubleBlack(parent);
				else parent->SetColor(BLACK);
			}
		}
	}
}

void RBTree::levelOrder(NodeTool::Node<int>* x)
{
	//it must need to implement queue

}

void RBTree::inOrder(NodeTool::Node<int>* x)
{
	if (x == nullptr) return;
	inOrder(x->GetLeft());
	std::cout << x->GetData() << " ";
	inOrder(x->GetRight());
}

RBTree::RBTree()
{
	root = nullptr;
}

void RBTree::insert(int data)
{
	Node<int> *newNode = new Node<int>(data);
	if (root == nullptr)
	{
		newNode->SetColor(BLACK);
		root = newNode;
	}
	{
		Node<int> *temp = search(data);
		if (temp->GetData() == data) return;

		newNode->SetParent(temp);
		if (data < temp->GetData()) temp->SetLeft(newNode);
		else temp->SetRight(newNode);

		fixRedRed(newNode);

			
	}
	
}

NodeTool::Node<int>* RBTree::getRoot()
{
	return root;
}

NodeTool::Node<int>* RBTree::search(int data)
{
	Node<int> *temp = root;
	while (temp != nullptr)
	{
		if (data < temp->GetData()) {
			if (temp->GetLeft() == nullptr) 
			{
				break;
			}
			else temp = temp->GetLeft();
		}
		else if (data == temp->GetData()) break;
		else
		{
			if (temp->GetRight() == nullptr) 
			{
				break;
			}
			else temp = temp->GetRight();
		}
	}
	return temp;
}

void RBTree::deleteByVal(int data)
{
	if (root == nullptr) return;
	Node<int> *x = search(data), *u;

	if (x->GetData() != data){ 
		std::cout << "No node found to delete with value: " << data << std::endl;
		return;
	}
	else
	{
		std::cout << "delete " << x->GetData() << " \n";
	}
	treeDeleteNode(x);

}

void RBTree::printInOrder()
{
	std::cout << "Inorder: " << std::endl;
	if (root == nullptr) std::cout << "Tree is empty" << std::endl;
	else inOrder(root);
	std::cout << std::endl;
	
}

void RBTree::printLevelOrder()
{
	std::cout << "not implement yet" << std::endl;
}
