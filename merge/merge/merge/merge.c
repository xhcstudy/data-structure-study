#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n，分别表示nums1和nums2中的元素数目。
//请你合并nums2到nums1中，使合并后的数组同样按非递减顺序排列。
//注意 : 最终，合并后数组不应由函数返回，而是存储在数组nums1中。
//为了应对这种情况，nums1的初始长度为m + n, 其中前m 个元素表示应合并的元素，后n个元素为0，应忽略。nums2的长度为n。
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while ((end1 >= 0) && (end2 >= 0))
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}
//时间复杂度O(M+N)
//空间复杂度0(1)