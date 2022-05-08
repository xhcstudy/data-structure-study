#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//bool binary_search(iterator beg, iterator end, value);
//查找指定元素 查到返回true  查不到返回false
//使用前提 查找的数据是放在有序序列
//如果是无序序列结果未知

//void Test1()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	
//	//查找容器中是否有9
//	bool ret = binary_search(v.begin(), v.end(), 9);
//	if (ret)
//	{
//		cout << "找到了元素" << endl;
//	}
//	else
//	{
//		cout << "未找到元素" << endl;
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