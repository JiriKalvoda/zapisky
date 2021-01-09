#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

#define fo(a,b) for(int a=0;a<(b);++a)

void prevod10do2(unsigned char vstup, char *vystup){
	for(int i=7;i>=0;i--)
	{
		vystup[i]=(vstup&1)+'0';
		vstup>>=1;
	}

}

void prevod2do10(char *vstup, unsigned char *vystup){
	*vystup=0;
	fo(i,8)
		*vystup=(*vystup<<1)+vstup[i]-'0';

}

int main(){
	char binarka[9];//9 znaků pro 8 nul a jedniček a jeden znak konec řetězce
	unsigned char cisloDesitkove;//bezznaménkové 1bajtové celé číslo v rozsahu 0..255

	prevod10do2(241, binarka);
	cout << binarka << endl; //melo by vytisknout "11110001"

	prevod2do10(binarka, &cisloDesitkove);
	cout << (int)cisloDesitkove << endl; //melo by vytisknout 241, znak je nutno přetypovat na int, aby se tisklo číslo
}
