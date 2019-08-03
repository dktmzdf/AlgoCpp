#pragma once


class heap
{
private:
	
	int heap_size;
protected:
	int * arr;
	void siftup(int index);
	void siftdown(int index);
	void heapify();
public:
	heap();
	heap(int size);
	heap(int * arr, int size);
	virtual ~heap();

	void Insert(int value);
	void delmin();
	int heap_size_return();
	int getmin();

	
};

