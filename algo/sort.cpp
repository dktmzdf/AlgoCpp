#include"sort.h"



void make_array(int * arr_ptr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		arr_ptr[i] = rand();
		std::cout << arr_ptr[i] << " ";
	}

}

void sort()
{
	
	srand(time(0));
	int i;
	int item_size = 20;// rand();
	int * item_array = new int[item_size];
	make_array(item_array, item_size);
	std::cout << "\n";
	
	quicksort quick;
	quick.quick_sort(item_array, 0, item_size - 1);
	for (i = 0; i < item_size; i++)
	{
		
		std::cout << item_array[i] << " ";
	}
	/*
	mergesort merge(item_size);
	merge.merge_sort(item_array,0,item_size-1);
	*/

	/*
	heapsort heaps(item_array, item_size);
	for (i = 0; i < item_size; i++)
	{
		std::cout << item_array[i] << " ";
	}
	std::cout << "\n";
	*/
	delete[] item_array;
}
