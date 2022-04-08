#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//������ֲ��ҵ�ʱ�临�Ӷ�
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
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//	return 0;
//}
//��ʱ�临�ӶȲ���ֻȥ������ѭ������Ҫȥ������˼��
//���ֲ��ҵ�ʱ�临�Ӷ�Ϊ��O(log2N)
//��õ������O(1)
//�����Ҳ�����1 * 2 * 2... * 2 = N
//2^X = N  ����������O(log2N)


//����׳˵ݹ�Fac��ʱ�临�Ӷ�
//long long Fac(size_t N)
//{
//	if (0 == N)
//	{
//		return 1;
//	}
//	return Fac(N - 1) *N;
//}
//�ݹ��㷨��ʱ�临�Ӷȵ��ڵݹ���� * ÿ�εݹ���õĴ���
//�׳˵ݹ�Fac��ʱ�临�Ӷ�Ϊ: O(N)


//����쳲������ݹ�Fib��ʱ�临�Ӷ�
//long long Fib(size_t N)
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}
//쳲������ݹ�Fib��ʱ�临�Ӷ�Ϊ: O(2^N)
//쳲��������еĵݹ�д����ȫ��һ��ʵ��û�õ��㷨����Ϊ̫����
//int main()
//{
//	printf("%lld", Fib(40));
//	return 0;
//}


//3.�ռ临�Ӷ�
//�ռ临�Ӷ�Ҳ��һ����ѧ�������ʽ���Ƕ�һ���㷨�����й�������ʱ����ռ�ô洢�ռ��С�����ȡ�
//�ռ临�ӶȲ��ǳ���ռ���˶���bytes�Ŀռ䣬��Ϊ���Ҳû̫�����壬���Կռ临�Ӷ�����Ǳ����ĸ������ռ临�Ӷȼ�����������ʵ�����Ӷ����ƣ�Ҳʹ�ô�O������ʾ����
//ע�� : ��������ʱ����Ҫ��ջ�ռ�(�洢�������ֲ�������һЩ�Ĵ�����Ϣ��)�ڱ����ڼ��Ѿ�ȷ�����ˣ���˿ռ临�Ӷ���Ҫͨ������������ʱ����ʽ����Ķ���ռ���ȷ����

//ð������Ŀռ临�Ӷ�
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
//ð������Ŀռ临�Ӷ�Ϊ: O(1)


//����Fibonacci�Ŀռ临�Ӷ�
//����쳲��������е�ǰn��
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
//�ռ临�Ӷ�Ϊ: O(N)


//����׳˵ݹ�Fac�Ŀռ临�Ӷ�
//ջ֡������Ҫ���ݹ�����
//long long Fac(size_t N)
//{
//	if (0 == N)
//	{
//		return 1;
//	}
//	return Fac(N - 1) *N;
//}
//�׳˵ݹ�Fac�Ŀռ临�Ӷ�Ϊ: O(N)


//����쳲������ݹ�Fib�Ŀռ临�Ӷ�
//long long Fib(size_t N)
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}
//쳲������ݹ�Fib�Ŀռ临�Ӷ�Ϊ: O(N)
//�ռ��ǿ����ظ����ã����ۼƵ�
//ʱ����һȥ���������ۼƵ�


//������:��ʧ������
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(N)ʱ���������
//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	//����x��0-n���������
//	for (int i = 0; i <= numsSize; i++)
//	{
//		x ^= i;
//	}
//	//Ȼ���ٺ�����������Ľ������ȱ������
//	for (int i = 0; i < numsSize; i++)
//	{
//		x ^= nums[i];
//	}
//	return x;
//}


//��ת����
//����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����k�ǷǸ���
//����:
//�����ܵ��������Ľ�����������������ֲ�ͬ�ķ������Խ���������
//�����ʹ�ÿռ临�Ӷ�ΪO(1)��ԭ���㷨������������?
//˼·1��������ת���
//ʱ�临�Ӷ�Ϊ: O(n * k)
//�ռ临�Ӷ�Ϊ: O(1)
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

//˼·2�������µĿռ�
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

//˼·3���������ã�ǰn-k������  ��k������  ��������
//ʱ�临�Ӷ�Ϊ: O(n)
//�ռ临�Ӷ�Ϊ: O(1)
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