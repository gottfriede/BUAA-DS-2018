#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n,m;
int ter[103],v[103];
int out[103];
int ans=0,d=0,star,min_weight=0x7fffffff;

struct Edge
{
	int to;
	int num;
	int weight;
	struct Edge *next;
}e,*list[103];

int gmax(int x,int y)
{
	return x>y?x:y;
}

void insert_edge(int x,int y,int hao,int quan)
{
	struct Edge *p=malloc(sizeof(e));
	p->next=NULL;
	p->num=hao;
	p->weight=quan;
	p->to=y;
	if (list[x]==NULL)
		list[x]=p;
	else
	{
		struct Edge *now=list[x];
		while (now->next!=NULL)
			now=now->next;
		now->next=p;
	}
	
	struct Edge *q=malloc(sizeof(e));
	q->next=NULL;
	q->num=hao;
	q->weight=quan;
	q->to=x;
	if (list[y]==NULL)
		list[y]=q;
	else
	{
		struct Edge *now=list[y];
		while (now->next!=NULL)
			now=now->next;
		now->next=q;
	}	
}

void init()
{
	scanf("%d%d",&n,&m);
	int i,l,r,nu,w;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&nu,&l,&r,&w);
		insert_edge(l,r,nu,w);
		insert_edge(r,l,nu,w);
		if (w<min_weight)
		{
			min_weight=w;
			star=l;
		}
	}
	for (i=0;i<n;i++)
	{
		v[i]=0;
		ter[i]=i;
	}
}

void kruskal()
{
	v[star]=1;
	while (d!=n-1)
	{
		int i;
		int minn=0x7fffffff;
		int m_to=0,m_weight=0,m_num=0;
		for (i=0;i<n;i++)
			if (v[i])              //对于已联通的每个点 
			{
				struct Edge *p=list[i];
				for (;p!=NULL;p=p->next)
					if (!v[p->to]&&ter[p->to]!=ter[i]&&p->weight<minn)
					{
						m_to=p->to;
						m_weight=p->weight;
						m_num=p->num;
						minn=p->weight;
					}
			}
		v[m_to]=1;
		out[d]=m_num;
		d++;
		ans+=m_weight;
		for (i=0;i<n;i++)
			if (v[i])
				ter[i]=gmax(ter[m_to],ter[i]);
	}
}

void output()
{
	int i,j;
	for (i=0;i<n-1;i++)
		for (j=i;j<n-1;j++)
			if (out[i]>out[j])
			{
				int t=out[i];
				out[i]=out[j];
				out[j]=t;
			}
	printf("%d\n",ans);
	for (i=0;i<n-2;i++)
		printf("%d ",out[i]);
	printf("%d\n",out[n-2]);
}

int main()
{
	init();
	kruskal();
	output();
	return 0;
}
