#include <stdio.h>
#include <algorithm>
#include "bubble_sort_and_optimizing.h"

int main()
{
	int max = 20;
	int arr[max];
	for (int i = 0; i < max; ++i)
		arr[i] = rand()/ 100000;
	
	for (int i = 0; i < max; ++i)
		printf("%u ", arr[i]);

	printf("\n");
	original_bubble_sort(arr, max);
	std::swap(arr[max - 1], arr[5]);
	original_bubble_sort(arr, max);
	std::swap(arr[max - 1], arr[5]);
	improved_bubble_sort_v1(arr, max);
	std::swap(arr[max - 1], arr[5]);
	improved_bubble_sort_v2(arr, max);
}
