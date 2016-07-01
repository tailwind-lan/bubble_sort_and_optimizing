#include <stdio.h>
#include <algorithm>

using namespace std;

/*
 * 原始的冒泡排序法
 * 
 */
template <typename T>
void original_bubble_sort(T *arr, int length)
{
	int compared_count = 0;
	for (int i = length; i > 1; --i)
	{
		for (int j = 0; j < i - 1; ++j)
		{
			++compared_count;
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}

	printf("original_bubble_sort, compared_count: %u\n", compared_count);
}

/*
 * 原始的冒泡法，内部循环在某次扫描中没有执行交换，则说明此时数组已全部有序，无需再扫描了。
 * 因此，增加一个标记，每次发生交换，就标记，如果某次循环完没有标记，则说明已完成排序。
 */
template <typename T>
void improved_bubble_sort_v1(T *arr, int length)
{
	int compared_count = 0;
	bool has_swapped = true;
	for (int i = length; i > 1; --i)
	{
		//每次先重置为false
		has_swapped = false;
		for (int j = 0; j < i - 1; ++j)
		{
			++compared_count;
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				has_swapped = true;
			}
		}

		//上次内循环为发生交换，表明数组已全部有序，推出循环。
		if (has_swapped)
			break;
	}

	printf("improved_bubble_sort_v1, compared_count: %u\n", compared_count);
}

/*
 *
 *
 */
template <typename T>
void improved_bubble_sort_v2(T *arr, int length)
{
	int compared_count = 0;
	for (int i = length; i > 1; --i)
	{
		int swapped_pos = i - 1;
		for (int j = 0; j < swapped_pos; ++j)
		{
			++compared_count;
			if (arr[j] > arr[j + 1])
			{
				swapped_pos = j;
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	printf("improved_bubble_sort_v2, compared_count: %u\n", compared_count);
}