#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

#define fo(a,b) for(int a=0;a<(b);++a)
using ll = long long;

const int n=100;
int arr[n];
void print()
{
	int i=0;
x:
	printf(i?" %d":"%d",arr[i++]);
	if(i<n) goto x;
	printf("\n");
}
int main()
{
	{
		int i=0;
a:
		arr[i++]=rand()%1000;
		if(i<n) goto a;
	}
	print();
b:
	{
		bool ch=0;
		int i=0;
c:
		if(arr[i]>arr[i+1])
		{
			ch=1;
			arr[i]^=arr[i+1];
			arr[i+1]^=arr[i];
			arr[i]^=arr[i+1];
		}
		if(++i<n-1) goto c;
		if(ch) 	goto b;
	}
	print();
	return 0;
}

