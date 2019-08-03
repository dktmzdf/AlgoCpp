#pragma once

#include "heap.h"


class heapsort : public heap
{

public:

	heapsort(int * arr, int size);
	virtual ~heapsort();
	void heap_sort();
	
};

