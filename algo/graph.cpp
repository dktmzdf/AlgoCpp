#include"graph.h"


void make_graph(int * arr_ptr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr_ptr[i] = rand();
		//std::cout << arr_ptr[i] << " ";
	}
}

void graph()
{
	srand(time(0));
	int i;
	int item_size = 2000;// rand();
	int * item_grahp = new int[item_size];
	make_graph(item_grahp, item_size);
	std::cout << "\n";
	
	/*
	BST bst;
	for (i = 0; i < item_size; i++) bst.insert(item_grahp[i]);
	bst.nodeAllPrint_preOrder();
	*/
	/*
	RBTree rb;
	for (i = 0; i < item_size; i++) rb.insert(item_grahp[i]);
	rb.printInOrder();

	for (i = 0; i < item_size/10; i++)
	{
		rb.deleteByVal(rand() % item_size);
	}
	
	rb.printInOrder();
	*/

	Graph<int> test;
	for (i = 0; i < item_size; i++) test.insert(item_grahp[i]);
	//test.printNode();
	for (i = 0; i < item_size; i++)
	{
		for(int j = 0; j< 5 ; j++)
		test.connect(item_grahp[i], item_grahp[rand() % item_size]);
		
	}
	test.print();
	//test.DFS();
	test.BFS();
	//test.~Graph();
	
	
	for (i = 0; i < item_size; i++)
	{
		//std::cout << item_grahp[i] << " ";
	}
	std::cout << "\n";

	delete[] item_grahp;
}
