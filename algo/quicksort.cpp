#include "quicksort.h"


void quicksort::quick_sort(int item_arr[], int left, int right)
{
	//initializing
	int arr_size = (sizeof(item_arr) / sizeof(*item_arr));
	int pivot = item_arr[left];
	int l_hold = left;
	int	r_hold = right;
	int i=0;
	while (left < right)
	{
		while((pivot <= item_arr[right]) && (left < right)) right--;

		if (left != right) item_arr[left] = item_arr[right];

		while ((pivot >= item_arr[left]) && (left < right)) left++;

		if (left != right) {
			item_arr[right] = item_arr[left];//arr[left] arr[right] are same value
			right--;
		}
		
	}

	item_arr[left] = pivot;
	int pivot_index = left;
	left = l_hold;
	right = r_hold;

	if(pivot_index > left) quick_sort(item_arr, left, pivot_index-1);
	if(pivot_index < right)quick_sort(item_arr, pivot_index+1, right);


}
