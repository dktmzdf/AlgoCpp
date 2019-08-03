#include "heap.h"


heap::heap()
{

}

heap::heap(int size):heap_size(size)
{
}

heap::heap(int * arr, int size): heap_size(size)
{
	int i;
	this->arr = new int[heap_size];
	for(i=0; i< heap_size; i++)
	this->arr[i] = arr[i];
	heapify();
}

heap::~heap()
{
	if (arr != nullptr) {
	

		delete[] arr;
	}
}


void heap::siftup(int index)
{
	if (index == 0)
		return;
	int parentIndex = (index - 1) / 2;
	if (arr[parentIndex] > arr[index])
	{
		int temp = arr[parentIndex];
		arr[parentIndex] = arr[index];
		arr[index] = temp;
		siftup(parentIndex);
	}
	
}

void heap::siftdown(int index)
{
	int lenght = heap_size;
	int leftchildindex = 2 * index + 1;
	int rightchildindex = 2 * index + 2;
	
	if (leftchildindex >= lenght) return;

	int minIndex = index;

	if (arr[index] > arr[leftchildindex]) minIndex = leftchildindex;
	if ((rightchildindex < lenght) && (arr[minIndex] > arr[rightchildindex]))
		minIndex = rightchildindex;

	if (minIndex != index)
	{
		int temp = arr[index];
		arr[index] = arr[minIndex];
		arr[minIndex] = temp;
		siftdown(minIndex);
	}
}

void heap::heapify()
{
	int i;
	for (i =  heap_size - 1;i >=0; --i)
	{
		siftdown(i);
	}
}

void heap::Insert(int value)
{
	
	int lenght = heap_size;
	arr[lenght] = value;
	siftup(lenght);
}

void heap::delmin()
{
	arr[0] = 2147483647;
	heapify();
}


int heap::heap_size_return()
{
	return heap_size;
}

int heap::getmin()
{
	return arr[0];
}

