#define _CRT_SECURE_NO_WARNINGS 1

#include "ShowScore.h"

void ShowScore(vector<Person> v)
{
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����:" << it->m_Name
			<< "\t�÷�:" << it->m_Score << endl;
	}
}