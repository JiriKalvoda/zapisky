#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

#define fo(a,b) for(int a=0;a<(b);++a)
using ll = long long;

struct TPRVEK{
	int hodnota;
	TPRVEK * dalsi=0;
};
void add(TPRVEK *& root,TPRVEK *in)
{
	if(root && root->hodnota<in->hodnota) return add(root->dalsi,in);
	in->dalsi=root;
	root = in;
}
void print(TPRVEK * root)
{
	if(!root) return;
	printf("%d\n",root->hodnota);
	print(root->dalsi);
}

int main()
{
	TPRVEK * r=0;
	add(r,new TPRVEK{5,0});
	add(r,new TPRVEK{7,0});
	add(r,new TPRVEK{3,0});
	add(r,new TPRVEK{6,0});
	print(r);
	return 0;
}

