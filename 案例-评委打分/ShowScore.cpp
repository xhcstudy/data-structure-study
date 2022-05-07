#define _CRT_SECURE_NO_WARNINGS 1

#include "ShowScore.h"

void ShowScore(vector<Person> v)
{
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ÐÕÃû:" << it->m_Name
			<< "\tµÃ·Ö:" << it->m_Score << endl;
	}
}