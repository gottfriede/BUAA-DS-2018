#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
int n,m,q;
struct Node
{
	int num;
	struct Node *next;
}monk,*list;

void create()
{
	scanf("%d%d%d",&n,&m,&q);
	int i;
	struct Node *now=list;
	for (i=1;i<=n;i++)
	{
		struct Node *p;
		p=malloc(sizeof(monk));
		p->num=i;
		p->next=list;
		if (list==NULL)
			list=p;
		else now->next=p;
		now=p;
	}
}

int solve()
{
	struct Node *now=list;
	int i;
	for (i=1;i<q;i++)
		now=now->next;
	while (now->next!=now)
	{
		for (i=1;i<m-1;i++)
			now=now->next;
		now->next=now->next->next;
		now=now->next;
	}
	return now->num;
}

int main()
{
	create();
	printf("%d",solve());
	return 0;
}
