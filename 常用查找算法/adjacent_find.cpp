#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//adjacent_find(iterator beg, iterator end);
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����

//void Test1()
//{
//	vector<int> v;
//	v.push_back(0);
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(3);
//	v.push_back(1);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(3);
//
//	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
//
//	if (pos == v.end())
//	{
//		cout << "û���ظ����ڵ�Ԫ��" << endl;
//	}
//	else
//	{
//		cout << "���ظ������ڵ�Ԫ�أ���Ԫ��Ϊ:" << *pos << endl;
//	}
//}
//
//int main()
//{
//	Test1();
//
//	system("pause");
//	return 0;
//}