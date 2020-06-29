#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[517],s3[517];
int n;
struct Node
{
	char c[517];
	struct Node *next;
}a,*list;

struct Nodee
{
	int op,pos;
	char s2[517];
}pri[11];

void in_vert()                 //反转链表 
{
	struct Node *p,*q,*r;
	p=malloc(sizeof(a));
	q=malloc(sizeof(a));
	r=malloc(sizeof(a));
	p=list;
	int i=1;
	while (i<n+1)
	{
		p=p->next;
		i++;
	}
	p->next=NULL;
	p=list;
	q=NULL;
	while (p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	list=q;
}

void get_ori(int x)            //找到原始所有状态 
{
	struct Node *p=malloc(sizeof(a));
	if (pri[x].op==1)
	{
		int i,len=strlen(pri[x].s2);
		for (i=pri[x].pos;i<=strlen(s)-len;i++)
			s[i]=s[i+len];
	}
	if (pri[x].op==2)
	{
		int i,len=strlen(pri[x].s2);
		for (i=strlen(s)+len;i>=pri[x].pos+len;i--)
			s[i]=s[i-len];
		for (i=pri[x].pos;i<pri[x].pos+len;i++)
			s[i]=pri[x].s2[i-pri[x].pos];
	}
	strcpy(p->c,s);
	p->next=list;
	list=p;
}

void init()
{
	int i,op,pos;
	scanf("%[^\n]",s);
	scanf("%d",&n);
	
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&pri[i].op,&pri[i].pos);
		scanf("%s",pri[i].s2);
	}
	list=malloc(sizeof(a));
	strcpy(list->c,s);
	for (i=n;i>=1;i--)
		get_ori(i);
	in_vert();
}

void solve(int x)              //之后进行的操作 
{
	strcpy(s,list->c);
	if (x==1)                  //插入 
	{
		int lo,i;
		scanf("%d",&lo);
		scanf("%s",s3);
		int len=strlen(s3);
		for (i=strlen(s)+len;i>=lo+len;i--)
			s[i]=s[i-len];
		for (i=lo;i<lo+len;i++)
			s[i]=s3[i-lo];
	}
	if (x==2)                  //删除 
	{
		int lo,i,nn;
		scanf("%d%d",&lo,&nn);
		if (lo+nn>strlen(s))
			s[lo]='\0';
		else for (i=lo;i<=strlen(s)-nn&&s[i+nn-1]!='\0';i++)
			s[i]=s[i+nn];
	}
	if (x==3)                   //撤销 
		if (list->next!=NULL)
			list=list->next;
	if (x!=3)
	{
		struct Node *p=malloc(sizeof(a));
		strcpy(p->c,s);
		p->next=list;
		list=p;
	}
}

void printt()
{
	while (list!=NULL)
	{
		printf("%s\n",list->c);
		list=list->next;
	}
}

int main()
{
	init();
	int opp;
	while (scanf("%d",&opp)&&opp!=-1)
		solve(opp);
	printf("%s",list->c);
	return 0;
}
