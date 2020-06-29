#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int n,x0x,y0y,max_poi=0;
char s1[37],s2[37];
int dis[2533],v[2533],way[2533][103];

struct Node
{
	char name[37];
	int changge;
	int num;
	int train;
}a,poi[2533];

struct Edge
{
	int to;
	int weight;
	struct Edge *next;
}e,*list[2533];

int hash(int num_train,int num_station)
{
	return num_train*50+num_station;
}

void insert_edge(struct Node *l,struct Node *r)
{
	struct Edge *p=malloc(sizeof(e));
	p->next=NULL;
	p->to=r->num;
	p->weight=1;
	if (list[l->num]==NULL)
		list[l->num]=p;
	else
	{
		struct Edge *now=list[l->num];
		while (now->next!=NULL)
			now=now->next;
		now->next=p;
	}
	
	struct Edge *q=malloc(sizeof(e));
	q->next=NULL;
	q->to=l->num;
	q->weight=1;
	if (list[r->num]==NULL)
		list[r->num]=q;
	else
	{
		struct Edge *now=list[r->num];
		while (now->next!=NULL)
			now=now->next;
		now->next=q;
	}
}

void find_the_same()
{
	int i,j;
	for (i=1;i<=2500;i++)
		if (poi[i].changge==1)
		for (j=i+50;j<=2500;j++)
			if (poi[j].changge==1&&strcmp(poi[i].name,poi[j].name)==0)
			{
				struct Edge *p=malloc(sizeof(e));
				p->next=NULL;
				p->to=j;
				p->weight=0;
				struct Edge *now=list[i];
				while (now->next!=NULL)
					now=now->next;
				now->next=p;
				
				struct Edge *q=malloc(sizeof(e));
				q->next=NULL;
				q->to=i;
				q->weight=0;
				now=list[j];
				while (now->next!=NULL)
					now=now->next;
				now->next=q;
			}
}

void init(FILE *inn)
{
	int i,d,m,j;
	fscanf(inn,"%d",&n);
	for (i=1;i<=n;i++)
	{
		struct Node *p=malloc(sizeof(a));
		struct Node *q=malloc(sizeof(a));
		fscanf(inn,"%d%d",&d,&m);
		max_poi+=m;
		for (j=1;j<=m;j++)
		{
			fscanf(inn,"%s",q->name);
			fscanf(inn,"%d",&(q->changge));
			q->num=hash(d,j);
			q->train=d;
			
			poi[q->num].changge=q->changge;
			poi[q->num].train=q->train;
			poi[q->num].num=q->num;
			strcpy(poi[q->num].name,q->name);
			
			if (j!=1)
				insert_edge(p,q);
				
			struct Node *t=p;
			p=q;
			q=t;
		}
	}
	find_the_same();
}

void dij()
{
	int i;
	for (i=1;i<=2500;i++)
	{
		dis[i]=3000;
		v[i]=0;
	}
	dis[x0x]=0;
	way[x0x][1]=x0x;
	for (i=1;i<=max_poi;i++)
	{
		int min_s=3000,min_n=0,j;
		for (j=1;j<=2500;j++)
			if (v[j]==0&&poi[j].train!=0&&dis[j]<min_s)
			{
				min_s=dis[j];
				min_n=j;
			}
		v[min_n]=1;
		struct Edge *now=list[min_n];
		for (;now!=NULL;now=now->next)
			if (dis[now->to]> now->weight+dis[min_n])
			{
				dis[now->to]= now->weight+dis[min_n];
				int k;
				for (k=1;way[now->to][k]!=0;k++)
					way[now->to][k]=0;
				for (k=1;way[min_n][k]!=0;k++)
					way[now->to][k]=way[min_n][k];
				way[now->to][k]=now->to;
			}	
	}
}

void solve()
{
	scanf("%s",s1);
	scanf("%s",s2);
	int i;
	for (i=1;i<=2500;i++)
		if (poi[i].train!=0)
		{
			if (strcmp(poi[i].name,s1)==0)
				x0x=i;
			if (strcmp(poi[i].name,s2)==0)
				y0y=i;
		}
		
	dij();
}

void output()
{
	printf("%s",poi[way[y0y][1]].name);
	int k,len=0;
	for (k=2;way[y0y][k]!=0;k++)
	{
		if (strcmp(poi[way[y0y][k]].name , poi[way[y0y][k-1]].name)==0)
		{
			if (len!=0)
			{
				printf("-%d(%d)-%s",poi[way[y0y][k-1]].train,len,poi[way[y0y][k]].name);
				len=0;
			}
			continue;
		}
		len++;
	}
	k=k-1;
	if (len!=0)
	{
		printf("-%d(%d)-%s",poi[way[y0y][k-1]].train,len,poi[way[y0y][k]].name);
	}
}

int main()
{
	FILE *in=fopen("bgstations.txt","r");
	init(in);
	
	solve();
	
	output();
	
	fclose(in);
	return 0;
}
