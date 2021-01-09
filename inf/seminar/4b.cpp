#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

#define fo(a,b) for(int a=0;a<(b);++a)
using ll = long long;

int gcd(int a,int b)
{
	while(a && b)
	{
		if(a>b) a=a%b;
		else b=b%a;
	}
	return a?a:b;
}
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<n;i++)
	{
		int y;
		scanf("%d",&y);
		x=gcd(x,y);
	}
	printf("%d\n",x);
	return 0;
}

