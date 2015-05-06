/*
Description

Problems involving the computation of exact values of very large magnitude and precision are common. 
For example, the computation of the national debt is a taxing experience for many computer systems. 

This problem requires that you write a program to compute the exact value of R^n where R is a real 
number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.

Input

The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6,
and the n value will be in columns 8 and 9.

Output

The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should 
be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if
the result is an integer.

Sample Input

95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12

Sample Output

548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
*/

/*
author: wt
date: 2015-5-5
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
using namespace std;

void exchange(float &a, string &sa)
{
	ostringstream buf;
	buf<<a;
	sa = buf.str();
	int la = sa.length();
}

void reverse(string &s)
{
	string temp;
	for(int i=s.length(); i>0; i--)
		temp.push_back(s[i-1]);
	s = temp;
}

string  mult(string a1, string a2)
{
	string an;
	reverse(a1);
	reverse(a2);
	vector<int> flag;
	flag.push_back(0);
	for(int i=0; i<a1.length(); i++)
	{
		for(int j=0; j<a2.length(); j++)
		{
			if(an.length()<=i+j)
			{
				flag.push_back(0);
				an.push_back(((a1[i]-48) * (a2[j]-48) + flag[i+j])%10 + 48);
				if((a1[i]-48) * (a2[j]-48) + flag[i+j] > 9)
					flag[i+j+1] += ((int)((a1[i]-48) * (a2[j]-48) + flag[i + j]) / 10);
				else
					flag[i+j+1] += 0;
				flag[i+j] = 0;

			}
			else
			{
				int temp = (a1[i]-48) * (a2[j]-48) + flag[i+j] + an[i+j];	;
				if (temp - 48 > 9)
				{
					flag[i+j+1] += (temp - 48)/10;
					an[i+j] = (temp - 48) % 10 + 48;
				}
				else
					an[i+j] = temp;
				flag[i+j] = 0;

			}
			
		}
	}
	if(flag[a1.length() + a2.length() - 1] != 0)
	{
		an.push_back(flag[a1.length() + a2.length() - 1] + 48);
	}
	reverse(an);
	reverse(a1);
	reverse(a2);
	return an;
}

string cul(string s, int b)
{
	if (b == 1)
		return s;
	else if (b%2 == 1)
		return mult(mult(cul(s, b/2), cul(s, b/2)), s);
	else if (b%2 == 0)
		return mult(cul(s, b/2),cul(s, b/2));
}

int dot_delete(string &str)
{
	int d = str.find('.');
	if(d != -1)
	{
		for(int i = str.length() - 1; i>0; i--)
		{
			if (str[i] == '0')
				str.erase(i, 1);
			else
				break;
		}
		str.erase(d,1);
	}
	return d;
}

int main()
{
	float a1;
	string sa1, sa2;
	int b, count, l;
	while(cin>>a1>>b)
	{
		if (b == 0)
		{
			cout<<1<<endl;
			continue;
		}
		if(a1 == 0)
		{
			cout<<0<<endl;
			continue;
		}
		exchange(a1, sa1);
		count = dot_delete(sa1);
		sa2 = cul(sa1, b);
		if (count != -1)
		{
			int insert = sa1.length() - count;
			insert = insert * b;
			insert = sa2.length() - insert;
			sa2.insert(insert, 1, '.');

		}
		l = sa2.length();
		for(int i=0; i<l; i++)
		{
			if (sa2[i] != '0')
				break;
			else
			{
				sa2.erase(i, 1);
				i--;
			}
		}
		cout<<sa2<<endl;
	}
	return 0;
}
