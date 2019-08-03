#pragma once


class mergesort
{
private:
	const int arr_size;
	int *tmp;
public:
	mergesort(int size);
	~mergesort();
	void merge_sort(int * item_arr, int start, int end);
	void array_merge(int * item_arr, int start, int end);
};

