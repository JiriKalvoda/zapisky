#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

using ll = long long;

template<class T> class ListItem
{
	public:
	T data;
	ListItem<T> * next;
	ListItem (T Data, ListItem<T> * Next):data(Data),next(Next){}
};
template<class T> class List
{
	private:
	ListItem<T> * begin;
	int sizeNum;
	public:
	List():begin(0),sizeNum(0){}
	int size()
	{
		return sizeNum;
	}
	void push_front(T in)
	{
		begin = new ListItem<T>(in,begin);
		sizeNum++;
	}
	void print(FILE * f,const char * format,const char * end = "\n")
	{
		for(auto it = begin;it;it=it->next)
			fprintf(f,format,it->data);
		fprintf(f,"%s",end);
	}
	T pop_front()
	{
		if(!begin) return T{};
		ListItem<T> tmp = *begin;
		delete begin;
		begin = tmp.next;
		sizeNum--;
		return tmp.data;
	}
	void push_back(T in)
	{
		ListItem<T> ** it = &begin;
		while(*it) it = &((*it)->next); 
		*it = new ListItem<T>(in,0);
		sizeNum++;
	}
	T pop_back()
	{
		if(!begin) return T{};
		ListItem<T> ** it = &begin;
		while((*it)->next) it = &((*it)->next); 
		ListItem<T> tmp = **it;
		delete *it;
		*it = 0;
		sizeNum--;
		return tmp.data;
		
	}
	void insertToSort(T in)
	{
		ListItem<T> ** it = &begin;
		while(*it && (*it)->data < in) it = &((*it)->next); 
		*it = new ListItem<T>(in,*it);
		sizeNum++;
	}
	T remove(int n)
	{
		ListItem<T> ** it = &begin;
		for(int i=0;i<n;i++)
		{
			if(!*it) return T{};
			it = &((*it)->next); 
		}
		if(!*it) return T{};
		ListItem<T> tmp = **it;
		delete *it;
		*it = tmp.next;
		sizeNum--;
		return tmp.data;
	}
};
const int NMAX = 123456;
int main()
{

	char * in = new char[NMAX];
	while(scanf("\n%[^\n]",in)>=1)
	{
		List<int> l;
		int num=0;
		bool numInput=0;
		for(int i=0;in[i];i++)
		{
			if('0'<=in[i]&&in[i]<='9')
			{
				numInput=1;
				num=num*10+(in[i]-'0');
			}
			else
			{
				if(numInput)
				{
					l.push_front(num);
					numInput=0;
					num=0;
				}
				switch(in[i])
				{
					case '+':
						if(l.size()<2) goto errStuckEmpty;
						l.push_front(l.pop_front() + l.pop_front());
					break;
					case '-':
						if(l.size()<2) goto errStuckEmpty;
						l.push_front(l.pop_front() - l.pop_front());
					break;
					case '*':
						if(l.size()<2) goto errStuckEmpty;
						l.push_front(l.pop_front() * l.pop_front());
					break;
					case '/':
						if(l.size()<2) goto errStuckEmpty;
						l.push_front(l.pop_front() / l.pop_front());
					break;
				}
			}
		}
		if(l.size()==1)
			printf("%d\n",l.pop_front());
		else
			printf("ERROR STUCK SIZE IS WRONG!!\n");
		if(0)
		{
			errStuckEmpty:;
			printf("ERROR STUCK IS EMPTY!!\n");
			break;
		}
	}
	return 0;
}

