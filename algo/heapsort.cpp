#include "heapsort.h"


heapsort::heapsort(int * item, int size):heap(size) 
{
	heap::arr = item;
	heap::heapify();
	heap_sort();
}


heapsort::~heapsort()
{
	heap::arr = nullptr;
}


void heapsort::heap_sort()
{
	int size = heap::heap_size_return();
	int * tmp = new int[size];
	for (int i = 0; i < size; i++) 
	{
		tmp[i] = heap::getmin();
		heap::delmin();
	}
	for (int i = 0; i < size; i++)
	{
		heap::arr[i] = tmp[i];
	}

	
	delete[] tmp;
}


