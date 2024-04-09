//kmpÀ„∑®
#include <iostream>
#include <string>
#define Maxsize 5
using namespace std;


typedef struct Sq
{
	char data[Maxsize];
	int length;
}Sqstring;

void InitSq(Sqstring *t)
{
	t->length=0;
}

int InsertSq(Sqstring *s,int i,char a)
{
	if(i>=0&&i<s->length)
	{
		s->data[i]=a;
	}
	else
	return -1;
}

void getnext(Sqstring t,int next[])
{	int i=0,j=-1;
	next[0]=-1;
	while(i<t.length-1)
	{
		if(j==-1||t.data[i]==t.data[j])
		{
			i++;j++;
			next[i]=j;
		}
		else j=next[j];
	}
}


int KMPindex(Sqstring s,Sqstring t)
{
	int i=0,j=0;
	int next[Maxsize];
	getnext(t,next);
	while(i<s.length&&j<t.length)
	{
		if(s.data[i]==t.data[j]||j==-1)
		{
			i++;j++;
		}
		else
		j=next[j];
	}
	if(j>t.length)
	{
		return (i-t.length);
	}
	else 
	return -1;
}

int main()
{
	Sqstring s,t;
	InitSq(&s);
	
	InitSq(&t); 
	InsertSq(&s,0,'a'); 
	InsertSq(&s,1,'a'); 
	InsertSq(&s,2,'a'); 	
	InsertSq(&s,3,'b'); 	
	InsertSq(&t,0,'a'); 
	InsertSq(&t,1,'b'); 
	KMPindex(s,t);
 } 
