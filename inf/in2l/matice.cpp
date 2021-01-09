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

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	assert(n>=m);
	auto ret = new ld[m];
	fo(i,m) ret[i]=0;
	auto data = new ld* [n];
	data[0] = new ld[n*(m+1)];
	fo(i,n-1) data[i+1]=data[i]+m+1;
	fo(i,n) fo(j,m+1) scanf("%LF",data[i]+j);
	fo(t,1000000)
	{
		ld maxim=0;
		fo(i,n)
		{
			ld sum=-data[i][m];
			fo(j,m)
				sum += data[i][j]*ret[j];
			sum /= data[i][i];
			ret[i] -= sum;
			maxim=max(maxim,abs(sum));
			//fo(i,m) printf("%Lf ",ret[i]);
			//printf("\n");
		}
		if(maxim<0.001) break;
	}
	fo(i,m) printf("%LF\n",ret[i]);
	delete [] data[0];
	delete [] data;
	delete [] ret;
	return 0;
}

