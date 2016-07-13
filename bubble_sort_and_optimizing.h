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
		if (!has_swapped)
			break;
	}

	printf("improved_bubble_sort_v1, compared_count: %u\n", compared_count);
	printf("after improved_bubble_sort_v1: ");
	for (int k = 0; k < length; ++k)
                printf("%u ", arr[k]);

	printf("\n");
}

/*
 * 做进一步优化。如果有100个数的数组，仅前面10个无序，后面90个都已排好序且都大于前面10个数字，
 * 那么在第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定已有序了，
 * 记录下这个位置，第二次只要从数组头部遍历到这个位置就可以了。
 */
template <typename T>
void improved_bubble_sort_v2(T *arr, int length)
{
	int compared_count = 0;
	int i, j;
	int swapped_pos = length;
	while (swapped_pos > 0)
	{
		j = swapped_pos;
		swapped_pos = 0;
		for (i = 1; i < j; ++i)
		{
			++compared_count;
			if (arr[i - 1] > arr[i])
			{
				swapped_pos = i;
				std::swap(arr[i - 1], arr[i]);
			}
		}
	}

	printf("improved_bubble_sort_v2, compared_count: %u\n", compared_count);
	printf("after improved_bubble_sort_v2: ");
        for (int k = 0; k < length; ++k)
                printf("%u ", arr[k]);

        printf("\n");
}
