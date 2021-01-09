#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

#define fo(a,b) for(int a=0;a<(b);++a)
using ll = long long;

template<class T>
class SetridenePole
{
	private:
	T *polePrvku; // snad chcete ukazatel na první prvek pole a ne na pole, ne?
	int pocetPrvku;
	int maxPocet;
	public:
	~SetridenePole(){if(polePrvku) delete [] polePrvku;}
	SetridenePole(SetridenePole<T> &d):polePrvku(new T[d.maxPocet]),pocetPrvku(d.pocetPrvku),maxPocet(d.maxPocet)
	{
		fo(i,pocetPrvku) polePrvku[i]=d.polePrvku[i];
	}
	SetridenePole(int MaxPocet):polePrvku(new T[MaxPocet]),pocetPrvku(0),maxPocet(MaxPocet){}
	int vlozDoPole(int cislo)
	{
		if(maxPocet<=pocetPrvku+1) return 0;
		for(int i=pocetPrvku++;;i--)
		{
			if(!i || polePrvku[i-1]<cislo)
			{
				polePrvku[i]=cislo;
				return 1;
			}
			polePrvku[i]=polePrvku[i-1];
		}
	}
	void tiskniPole(FILE * f = stdout,const char * format="%d")
	{
		fo(i,pocetPrvku)
		{
			if(i) fprintf(f," ");
			fprintf(f,format,polePrvku[i]);
		}
		fprintf(f,"\n");
	}
};

int main()
{
	SetridenePole<int> a(50);
	SetridenePole<int> b(a);
	fo(i,100) a.vlozDoPole(rand()%100);
	a.tiskniPole();
	return 0;
}

