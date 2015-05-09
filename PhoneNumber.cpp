/*From: POJ
 *ID:1002
 这道题对于我这种半道出家没有扎实算法基础的人来说，确实有点蛋疼，算下来花了两天时间才AC。
 主要原因是超时。
 因为涉及到排序以及字符串的遍历迭代，所以一开始敲出来的代码完全不能看。乱，而且多。
 后来修改了好多遍，用了好几种不同的方法，终于写出来，幸好没放弃。

 有空的时候是得要多补补数据结构与算法基础了。
 * */
 /*
 author: wt
 date: 2015/5/9
 */
#include<iostream>
#include<list>
#include<map>
#include<string>
#include<stdlib.h>
#include<iomanip> 
using namespace std;

int conver(char ch)
{
	if(ch=='A' || ch=='B' || ch=='C')  
        return 2;  
        if(ch=='D' || ch=='E' || ch=='F')  
        return 3;  
        if(ch=='G' || ch=='H' || ch=='I')  
        return 4;
        if(ch=='J' || ch=='K' || ch=='L')  
        return 5;
        if(ch=='M' || ch=='N' || ch=='O')  
        return 6;
        if(ch=='P' || ch=='R' || ch=='S')  
        return 7;
        if(ch=='T' || ch=='U' || ch=='V')  
        return 8;
        if(ch=='W' || ch=='X' || ch=='Y')  
        return 9; 
}
int main()
{
	int n;
	cin>>n;
	if(n>100000)
		return 0; 
	list<char*> pnumber;
	map<int, int> time;
	while(n--)
	{
		char snumber[100];
		cin>>snumber;
		int x=0;
		for(int i=0; snumber[i]!='\0'; i++)
		{
			if(snumber[i]=='-' || snumber[i]=='Q' || snumber[i]=='Z')
				continue;
			else if(snumber[i]<='9')
				x = 10*x + snumber[i] - '0';
			else if(snumber[i]<='Z')
				x = 10*x + conver(snumber[i]);
		}
		time[x]++;
	}

	bool f = 0;
	for(map<int, int>::iterator iter = time.begin(); iter != time.end();++iter)
	{
		if(iter->second > 1)
		{
			int f_num = iter->first / 10000;
			int b_num = iter->first % 10000;
			cout<<setfill('0')<<setw(3)<<f_num<<'-'<<setfill('0')<<setw(4)<<b_num<<' '<<iter->second<<endl;
			f = 1;
		}
	}
	if (!f)
		cout<<"No duplicates."<<endl;
	return 0;
}
