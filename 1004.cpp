/*
from：POJ
ID：1004
真不明白那些40B就能把功能实现的代码是怎么敲的，好想找个大神的代码来看看啊。
*/
#include<stdio.h>
float s,n,m;
int main()
{
	while(n++<12)
	{
		scanf("%f",&m);
		s+=m;
	}
	printf("$%.2f", s/12);
}
