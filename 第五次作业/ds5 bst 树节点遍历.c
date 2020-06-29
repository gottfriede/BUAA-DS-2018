#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Node
{
	int data;
	struct Node *l,*r;
}a,*tri;

void insert(int x)
{
	struct Node *now=tri;
	struct Node *p=malloc(sizeof(a));
	p->data=x;
	p->l=NULL;
	p->r=NULL;
	if (now==NULL)
	{
		tri=p;
		return;
	}
	while (1)
	{
		if (x<now->data)
		{
			if (now->l==NULL)
			{
				now->l=p;
				break;
			}
			else now=now->l;
		}
		else if (x>=now->data)
		{
			if (now->r==NULL)
			{
				now->r=p;
				break;
			}
			else now=now->r;
		}
	}
}

void search(struct Node *p,int x)
{
	if (p->l==NULL&&p->r==NULL)
		printf("%d %d\n",p->data,x);
	else
	{
		if(p->l!=NULL)
			search(p->l,x+1);
		if (p->r!=NULL)
			search(p->r,x+1);
	}
}

int main()
{
	int n,i,x;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	search(tri,1);
	return 0;
}
