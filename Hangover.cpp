/*
From: POJ
ID:1003
这道题一开始采用的方法是遍历搜寻，对每一个可能的值穷举，完成案例时间花了16ms。
后来换了二分查找，完成案例还是花了16ms。。。
真是够了。
*/

//遍历搜寻：
#include<iostream>
using namespace std;

float plus(float n)
{
	if(n==1)
		return 1/2.0;
	else
		return 1/(n+1) + plus(n-1);
}
int main()
{
	float lenth;
	while(1)
	{
		cin>>lenth;
		if(!lenth)
			break;
		float l = 0.0;
		int n = 1;
		while(l<lenth)
		{
			l = plus(n++);
		}
		cout<<n-1<<' '<<"card(s)"<<endl;
	}
	return 0;
}

//二分查找
/*
#include<iostream>
using namespace std;

float plu(float n)
{
	if(n==1)
		return 1/2.0;
	else
		return 1/(n+1) + plu(n-1);
}

int di(int max, int min, float lenth)
{	
	if(max ==min || (max - min) == 1)
		if (plu(min)>=lenth)
			return min;
		else return max;
	else if(plu((max-min)/2 + min)>lenth)
	{
		max = (max-min)/2 + min;
		di(max, min, lenth);
	}
	else if(plu((max-min)/2 + min)<lenth)
	{
		min = (max-min)/2 + min;
		di(max, min, lenth);
	}
}

int main()
{
	float lenth;
	while(1)
	{
		cin>>lenth;
		if(!lenth)
			break;
		float l = 0.0;
		int n = 276;
		int a = di(n, 1, lenth);
		cout<<a<<" card(s)"<<endl;
	}
	return 0;
}
*/
