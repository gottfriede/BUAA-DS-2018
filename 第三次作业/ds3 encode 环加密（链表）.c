#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
char c[203];
int v[203];
char m[137]={0};

struct Node
{
	char ch;
	struct Node *next;
}a,*list;

void delete_same()
{
	int i,j;
	for (i=0;i<strlen(c);i++)
	{
		if (c[i]<32||c[i]>126)
			continue;
		v[c[i]]=1;
		for (j=i+1;j<strlen(c);j++)
		if (c[j]==c[i])
		{
			int k;
			for (k=j;k<strlen(c);k++)
				c[k]=c[k+1];
			j--;
		}
	}
		
}

void create()
{
	scanf("%[^\n]",c);
	delete_same();
	int i;
	struct Node *now=list;
	for (i=0;i<strlen(c);i++)
	{
		struct Node *p=malloc(sizeof(a));
		p->ch=c[i];
		p->next=list;
		if (list==NULL)
			list=p;
		else now->next=p;
		now=p;
	}
	for (i=32;i<=126;i++)
		if (!v[i])
		{
			struct Node *p=malloc(sizeof(a));
			p->ch=i;
			p->next=list;
			if (list==NULL)
				list=p;
			else now->next=p;
			now=p;
		}
}

void get_map()
{
	struct Node *now=list;
	while (now->next!=list)
		now=now->next;
	char delet=list->ch,delet1=list->ch;
	now->next=list->next;
	list=now;
	int i;
	for (i=1;i<=(int)(delet)-1;i++)
		now=now->next;
	m[delet]=now->next->ch;
	while (list->next!=list)
	{
		delet=now->next->ch;
		now->next=now->next->next;
		list=now;
		for (i=1;i<=(int)(delet)-1;i++)
			now=now->next;
		m[delet]=now->next->ch;
	}
	for (i=32;i<=126;i++)
		if (!m[i])
			m[i]=delet1;
}

int main()
{
	FILE *in =fopen("in.txt","r");
	FILE *out=fopen("in_crpyt.txt","w");
	create();
	get_map();
	char ch;
	while (~fscanf(in,"%c",&ch))
	{
		if (ch>=32&&ch<=126)
			fprintf(out,"%c",m[ch]);
		else fprintf(out,"%c",ch);
	}
	fclose(in);
	fclose(out);
	return 0;
}
