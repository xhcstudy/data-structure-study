#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//OJ的分类和原理
//1.IO型
//我们要自己写头文件、main函数等
//测试用例输入:我们要scanf获取
//测试结果:我们printf输出

//2.接口型  -  不需要写主函数和头文件等等    提交了以后，会跟OJ服务器上的准备好的代码合并，再编译

//找出单身狗 - 对接leetcode接口型
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。编写一个函数找出这两个只出现一次的数字
int* FindSingleDog(int arr[], int size, int* returnSize)
{
	int x = 0;
	int m = 0;
	int n = 0;
	int i = 0;
	*returnSize = 2;
	int* a = (int*)malloc(8);
	if (NULL == a)
	{
		perror("__LINE__");
		return NULL;
	}
	int count = 0;//记录异或完成之后的x的第几位是1
	for (i = 0; i < size; i++)
	{
		x ^= arr[i];
	}
	while (x % 2 != 1)
	{
		x /= 2;
		count++;
	}
	for (i = 0; i < size; i++)
	{
		if (((arr[i] >> count) &1) == 1)
		{
			m ^= arr[i];
		}
		else
		{
			n ^= arr[i];
		}
	}
	a[0] = m;
	a[1] = n;
	return a;
}
int main()
{
	int arr1[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	int* p = NULL;
	int size = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	p = FindSingleDog(arr1, sz, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	p = NULL;
}


//给你一个数组nums和一个值val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间,你必须仅使用O(1)额外空间并原地修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素

//int removeElement(int* nums, int numsSize, int val)
//{
//	int src = 0;
//	int dst = 0;
//	while (src < numsSize)
//	{
//		if (nums[src] != val)
//		{
//			nums[dst] = nums[src];
//			dst++;
//		}
//		src++;
//	}
//	return dst;
//}
