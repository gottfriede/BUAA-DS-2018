#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char s[103],r[103];

struct Node
{
	char w[103];
	int t;
	struct Node *l;
	struct Node *r;
}a,*tri;

void insert(char *c)
{
	struct Node *p=malloc(sizeof(a));
	p->l=NULL;
	p->r=NULL;
	p->t=1;
	strcpy(p->w,c);
	struct Node *now=tri;
	if (tri==NULL)
	{
		tri=p;
		return;
	}
	while (1)
	{
		if (strcmp(p->w,now->w)<0)
		{
			if (now->l==NULL)
			{
				now->l=p;
				break;
			}
			else now=now->l;
		}
		if (strcmp(p->w,now->w)>0)
		{
			if (now->r==NULL)
			{
				now->r=p;
				break;
			}
			else now=now->r;
		}
		if (strcmp(p->w,now->w)==0)
		{
			now->t++;
			break;
		}
	}
}

void find(struct Node *root)
{
	if (root==NULL) return;
	find(root->l);
	printf("%s %d\n",root->w,root->t);
	find(root->r);
}

void output()
{
	printf("%s",tri->w);
	if (tri->r!=NULL) printf(" %s",tri->r->w);
	if (tri->r!=NULL&&tri->r->r!=NULL) printf(" %s",tri->r->r->w);
	printf("\n");
	find(tri);
}

int main()
{
	FILE *in=fopen("article.txt","r");
	while (fscanf(in,"%s",s)!=EOF)
	{
		int i,lth=strlen(s),ans=0;
		for (i=0;i<lth;i++)
		{
			if (s[i]>='A'&&s[i]<='Z')
				s[i]=s[i]-'A'+'a';
			if (s[i]>='a'&&s[i]<='z')
			{
				r[ans]=s[i];
				ans++;
			}
			else if (ans!=0)
			{
				r[ans]='\0';
				insert(r);
				ans=0;
			}
			else if (ans==0)
				continue;
		}
		if (ans!=0)
		{
			r[ans]='\0';
			insert(r);
			ans=0;
		}
	}
	output();
}

