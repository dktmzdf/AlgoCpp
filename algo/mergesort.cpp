#include "mergesort.h"


mergesort::mergesort(int size): arr_size(size)
{
	tmp = new int[arr_size];

}

mergesort::~mergesort()
{
	delete[] tmp;
}

void mergesort::merge_sort(int * item_arr, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(item_arr, start, mid);
		merge_sort(item_arr, mid+1, end);
		array_merge(item_arr, start, end);
	}
}

void mergesort::array_merge(int * item_arr, int start, int end)
{
	const int arr_size = (sizeof(item_arr) / sizeof(*item_arr));
	int mid = (start + end) / 2;

	int a, b;
	a = start;
	b = mid + 1;

	int t = start;
	while (a <= mid && b <= end)
	{
		if (item_arr[a] <= item_arr[b])
		{
			tmp[t] = item_arr[a];
			a++;
		}
		else {
			tmp[t] = item_arr[b];
			b++;
		}
		t++;
	}

	int k;
	if (a > mid) k = b;
	else k = a;

	for (t; t<= end; t++, k++) 
	{
		tmp[t] = item_arr[k];
	}
	for (t = 0; t <= end; t++)
	{
		item_arr[t] = tmp[t];
	}

	
}
