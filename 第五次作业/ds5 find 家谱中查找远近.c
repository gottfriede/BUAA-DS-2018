#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char s1[23],s2[23],s3[23],s4[23],s5[23];

struct Node
{
	char na[23];
	struct Node *l;
	struct Node *r;
	struct Node *p;
}a,*tri;

struct Node *get_loc(struct Node *x,char *s)
{
	if (x==NULL)
		return NULL;
	if (strcmp(x->na,s)==0)
		return x;
	else
	{
		struct Node *lres=get_loc(x->l,s);
		struct Node *rres=get_loc(x->r,s);
		if(lres==NULL&&rres==NULL)
			return NULL;
		else return (lres!=NULL)? lres :rres;
	}
}

void insert(char *s1,char *s2,char *s3)
{
	struct Node *now=get_loc(tri,s1);
	if (now==NULL)
		now=malloc(sizeof(a));
	strcpy(now->na,s1);
	if (strcmp(s2,"NULL")!=0)
	{
		struct Node *pp=malloc(sizeof(a));
		pp->l=NULL;
		pp->r=NULL;
		strcpy(pp->na,s2);
		pp->p=now;
		now->l=pp;
	}
	if (strcmp(s3,"NULL")!=0)
	{
		struct Node *qq=malloc(sizeof(a));
		qq->l=NULL;
		qq->r=NULL;
		strcpy(qq->na,s3);
		qq->p=now;
		now->r=qq;
	}
	if (tri==NULL)
	{
		tri=now;
		tri->p=NULL;
	}
}

void init()
{
	FILE *in=fopen("in.txt","r");
	int n,i;
	fscanf(in,"%d",&n);
	for (i=1;i<=n;i++)
	{
		fscanf(in,"%s%s%s",s1,s2,s3);
		insert(s1,s2,s3);
	}
}

int get_dp(struct Node *x)
{
	return (x->p==NULL)? 1 : 1+get_dp(x->p);
}

void output()
{
	scanf("%s%s",s4,s5);
	struct Node *a1=get_loc(tri,s4);
	struct Node *a2=get_loc(tri,s5);
	int dp1=get_dp(a1);
	int dp2=get_dp(a2);
	if (dp1==dp2)
	{
		while (strcmp(a1->na,a2->na)!=0)
		{
			a1=a1->p;
			a2=a2->p;
		}
		int dp3=get_dp(a1);
		printf("%s %s %d\n",a1->na,s4,dp1-dp3);
		printf("%s %s %d\n",a1->na,s5,dp2-dp3);
	}
	if (dp1<dp2)
		printf("%s %s %d\n",s5,s4,dp2-dp1);
	if (dp1>dp2)
		printf("%s %s %d\n",s4,s5,dp1-dp2);
}

int main()
{
	init();
	output();
	return 0;
}
