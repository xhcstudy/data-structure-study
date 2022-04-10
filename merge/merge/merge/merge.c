#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�����������ǵݼ�˳�����е���������nums1��nums2��������������m��n���ֱ��ʾnums1��nums2�е�Ԫ����Ŀ��
//����ϲ�nums2��nums1�У�ʹ�ϲ��������ͬ�����ǵݼ�˳�����С�
//ע�� : ���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������nums1�С�
//Ϊ��Ӧ�����������nums1�ĳ�ʼ����Ϊm + n, ����ǰm ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ���n��Ԫ��Ϊ0��Ӧ���ԡ�nums2�ĳ���Ϊn��
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
//ʱ�临�Ӷ�O(M+N)
//�ռ临�Ӷ�0(1)