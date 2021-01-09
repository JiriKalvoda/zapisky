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

ld obdelnicky(function<ld(ld)> f,ld from,ld to,ld iteration=100)
{
	ld out = 0;
	ld len=to-from;
	fo(i,iteration)
		out+=f(from+(i+0.5)*len/iteration);
	return out*len/iteration;
}
ld lichobezniky(function<ld(ld)> f,ld from,ld to,ld iteration=100)
{
	ld out = 0;
	ld len=to-from;
	out+=f(from);
	out+=f(to);
	for(int i=1;i<iteration;i++)
		out+=2*f(from+i*len/iteration);
	return out*len/iteration/2;
}
ld pupky(function<ld(ld)> f,ld from,ld to,ld iteration=100)
{
	ld out = 0;
	ld len=to-from;
	out+=f(from);
	out+=f(to);
	for(int i=1;i<iteration;i++)
		out+=2*f(from+i*len/iteration);
	for(int i=0;i<iteration;i++)
		out+=4*f(from+(2*i+1)*len/(2*iteration));
	return out*len/(iteration*3*2);
}

int main()
{
	printf("%.10LF\n",obdelnicky([](ld x)->ld{return x*x;},0,2));
	printf("%.10LF\n",lichobezniky([](ld x)->ld{return x*x;},0,2));
	printf("%.10LF\n",pupky([](ld x)->ld{return x*x;},0,2));
	return 0;
}

