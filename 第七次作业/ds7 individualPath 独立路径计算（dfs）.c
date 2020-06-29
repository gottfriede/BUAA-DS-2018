#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n,m;
int v[1003],out[1003];
struct Edge
{
	int to;
	int num;
	struct Edge *next;
}e,*list[1003];

void insert_edge(int x1,int x2,int hao)
{
	struct Edge *p=malloc(sizeof(e));
	p->next=NULL;
	p->num=hao;
	p->to=x2;
	if (list[x1]==NULL)
		list[x1]=p;
	else 
	{
		struct Edge *now=list[x1];
		while (now->next!=NULL)
			now=now->next;
		now->next=p;
	}
	struct Edge *q=malloc(sizeof(e));
	q->to=x1;
	q->next=NULL;
	q->num=hao;
	if (list[x2]==NULL)
		list[x2]=q;
	else 
	{
		struct Edge *now=list[x2];
		while (now->next!=NULL)
			now=now->next;
		now->next=q;
	}
}

void init()
{
	scanf("%d%d",&n,&m);
	int i,l,r,numm;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&numm,&l,&r);
		insert_edge(l,r,numm);
	}
}

void dfs(int x,int ans)
{
	if (x==n-1)
	{
		int i;
		for (i=0;i<ans-1;i++)
			printf("%d ",out[i]);
		printf("%d\n",out[ans-1]);
		return;
	}
	v[x]=1;
	struct Edge *now=list[x];
	for (;now!=NULL;now=now->next)
		if (!v[now->to])
		{
			out[ans]=now->num;
			ans++;
			dfs(now->to,ans);
			ans--;
		}
	v[x]=0;
}

int main()
{
	init();
	
	dfs(0,0);
	return 0;
}

