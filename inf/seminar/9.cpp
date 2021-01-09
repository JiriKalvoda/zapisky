#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif
#include "9-str.h"

#define fo(a,b) for(int a=0;a<(b);++a)
using ll = long long;

int main()
{
	char str[1234]="Petr nenese saxofon";
	puts(str);
	strdel(str,5,2);
	puts(str);
	strins(str,"sne",7);
	puts(str);
	puts(str);
	return 0;
}

