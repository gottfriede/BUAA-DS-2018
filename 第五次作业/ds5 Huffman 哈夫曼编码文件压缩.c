#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int code[150][128];
int pc[128];
int ans;
struct Node
{
	char chh;
	int ti;
}zi[150];

struct Nodee
{
	struct Node fu;
	struct Nodee* l;
	struct Nodee* r;
}Btree,*tri;

struct Nodeee
{
	struct Nodee* point;
	struct Nodeee* next;
}a,*list,*tail;

void init()
{
	int i;
	for (i=1;i<=127;i++)
	{
		zi[i].chh=(char)i;
		zi[i].ti=0;
	}
	zi[0].ti=1;
	list=NULL;
	tail=NULL;
	tri=NULL;
}

int cmp(const void *a,const void *b)
{
	struct Node *c=(struct Node *)a;
	struct Node *d=(struct Node *)b;
	if (c->ti==d->ti)
		return c->chh - d->chh;
	return c->ti - d->ti;
}

void insert_to_line(struct Nodee *x)
{
	struct Nodeee *now=malloc(sizeof(a));
	now->point=x;
	now->next=NULL;
	if (list==NULL)
	{
		list=now;
		tail=now;
		return;
	}
	tail->next=now;
	tail=tail->next;
}

void build_tree()
{
	int i;
	for (i=0;i<=127;i++)
		if (zi[i].ti>0)
		{
			struct Nodee *p=malloc(sizeof(Btree));
			p->fu=zi[i];
			p->l=NULL;
			p->r=NULL;
			insert_to_line(p);
		}
	
	while (list!=tail)
	{
		struct Nodeee *n1=list;
		struct Nodeee *n2=list->next;
		struct Nodeee *neww=malloc(sizeof(a));
		struct Nodee *now=malloc(sizeof(Btree));
		now->l=n1->point;
		now->r=n2->point;
		(now->fu).ti=(now->l->fu).ti+(now->r->fu).ti;
		neww->point=now;
		neww->next=NULL;
		
		struct Nodeee *pai=list;
		while (pai->next!=NULL&&(pai->next->point->fu).ti<=(neww->point->fu).ti)
			pai=pai->next;
		if (pai->next==NULL)
		{
			tail->next=neww;
			tail=tail->next;
		}
		else
		{
			neww->next=pai->next;
			pai->next=neww;
		}
		
		list=list->next->next;
	}
	tri=list->point;
}

void get_huffman_code(struct Nodee *x,int loc)
{
	if (x->l==NULL&&x->r==NULL)
	{
		int i;
		for (i=0;i<loc;i++)
		{
			code[(x->fu).chh][0]=loc;
			code[(x->fu).chh][i+1]=pc[i];
		}
	}
	if (x->l!=NULL)
	{
		pc[loc]=0;
		loc++;
		get_huffman_code(x->l,loc);
		loc--;
	}
	if (x->r!=NULL)
	{
		pc[loc]=1;
		loc++;
		get_huffman_code(x->r,loc);
		loc--;
	}
}

void fuck_output()
{
	FILE *in=fopen("output.txt","r");
	int ru[9],i=0;
	char c;
	while (c=fgetc(in))
	{
		if (c==EOF) break;
		i++;
		ru[i]=c-'0';
		if (i==8)
		{
			int sum1=((ru[1]*2+ru[2])*2+ru[3])*2+ru[4];
			if (sum1!=0)
				printf("%x",sum1);
			int sum2=((ru[5]*2+ru[6])*2+ru[7])*2+ru[8];
				printf("%x",sum2);
			i=0;
		}
	}
}

int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	init();
	char ch;
	while (ch=fgetc(in))
	{
		if (ch==EOF) break;
		if (ch=='\n') continue;
		zi[ch].ti++;
	}

	qsort(zi,128,sizeof(zi[0]),cmp);
	
	build_tree();
	
	get_huffman_code(tri,0);
	
	fclose(in);
	FILE *inn=fopen("input.txt","r");
	ans=code[0][0];
	while (ch=fgetc(inn))
	{
		if (ch==EOF) break;
		if (ch=='\n') continue;
		int i;
		
		ans+=code[ch][0];
		ans%=8;
		for (i=1;i<=code[ch][0];i++)
			fprintf(out,"%d",code[ch][i]);
	}
	int i;
	for (i=1;i<=code[0][0];i++)
		fprintf(out,"%d",code[0][i]);
	for (1;ans!=0&&ans<8;ans++)
			fprintf(out,"0");
	fclose(inn);
	fclose(out);
	
	fuck_output();
	
	return 0;
}
