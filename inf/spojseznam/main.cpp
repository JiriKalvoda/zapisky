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
	public:
	List():begin(0){}
	void push_front(T in)
	{
		begin = new ListItem<T>(in,begin);
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
		return tmp.data;
	}
	void push_back(T in)
	{
		ListItem<T> ** it = &begin;
		while(*it) it = &((*it)->next); 
		*it = new ListItem<T>(in,0);
	}
	T pop_back()
	{
		if(!begin) return T{};
		ListItem<T> ** it = &begin;
		while((*it)->next) it = &((*it)->next); 
		ListItem<T> tmp = **it;
		delete *it;
		*it = 0;
		return tmp.data;
		
	}
	void insertToSort(T in)
	{
		ListItem<T> ** it = &begin;
		while(*it && (*it)->data < in) it = &((*it)->next); 
		*it = new ListItem<T>(in,*it);
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
		return tmp.data;
	}
};
int main()
{
	List<int> list;
	printf("remove first:%d\n", list.pop_front());
	printf("remove last:%d\n", list.pop_back());
	printf("remove index 0:%d\n", list.remove(0));
	printf("remove index 5:%d\n", list.remove(5));
	list.push_front(1);
	list.push_front(11);
	list.push_front(111);
	list.push_front(1111);
	list.print(stdout,"%d ");
	list.push_back(21);
	list.push_back(211);
	list.push_back(2111);
	list.push_back(21111);
	list.print(stdout,"%d\n","");
	printf("remove first:%d\n", list.pop_front());
	printf("remove last:%d\n", list.pop_back());
	printf("remove index 0:%d\n", list.remove(0));
	printf("remove index 5:%d\n", list.remove(5));
	printf("remove index 1:%d\n", list.remove(1));
	list.print(stdout,"%d\n","");

	List<long long> sort;
	sort.insertToSort(151);
	sort.insertToSort(45);
	sort.insertToSort(664185);
	sort.insertToSort(11);
	sort.print(stderr,"%10lld");

	return 0;
}

