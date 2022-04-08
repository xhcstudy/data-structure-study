#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//计算二分查找的时间复杂度
#include <assert.h>
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//		{
//			begin = mid + 1;
//		}
//		else if (a[mid] > x)
//		{
//			end = mid;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//int my_BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int mid = (begin + end) / 2;
//		if (a[mid] > x)
//		{
//			end = mid - 1;
//		}
//		else if (a[mid] < x)
//		{
//			begin = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 5;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = my_BinarySearch(arr, sz, k);
//	if (-1 == ret)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	return 0;
//}
//算时间复杂度不能只去看几层循环，而要去看他的思想
//二分查找的时间复杂度为：O(log2N)
//最好的情况是O(1)
//最坏情况找不到：1 * 2 * 2... * 2 = N
//2^X = N  所以最坏情况是O(log2N)


//计算阶乘递归Fac的时间复杂度
//long long Fac(size_t N)
//{
//	if (0 == N)
//	{
//		return 1;
//	}
//	return Fac(N - 1) *N;
//}
//递归算法的时间复杂度等于递归次数 * 每次递归调用的次数
//阶乘递归Fac的时间复杂度为: O(N)


//计算斐波那契递归Fib的时间复杂度
//long long Fib(size_t N)
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}
//斐波那契递归Fib的时间复杂度为: O(2^N)
//斐波那契数列的递归写法完全是一个实际没用的算法，因为太慢了
//int main()
//{
//	printf("%lld", Fib(40));
//	return 0;
//}


//3.空间复杂度
//空间复杂度也是一个数学函数表达式，是对一个算法在运行过程中临时额外占用存储空间大小的量度。
//空间复杂度不是程序占用了多少bytes的空间，因为这个也没太大意义，所以空间复杂度算的是变量的个数。空间复杂度计算规则基本跟实践复杂度类似，也使用大O渐进表示法。
//注意 : 函数运行时所需要的栈空间(存储参数、局部变量、一些寄存器信息等)在编译期间已经确定好了，因此空间复杂度主要通过函数在运行时候显式申请的额外空间来确定。

//冒泡排序的空间复杂度
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
//冒泡排序的空间复杂度为: O(1)


//计算Fibonacci的空间复杂度
//返回斐波那契数列的前n项
#include <stdlib.h>
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//	{
//		return NULL;
//	}
//	long long* fibArray = (long long*)malloc((n + 1)*sizeof(long long));
//	if (fibArray == NULL)
//	{
//		perror("__LINE__");
//		return NULL;
//	}
//	fibArray[0] = 0;
//	fibArray[0] = 1;
//	for (size_t i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//
//	return fibArray;
//}
//空间复杂度为: O(N)


//计算阶乘递归Fac的空间复杂度
//栈帧的消耗要看递归的深度
//long long Fac(size_t N)
//{
//	if (0 == N)
//	{
//		return 1;
//	}
//	return Fac(N - 1) *N;
//}
//阶乘递归Fac的空间复杂度为: O(N)


//计算斐波那契递归Fib的空间复杂度
//long long Fib(size_t N)
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}
//斐波那契递归Fib的空间复杂度为: O(N)
//空间是可以重复利用，不累计的
//时间是一去不复返，累计的


//面试题:消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数，你有办法在O(N)时间内完成吗
//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	//先让x和0-n的数字异或
//	for (int i = 0; i <= numsSize; i++)
//	{
//		x ^= i;
//	}
//	//然后再和数组异或，最后的结果就是缺的数字
//	for (int i = 0; i < numsSize; i++)
//	{
//		x ^= nums[i];
//	}
//	return x;
//}


//旋转数组
//给定一个数组，将数组中的元素向右移动k个位置，其中k是非负数
//进阶:
//尽可能的想出更多的解决方案，至少有三种不同的方法可以解决这个问题
//你可以使用空间复杂度为O(1)的原地算法解决这个问题吗?
//思路1：暴力旋转求解
//时间复杂度为: O(n * k)
//空间复杂度为: O(1)
//void Move_Right_arr(int arr[], int k, int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < k; i++)
//	{
//		int temp = 0;
//		temp = arr[n - 1];
//		for (j = n - 1; j > 0; j--)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[0] = temp;
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	Move_Right_arr(arr, 4, 10);
//	return 0;
//}

//思路2：开辟新的空间
#include <stdlib.h>
//int* Move_Right_arr(int arr[], int k, int n)
//{
//	int* a = (int*)malloc(n*sizeof(int));
//	if (NULL == a)
//	{
//		perror("__LINE__");
//		return NULL;
//	}
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		a[i] = arr[n - k - i];
//	}
//	for (i = k; i < n - 1; i++)
//	{
//		a[i] = arr[i - k];
//	}
//	return a;
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int p[10] = { 0 };
//	p[10] = Move_Right_arr(arr, 2, 10);
//	return 0;
//}

//思路3：三次逆置：前n-k项逆置  后k个逆置  整体逆置
//时间复杂度为: O(n)
//空间复杂度为: O(1)
void Reverse(int* arr, int left, int right)
{
	while (left < right)
	{
		int temp = 0;
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		right--;
		left++;
	}
}
void Move_Right_arr(int arr[], int k, int n)
{
	Reverse(arr, 0, n - k - 1);
	Reverse(arr, n - k, n - 1);
	Reverse(arr, 0, n - 1);
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Move_Right_arr(arr, 3, 10);
	return 0;
}