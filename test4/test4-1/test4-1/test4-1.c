#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//OJ�ķ����ԭ��
//1.IO��
//����Ҫ�Լ�дͷ�ļ���main������
//������������:����Ҫscanf��ȡ
//���Խ��:����printf���

//2.�ӿ���  -  ����Ҫд��������ͷ�ļ��ȵ�    �ύ���Ժ󣬻��OJ�������ϵ�׼���õĴ���ϲ����ٱ���

//�ҳ����� - �Խ�leetcode�ӿ���
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ���дһ�������ҳ�������ֻ����һ�ε�����
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
	int count = 0;//��¼������֮���x�ĵڼ�λ��1
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


//����һ������nums��һ��ֵval������Ҫ ԭ�� �Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ�,������ʹ��O(1)����ռ䲢ԭ���޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ��

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
