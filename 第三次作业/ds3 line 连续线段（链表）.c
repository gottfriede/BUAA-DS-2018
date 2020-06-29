#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
int n;
struct Node
{
	int x1,y1,x2,y2;
	struct Node *next;
}line,*list[103];

void create()
{
	int i;
	for (i=1;i<=n;i++)
	{
		list[i]=malloc(sizeof(line));
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		list[i]->next=NULL;
		list[i]->x1=x1;
		list[i]->x2=x2;
		list[i]->y1=y1;
		list[i]->y2=y2;
	}
}

void solve()
{
	int i,j;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (i!=j)
			{
				if (list[i]->x1==list[j]->x2&&list[i]->y1==list[j]->y2)
					list[j]->next=list[i];
				else if (list[i]->x2==list[j]->x1&&list[i]->y2==list[j]->y1)
					list[i]->next=list[j];
			}
}

void get_max()
{
	int i,maxn=-1,mx,my;
	for (i=1;i<=n;i++)
	{
		int ans=1;
		struct Node *now=list[i];
		while (now->next!=NULL)
		{
			now=now->next;
			ans++;
		}
		if (ans>maxn)
		{
			maxn=ans;
			mx=list[i]->x1;
			my=list[i]->y1;
		}
	}
	printf("%d %d %d",maxn,mx,my);
}

int main()
{
	scanf("%d",&n);
	create();
	solve();
	get_max();
	return 0;
}
