#pragma once
#include"binary_Tree.h"
#include"Tree.h"
#include"RBTree.h"
#include <iostream>
#include <ctime>
using namespace NodeTool;

void make_graph(int *, int);
void graph();


template<typename T>
class Graph
{
private:
	Node<T> *start;
	int nodeNum;
	//left is direction that goes to next node
	//right is direction that connects other node
	//
	Node<T>* searchNode(T data)
	{
		if (start->GetData() == data) return start;
		Node<T> *tmp = start;
		while (tmp->GetLeft() != nullptr)
		{
			if (tmp->GetData() == data) break;
			tmp = tmp->GetLeft();
		}
		return tmp;
	}
	Node<T>* searchConnect(Node<T>* SP, T dest)
	{
		Node<T>* tmp = SP;
		while (tmp->GetRight() != nullptr)
		{
			if (tmp->GetData == dest) break;
			tmp = tmp->GetRight();
		}
		return tmp;
	}
	void allNodeDelete(Node<T>* dNode)
	{
		if (dNode == nullptr) return;
		Node<T>* tmp = dNode;

		while (tmp->GetLeft() != nullptr)
		{

			tmp = tmp->GetLeft();
		}

		allDisconnect(tmp);
	}

	void allDisconnect(Node<T> *dNode)
	{
		if (dNode == nullptr) return;
		Node<T>* tmp = dNode;
		
		while (tmp->GetRight() != nullptr)
		{
			
			
			tmp = tmp->GetRight();
		}
		dNode->DeleteNode(tmp);
	}
	
	void connectNode(Node<T> *start, Node<T>* dest)
	{
		Node<T> *tmp = start;
		if (tmp->GetRight() != nullptr)
			while (tmp->GetRight() != nullptr)
			{
				if (tmp->GetData() == dest->GetData())
					return;
				tmp = tmp->GetRight();
			
			}
		Node<T> *newNode = new Node<T>(dest);
		newNode->SetLeft(nullptr);
		newNode->SetRight(nullptr);
		newNode->SetGP(dest);
		
		tmp->SetRight(newNode);
		tmp = nullptr;
		delete tmp;
		//std::cout << dest->GetData() << " dest "<< tmp->GetData() << " parent\n";
		
	}
	void connectNode(Node<T> *start, T dest)
	{
		Node<T> *tmp = start;
		if (tmp->GetRight() != nullptr)
		
			while (tmp->GetRight() != nullptr)
			{
				if (tmp->GetData() == dest)
					return;
				tmp = tmp->GetRight();

			}

		
		Node<T> *newNode = new Node<T>(dest);

		newNode->SetGP(searchNode(dest));
		
		tmp->SetRight(newNode);
		newNode->SetLeft(tmp);
		tmp = nullptr;
		//std::cout << dest << " dest " << tmp->GetData() << " parent\n";
	}
public:
	Graph()
	{
		nodeNum = 0;
		start = nullptr;
	}
	~Graph()
	{
		allNodeDelete(start);
	}
	
	void nodeDelete(T node)
	{
		Node<T>* tmp = searchNode(node);
		allConnectDelete(tmp);
	}
	void connect(T startNode, T dest)
	{
		if (startNode != dest) {
			Node<T> *SP = searchNode(startNode);
			if (SP == nullptr)
			{
				SP = nodeInsert(startNode);
				Node<T> *D = searchNode(dest);
				//connectNode(SP, dest);
				connectNode(SP, D);
			}
			else
			{
				//connectNode(SP, dest);
				Node<T> *D = searchNode(dest);
				connectNode(SP, D);
			}
		}

	}
	void disconnect(T startNode, T connectNode)
	{
		Node<T>* SP = searchNode(startNode);
		if (SP == nullptr)
		{
			std::cout << "not found for starting Node.";
			return;
		}
		Node<T>* tmp;
		tmp = searchConnect(SP, connectNode);
		if (tmp == nullptr)
		{
			std::cout << "not found for starting connect.";
		}
		Node<T> tmpLeft = tmp->GetLeft();
		Node<T> tmpRight = tmp->GetRight();
		tmpLeft->SetRight(tmpRight);
		tmp->DeleteNode();
	}

	void insert(T nodeData)
	{

		if (start == nullptr)
		{
			Node<T> *newNode = new Node<T>(nodeData);
			start = newNode;
		}
		else {
			Node<T> *tmp = start;
			while (tmp->GetLeft() != nullptr)
			{
				tmp = tmp->GetLeft();
			}
			Node<T> *newNode = new Node<T>(nodeData);
			tmp->SetLeft(newNode);
		}
		nodeNum++;
	}

	Node<T>* nodeInsert(T nodeData)
	{
		
		if (start == nullptr)
		{
			Node<T> *newNode = new Node<T>(nodeData);
			start = newNode;
			return start;
		}
		else {
			Node<T> *tmp = start;
			while (tmp->GetLeft() != nullptr)
			{
				tmp = tmp->GetLeft();
			}
			Node<T> *newNode = new Node<T>(nodeData);
			tmp->SetLeft(newNode);
			return tmp;
		}

	}

	int totalNode()
	{
		int num = 0;
		Node<T> *tmp = start;
		while (tmp->GetLeft() != nullptr)
		{
			tmp = tmp->GetLeft();
			num++;
		}
		return num;
	}
	void printConnect(T node)
	{
		Node<T> *tmp = searchNode(node);
		do
		{
			tmp = tmp->GetRight();
			if (tmp == nullptr) {
				std::cout << "end\n";
					break;
			}
			else std::cout << tmp->GetData() << " - ";
		} while (1);
	}
	void printConnect(Node<T>* node)
	{
		Node<T> *tmp = node;
		do
		{
			tmp = tmp->GetRight();
			if (tmp == nullptr) {
				std::cout << "end\n";
				break;
			}
			else std::cout << tmp->GetData() << " - ";
		} while (1);
	}
	void printNode()
	{

		Node<T> *tmp = start;
		std::cout << tmp->GetData() << "\n|\n";
		do
		{
			tmp = tmp->GetLeft();
			if (tmp == nullptr) {
				std::cout << "end\n";
					break;
			}
			else std::cout << tmp->GetData() << "\n|\n";
		} while (1);
		
	}
	void print()
	{
		std::cout << "print\n";
		Node<T> *tmp = start;
		do
		{
			
			if (tmp == nullptr) {
				std::cout << "end\n";
				break;
			}
			
			else {
				std::cout << tmp->GetData() << " - ";
				printConnect(tmp);
				std::cout << "\n|\n";
				
			}
			tmp = tmp->GetLeft();
		} while (1);

	}
	int nodeTotal() {
		return nodeNum;
	}

	void DFS()
	{
		dfsReadyPrint(start);
	}
	void DFS(Node<T>* node)
	{
		
		dfsReadyPrint(node);
	}
	void dfsReadyPrint(Node<T>* node)
	{
		T* visitNode = new T[nodeNum];
		int *visit = new int[nodeNum];
		std::fill_n(visit, nodeNum, -1);
		DFS(start, visitNode, visit);
		for (int i = 0; i < nodeNum; i++)
		{
			if(visit[i] == 1) std::cout << visitNode[i] << " ";
		}
		//std::cout << "\n";
		delete[] visit;
		delete[] visitNode;
	}
	void DFS(Node<T>* node,T* visitNode ,int *visit)
	{

		//std::cout << " node data ";
		//std::cout <<node->GetData() << " \n";
		if (visitNode == nullptr) {
			std::cout << "initialzing in function.";
			visitNode = new T[nodeNum];
			visit = new int[nodeNum];
			std::fill_n(visit, nodeNum, -1);
		}
		
		Node<T>* tmp1 = node;
		int Rightflag = 0;

		for (int i = 0; i < nodeNum; i++)
		{
			if (visitNode[i] != tmp1->GetData()) {
				if (visit[i] == -1)
				{
					visitNode[i] = tmp1->GetData();
					visit[i] = 1;
					break;
				}
			}
			else {
				Rightflag = 1;
				break;
			}
	
		}
		
		if (tmp1->GetRight() != nullptr) 
		{
			//std::cout << tmp1->GetData() << " ";
			tmp1 = tmp1->GetRight();
			if (Rightflag == 0)
			{
				int flag = 0;
				Node<T> *tmp2 = tmp1->GetParent();
				//std::cout << tmp1->GetData() << " " << tmp2->GetData() << " \n";
				for (int i = 0; i < nodeNum; i++)
				{

					if (visitNode[i] == tmp2->GetData())
					{
						flag = 1;

						break;

					}

				}
				tmp2 = nullptr;
				delete tmp2;
				if (flag == 0) {

					DFS(tmp1->GetParent(), visitNode,visit);
				}



			}
			DFS(tmp1, visitNode, visit);
		}
		tmp1 = nullptr;
		delete tmp1;

		return;

	}


	void BFS()
	{
		bfsReadyPrint(start);
	}
	void BFS(Node<T>* node)
	{

		bfsReadyPrint(node);
	}
	void bfsReadyPrint(Node<T>* node)
	{
		T* visitNode = new T[nodeNum];
		int *visit = new int[nodeNum];
		std::fill_n(visit, nodeNum, -1);
		BFS(start, visitNode, visit);
		for (int i = 0; i < nodeNum; i++)
		{
			if (visit[i] == 1) std::cout << visitNode[i] << " ";
		}
		//std::cout << "\n";
		delete[] visit;
		delete[] visitNode;
	}
	void BFS(Node<T>* node, T* visitNode, int *visit)
	{

		//std::cout << " node data ";
		//std::cout <<node->GetData() << " \n";
		if (visitNode == nullptr) {
			std::cout << "initialzing in function.";
			visitNode = new T[nodeNum];
			visit = new int[nodeNum];
			std::fill_n(visit, nodeNum, -1);
		}

		Node<T>* tmp1 = node;
		int Rightflag = 0;

		for (int i = 0; i < nodeNum; i++)
		{
			if (visitNode[i] != node->GetData()) {
				if (visit[i] == -1)
				{
					visitNode[i] = node->GetData();
					visit[i] = 1;
					break;
				}
			}
			else {
				Rightflag = 1;
				break;
			}

		}

		if (tmp1->GetRight() != nullptr)
		{
			tmp1 = tmp1->GetRight();
			//std::cout << tmp1->GetData() << " ";
			BFS(tmp1, visitNode, visit);
			if (Rightflag == 0)
			{
			
			
			BFS(tmp1->GetParent(), visitNode, visit);

			}

		}
		tmp1 = nullptr;
		delete tmp1;

		return;

	}


};