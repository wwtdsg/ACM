/*
From: The 15th Zhejiang University Programming Contest - A

Input

There are multiple test cases. The first line of input contains an integer T indicating the number of test cases. For each test case:

The first line contains a integer N (3 <= N <= 100), which describes that there are N students need to be checked.

The second line contains N integers indicating the ID card number of N students. All ID card numbers are 32-bit integers.

Output

For each test case, output the ID card number which is different from others.

Sample Input

3
10
1 1 1 1 1 1 1 1 6 1
3
9 9 8
5
90016 90016 90016 2009 90016
Sample Output

6
8
2009
*/

/*
author: wt
date: 2015-5-6
*/

#include <iostream>
using namespace std;

int main()
{
	int t, n;
	cin>>t;
	long* out = (long *)malloc(sizeof(long) * t);
	int count = 0;
	while(t - count)
	{
		long value[2];
		int f0 = 0;
		int f1 = 0;
		cin>>n;
		long* ID = (long *)malloc(sizeof(long) * n); //注意释放内存
		for(int i=0; i<n; i++)
		{
			cin>>ID[i];
			if(i == 0)
			{
				value[0] = ID[i];
				f0++;
			}
			else if(ID[i] != ID[i-1])
			{
				value[1] = ID[i];
				f1++;
				for(int j=i+1; j<n; j++)
				{
					cin>>ID[j];
					if(ID[j] == value[1])
						f1++;
					else
						f0++;
				}
				break;
			}
			else
				f0++;
		}
		free(ID);
		if (f0 == 1)
			out[count] = value[0];
		else
			out[count] = value[1];
		count++;
	}
	for(int i=0; i<t; i++)
		cout<<out[i]<<endl;
	free(out);

}
