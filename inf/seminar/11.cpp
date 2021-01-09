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
	FILE * f = fopen("ZPRAVA.TXT","r");
	char in[1234];
	vector<char *> data;
	while(fscanf(f,"%1234s",in)==1)
	{
		data.push_back(new char [strlen(in+1)]);
		strcpy(data.rbegin()[0],in);
	}
	sort(data.begin(),data.end(),[](char * a,char * b)->bool{return strcmp(a,b)<0;});
	int n=0;
	for(int i=0;i<int(data.size());i++)
	{
		n++;
		if(i==int(data.size())-1 || strcmp(data[i],data[i+1]))
		{
			printf("%s %d\n",data[i],n);
			n=0;
		}
	}
	fclose(f);
	return 0;
}

