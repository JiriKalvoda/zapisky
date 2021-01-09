#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

#define fo(a,b) for(int a=0;a<(b);++a)
using ll = long long;

int main()
{
	FILE * in = fopen("VYPOVED.TXT","r");
	FILE * out = fopen("SKUTECNE.TXT","w");
	char ch;
	bool inWord=0;
	bool haveN=0;
	while((ch=getc(in))>0)
	{
		if(!inWord && ch=='n') haveN=1;
		else
		if(haveN && ch=='e') haveN=0;
		else
		{
			if(haveN) putc('n',out);
			haveN=0;
			putc(ch,out);
		}
		inWord = 'a'<=ch && ch<='z' || 'A'<=ch && ch <='Z';
	}
	fclose(in);
	fclose(out);
	return 0;
}

