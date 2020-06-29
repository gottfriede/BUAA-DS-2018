#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

struct Node
{
	int coef,expp;
	struct Node *next;
}a,*lista,*listb,*listc;

void create(int x)
{
	int coe,ex;
	char ch;
	struct Node *now;
	if (x==1)
		now=lista;
	if (x==2)
		now=listb;
	while (1)
	{
		scanf("%d%d%c",&coe,&ex,&ch);
		struct Node *p=malloc(sizeof(a));
		p->coef=coe;
		p->expp=ex;
		p->next=NULL;
		if (x==1)
		{
			if (lista==NULL)
				lista=p;
			else now->next=p;
			now=p;
		}
		if (x==2)
		{
			if (listb==NULL)
			listb=p;
			else now->next=p;
			now=p;
		}
		if (ch=='\n') return;
	}
}

void multi()
{
	struct Node *now=listc,*now1=lista,*now2=listb;
	while (now1!=NULL)
	{
		while (now2!=NULL)
		{
			struct Node *p=malloc(sizeof(a));
			p->coef=now1->coef*now2->coef;
			p->expp=now1->expp+now2->expp;
			p->next=NULL;
			if (listc==NULL)
				listc=p;
			else now->next=p;
			now=p;
			now2=now2->next;
		}
		now2=listb;
		now1=now1->next;
	}
}

void comb()
{
	struct Node *now=listc;
	while (now!=NULL)
	{
		struct Node *bi=now;
		while (bi->next!=NULL)
		{
			if (bi->next->expp==now->expp)
			{
				now->coef+=bi->next->coef;
				bi->next=bi->next->next;
			}
			bi=bi->next;
		}
		now=now->next;
	}
}

void sortt()
{
	struct Node *now=listc;
	while (now!=NULL)
	{
		struct Node *bi=now->next;
		while (bi!=NULL)
		{
			if (bi->expp > now->expp)
			{
				int t=bi->coef;
				bi->coef=now->coef;
				now->coef=t;
				t=bi->expp;
				bi->expp=now->expp;
				now->expp=t;
			}
			bi=bi->next;
		}
		now=now->next;	
	}
}

void printff()
{
	struct Node *now=listc;
	while (now!=NULL)
		if (now->coef!=0)
		{
			printf("%d %d ",now->coef,now->expp);
			now=now->next;
		}
}

int main()
{
	create(1);
	create(2);
	multi();
	comb();
	sortt();
	printff();
	return 0;
}
