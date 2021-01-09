#include "9-str.h"

void strdel(char * s,int start,int num)
{
	int len=0;
	for(;s[len];len++);
	if(len<start+num) s[start]=0;
	else for(int i=start;i+num<=len;i++) s[i]=s[i+num];
}
void strins(char * s,const char * in,int start)
{
	int inlen=0;
	for(;in[inlen];inlen++);
	int len=0;
	for(;s[len];len++);
	for(int i=len;i>=start;i--) s[i+inlen]=s[i];
	for(int i=0;i<inlen;i++) s[i+start]=in[i];

}
