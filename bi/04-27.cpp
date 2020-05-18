#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

using ll = long long;

const int MAX = 1123456;

int a,b;
int x,y;

int main()
{
	srand(time(0));
	int n;
	scanf("%d",&n);
	x=y=20;
	for(int i=0;i<n;i++)
	{
		a=b=0;
		int p = x+y;
		for(int i=0;i<p/2;i++)
		{
			int r = rand()%(x+y);
			if(r<x) {a+=2;x--;}
			else {b+=2;y--;}
		}
		printf("%d %d\n",a,b);
		x=a;y=b;
	}

	return 0;
}

