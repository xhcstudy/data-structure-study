#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}
	int src = 0;
	int dst = 0;
	while (src < numsSize - 1)
	{
		if (nums[src] != nums[src + 1])
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}
	nums[dst] = nums[numsSize - 1];
	dst++;
	return dst;
}
int main()
{
	int arr[10] = { 1, 1, 2, 2, 4, 4, 5, 6, 7, 8 };
	int size = 0;
	size = removeDuplicates(arr, 10);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}