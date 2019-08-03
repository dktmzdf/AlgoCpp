#pragma once
#include<iostream>
#include"Node.h"

constexpr auto MAX_HASH = 10;
template<typename T>
constexpr auto HASH_KEY(T key) { return key % MAX_HASH; }

using namespace std;
using namespace NodeTool;

template<typename T>
class hash
{
private:
	hashNode<T> *hashTable[MAX_HASH];

public:

	hash()
	{

	}


	~hash()
	{
		delete[] hashTable;
	}
	void AddHashData(int key, T data)
	{
		int hashkey = HASH_KEY<T>(key);
		if (hashTable[hashkey]->GetData() == 0)
		{
			hashTable[hashkey]->SetData(data);
			hashTable[hashkey]->SetDataExist(hashNode<T>::EXISTING);
		}
		else
		{
			hashNode<T> *newNode = new hashNode<T>;
			newNode->SetData(data);

			hashTable[hashkey]->SetRight(newNode);
		}
	}

	void delHashData(T id)
	{
		int hashkey = HASH_KEY<T>(id);
		if (hashTable[hashkey]->GetDataExist() == hashNode<T>::NOTHING)
			return;

		hashNode<T>* delNode = nullptr;
		if (hashTable[hashkey]->GetData() == id)
		{
			delNode = hashTable[hashkey];
		}
		else
		{
			hashNode<T>* node = hashTable[hashkey];
			hashNode<T>* next = hashTable[hashkey]->GetRight();

			while (next != nullptr)
			{
				if (next->GetData() == id)
				{
					node->SetRight = next->GetRight();
					delNode = next;
					break;
				}
				node = next;
				next = node->GetRight();
			}
		}
		delNode->DeleteNode(delNode);
	}

	hashNode<T>* findHashData(T id)
	{
		int hashkey = HASH_KEY(id);
		if (hashTable[hashkey] == nullptr)
		{
			return;
		}
		if (hashTable[hashkey]->GetData() == id)
		{
			return hashTable[hashkey];
		}
		else {
			hashNode<T>* node = hashTable[hashkey];

			while (node->GetRight != nullptr)
			{
				node = node->GetRight();
				if (node->GetData() == id)
				{
					return node;
				}
			}
		}
		return nullptr;
	}
	void PrTAllHashData()
	{
		cout << "###PrT All Hash Data###" << endl;
		for (int i = 0; i < MAX_HASH; i++)
		{

			if (hashTable[i] != NULL)
			{
				hashNode<T>* node = hashTable[i];
				while (node->GetRight() != nullptr)
				{
					cout << node->GetData() << " ";
					node = node->GetRight();
				}
				cout << node->GetData() << endl;


			}
		}

		cout << endl << endl;
	}
};



//출처: http://huiyu.tistory.com/en try/자료구조-체이닝-해시-테이블Chaining-Hash-Table [huiyu]