/*
From：PAT
describe: A+B for Polynomials (25)
author: wt
date: 20150529

用了大量的if else，看起来真是太丑了--
*/

#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	map<int, float> a1, a2;
	int k, num;
	float v, t = 1;
	cin>>num;
	while (num--)
	{
		cin>>k>>v;
		a1[k] = v;
	}
	cin>>num;
	while (num--)
	{
		cin>>k>>v;
		a2[k] = v;
	}
	map<int, float>::iterator it2 = a2.begin();
	for (map<int, float>::iterator it1 = a1.begin(); ; )
	{
		if(it2 == a2.end())
			break;
		for (;it2 != a2.end();)
		{
			if(it1 != a1.end())
			{
				if (it1->first == it2->first)
				{
					t = it1->second + it2->second;
					if(t == 0)
					{
						map<int, float>::iterator it = ++it1;
						a1.erase(--it1);
						it1 = it;
						it2++;
						break;
					}
					a1[it1->first] = t;
					++it2;
					break;
				}
				else if (it1->first < it2->first)
				{
					break;
				}
				else
				{
					a1[it2->first] = it2->second;
					it2++;
				}
			}
			else
			{
				a1[it2->first] = it2->second;
				it2++;
			}
		}
		if (it1 != a1.end() && t != 0)
			it1++;
		t = 1;
	}
	cout<<a1.size();
	if(a1.size())
		cout<<' ';
	for (map<int, float>::iterator it = a1.end(); it != a1.begin(); )
	{
		it--;
		int m = it->first;
		float n = it->second;
		cout<<m<<' '<<fixed<<setprecision(1)<<n;
		if (it != a1.begin())
			cout<<' ';
	}
}
