#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n,m,del;
int v[103];

struct Edge
{
	int to;
	struct Edge *next;
}a,*list[103];

struct Node
{
	struct Edge *poi;
	struct Node *next;
}q,*queue,*tail;

void init()
{
	scanf("%d%d",&n,&m);
	int i,l,r;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		struct Edge *p=malloc(sizeof(a));
		p->to=r;
		p->next=NULL;
		if (list[l]==NULL)
			list[l]=p;
		else 
		{
			struct Edge *now=list[l];
			while (now->next!=NULL)
				now=now->next;
			now->next=p;
		}
		struct Edge *q=malloc(sizeof(a));
		q->to=l;
		q->next=NULL;
		if (list[r]==NULL)
			list[r]=q;
		else 
		{
			struct Edge *now=list[r];
			while (now->next!=NULL)
				now=now->next;
			now->next=q;
		}
	}
	scanf("%d",&del);
}

void sortt()
{
	int i;
	for (i=0;i<n;i++)
	{
		struct Edge *p=list[i];
		struct Edge *q=p;
		for (;p!=NULL;p=p->next)
			for (q=p;q!=NULL;q=q->next)
				if (p->to > q->to)
				{
					int tmp=p->to;
					p->to=q->to;
					q->to=tmp;
				}
	}
}

void dfs(int x)
{
	v[x]=1;
	if (x==0)
		printf("%d",x);
	else printf(" %d",x);
	struct Edge *now=list[x];
	while (now!=NULL)
	{
		if (v[now->to]==1)
		{
			now=now->next;
			continue;
		}
		dfs(now->to);
	}
}

void qpush(int x)
{
	struct Edge *t=list[x];
	while (t!=NULL)
	{
		if (v[t->to]==1)
		{
			t=t->next;
			continue;
		}
		v[t->to]=1;
		struct Node *now=malloc(sizeof(q));
		now->next=NULL;
		now->poi=t;
		if (queue==NULL)
		{
			queue=now;
			tail=now;
		}
		else
		{
			tail->next=now;
			tail=tail->next;
		}
		t=t->next;
	}
}

struct Edge *qpop()
{
	struct Edge *x=queue->poi;
	queue=queue->next;
	return x;
}

void bfs()
{
	qpush(0);
	v[0]=1;
	printf("0");
	while (queue!=NULL)
	{
		struct Edge *x=qpop();
		printf(" %d",x->to);
		v[x->to]=1;
		qpush(x->to);
	}
}

void solve()
{
	int i;
	for (i=0;i<103;i++)
		v[i]=0;
	dfs(0);
	printf("\n");
	
	for (i=0;i<103;i++)
		v[i]=0;
	bfs();
	printf("\n");
	
	for (i=0;i<103;i++)
		v[i]=0;
	v[del]=1;
	dfs(0);
	printf("\n");
	
	for (i=0;i<103;i++)
		v[i]=0;
	v[del]=1;
	bfs();
	printf("\n");
}

int main()
{
	init();
	sortt();
	solve();
	return 0;
}

