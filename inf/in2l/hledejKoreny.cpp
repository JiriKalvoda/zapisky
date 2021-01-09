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


ld f(ld x)
{
	return x*x-1+0.523;
}

ld findRoot(ld l,ld r,ld p,ld  f(ld))
{
	while(r-l>p)
	{
		ld m=l+(r-l)/2;
		if(!f(l)) return l;
		if(!f(r)) return r;
		if(!f(m)) return m;
		if(f(l)*f(m)<0) r=m;
		else l=m;
	}
	return l+(r-l)/2;
}

ld findRoot(ld x,ld p,ld  f(ld),ld df(ld))
{
	do
	{

	}
}


int main()
{
	ld minim=-1000;
	ld maxim=1000;
	ld step=0.1;
	for(ld i=minim;i<maxim;i+=step)
	{
		if(f(i)*f(i+step) <= 0)
		{
			printf("kořen v  <%LF,%LF>\n",i,i+step);
			printf("%LF\n",findRoot(i,i+step,step/100000,&f));
		}

	}
	return 0;
}

