#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//bool binary_search(iterator beg, iterator end, value);
//����ָ��Ԫ�� �鵽����true  �鲻������false
//ʹ��ǰ�� ���ҵ������Ƿ�����������
//������������н��δ֪

//void Test1()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	
//	//�����������Ƿ���9
//	bool ret = binary_search(v.begin(), v.end(), 9);
//	if (ret)
//	{
//		cout << "�ҵ���Ԫ��" << endl;
//	}
//	else
//	{
//		cout << "δ�ҵ�Ԫ��" << endl;
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