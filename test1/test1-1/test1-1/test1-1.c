#define _CRT_SECURE_NO_WARNINGS 1
//1.什么是数据结构 ?
//数据结构(Data Structure)是计算机存储、组织数据的方式，指相互之间存在一种或多种特定关系的数据元素的集合。
//2.什么是算法 ?
//算法(Algorithm) : 就是定义良好的计算过程，他取一个或一组的值为输入，并产生出一个或一组值作为输出。简单来说算法就是一系列的计算步骤，用来将输入数据转化成输出结果。

//算法的时间复杂度和空间复杂度
//1.算法效率
//2.时间复杂度
//3.空间复杂度
//4.常见时间复杂度以及复杂度练习

//1.算法效率
//如何衡量一个算法的好坏
//算法在编写成可执行程序后，运行时需要耗费时间资源和空间(内存)资源。因此衡量一个算法的好坏，一般是从时间和空间两个维度来衡量的，即时间复杂度和空间复杂度。
//时间复杂度主要衡量一个算法的运行快慢，而空间复杂度主要衡量一个算法运行所需要的额外空间。在计算机发展的早期，计算机的存储容量很小。所以对空间复杂度很是在乎。
//但是经过计算机行业的迅速发展，计算机的存储容量已经达到了很高的程度。所以我们如今已经不需要再特别关注一个算法的空间复杂度。

//2.时间复杂度
//时间复杂度的定义:在计算机科学中，算法的时间复杂度是一个函数，它定量描述了该算法的运行时间。
//一个算法执行所耗费的时间，从理论上说，是不能算出来的，只有你把你的程序放在机器上跑起来，才能知道。
//但是我们需要每个算法都上机测试吗 ? 是可以都上机测试，但是这很麻烦，所以才有了时间复杂度这个分析方式。
//一个算法所花费的时间与其中语句的执行次数成正比例，算法中的基本操作的执行次数，为算法的时间复杂度。
//即 : 找到某条基本语句与问题规模N之间的数学表达式，就是算出了该算法的时间复杂度。
#include <stdio.h>
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (--M)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	Func1(10);
//	return 0;
//}
//时间复杂度的函数式 F(N) = N * N + 2 * N + 10
//N越大，后两项对结果的影响越小
//实际上，计算时间复杂度并不需要计算精确的执行次数，只需要大概执行次数，那么我们使用大O的渐进表示法

//大O的渐进表示法
//大O符号(Big O notation) :是用于描述函数渐进行为的数学符号。
//推导大O阶方法 :
//1、用常数1取代运行时间中的所有加法常数。
//2、在修改后的运行次数函数中，只保留最高阶项。
//3、如果最高阶项存在且不是1，则去除与这个项目相乘的常数。得到的结果就是大O阶。
//使用大O的渐进表示法以后，Func1的时间复杂度为 :O(N^2)

//计算Func2的时间复杂度
//void Func(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//Func2的时间复杂度为：O(N)

//计算Func3的时间复杂度
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//Func3的时间复杂度为：O(M + N)  
//如果M远大于N -> O(M)    如果N远大于M -> O(N)
//如果M和N差不多大 -> O(M) O(N)

//计算Func4的时间复杂度
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//Func4的时间复杂度为：O(1)   
//O(1)不是代表算法运行一次，是常数次

//计算strchr(查找字符)的时间复杂度
//#include <string.h>
//const char* strchr(const char* str, int character);
//最好情况:任意输入规模的最小运行次数(下界)
//平均情况 : 任意输入规模的期望运行次数
//最坏情况 : 任意输入规模的最大运行次数(上界)
//当一个算法随着输入不同，时间复杂度不同，时间复杂度做悲观预期，看最坏情况
//所以strchr的时间复杂度为：O(N)

//计算冒泡排序的时间复杂度
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (0 == exchange)
//		{
//			break;
//		}
//	}
//}
//精确F(N) = N * (N - 1) / 2
//冒泡排序的时间复杂度为：O(N^2)

//计算二分查找的时间复杂度
#include <assert.h>
int BinarySearch(int* a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
		{
			begin = mid + 1;
		}
		else if (a[mid] > x)
		{
			end = mid;
		}
		else
			return mid;
	}
	return -1;
}
int my_BinarySearch(int* a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (a[mid] > x)
		{
			end = mid - 1;
		}
		else if (a[mid] < x)
		{
			begin = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 5; 
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = my_BinarySearch(arr, sz, k);
	if (-1 == ret)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}
	return 0;

//算时间复杂度不能只去看几层循环，而要去看他的思想
//二分查找的时间复杂度为：O(log2N)