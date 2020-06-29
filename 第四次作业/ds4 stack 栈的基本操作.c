#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *next;
}a,*list;

int get_lenth()
{
	struct Node *p=malloc(sizeof(a));
	p=list;
	int ans=0;
	while (p!=NULL)
	{
		ans++;
		p=p->next;
	}
	return ans;
}

void ppush(int x)
{
	if (get_lenth()==100)
		printf("error ");
	else
	{
		struct Node *p=malloc(sizeof(a));
		p->data=x;
		p->next=list;
		list=p;
	}
}

void popp()
{
	if (get_lenth()==0)
		printf("error ");
	else 
	{
		printf("%d ",list->data);
		struct Node *p=malloc(sizeof(a));
		p=list;
		list=list->next;
		free(p);
	}
}

int main()
{
	int switchh;
	while (~scanf("%d",&switchh))
	{
		if (switchh==-1)
			break;
		if (switchh==1)
		{
			int num;
			scanf("%d",&num);
			ppush(num);
		}
		if (switchh==0)
			popp();
	}
	return 0;
}

