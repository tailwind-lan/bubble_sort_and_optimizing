#include <stdio.h>
#include "bubble_sort_and_optimizing.h"

int main()
{
	int max = 20;
	int arr[max];
	for (int i = 0; i < max; ++i)
		arr[i] = rand()/ 100000;
	
	for (int i = 0; i < max; ++i)
		printf("%u ", arr[i]);

	original_bubble_sort(arr, max);
	improved_bubble_sort_v1(arr, max);
	improved_bubble_sort_v2(arr, max);
}
