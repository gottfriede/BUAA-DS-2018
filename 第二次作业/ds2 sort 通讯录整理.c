#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int n;

struct Node
{
	char name[25];
	char tel[15];
	int num;
}a[105];

void init()
{
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i++)
	{
		scanf("%s",a[i].name);
		scanf("%s",a[i].tel);
		a[i].num=1;
		int j;
		for (j=1;j<i;j++)
			if (a[j].num>0&&strcmp(a[i].name,a[j].name)==0)
			{
				if (strcmp(a[i].tel,a[j].tel)==0)
					{a[i].num=0;break;}
				else a[i].num++;
			}
	}
	for (i=1;i<=n;i++)
		if (a[i].num>1)
		{
			int lth=strlen(a[i].name);
			(a[i].name)[lth]='_';
			(a[i].name)[lth+1]=a[i].num-1+'0';
			(a[i].name)[lth+2]='\0';
		}
}

void choose_sort()
{
	int i,j;
	for (i=1;i<=n;i++)
		for (j=1;j<i;j++)
			if (a[i].num>0&&a[j].num>0)
			{
				if (strcmp(a[i].name,a[j].name)<0)
				{
					struct Node tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
			}
}

void stddout()
{
	int i;
	for (i=1;i<=n;i++)
		if (a[i].num>0)
			printf("%s %s\n",a[i].name,a[i].tel);
}

int main()
{
	init();
	choose_sort();
	stddout();
	return 0;
}
