#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

#define fo(a,b) for(int a=0;a<(b);++a)
using ll = long long;
using ld = long double;

ld pow(ld a,ll n)
{
	if(a==0) return 1;
	ld v = pow(a,n/2);
	return v*v*(n%2?a:1);
}

ld fac(ll n)
{
	return n?fac(n-1)*n:1;
}

int main()
{
	int x;
	scanf("%d",&x);
	ld val = 0;
	ld last= -1;
	for(int i=0;val-last>ld(1)/10'000;i++)
	{
		last=val;
		val+=pow(x,i)/fac(i);
	}
	printf("%LF\n",val);
	return 0;
}

