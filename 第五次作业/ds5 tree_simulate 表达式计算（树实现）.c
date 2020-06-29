#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char s[1003];

struct Node
{
	char ope;
	struct Node *next;
}p,*plist;

struct Nodeee
{
	int num;
	int typ;
	struct Nodeee *l,*r;
	int ans; 
}a,*tri;

struct Nodee
{
	struct Nodeee *data;
	struct Nodee *nextt;
}q,*qlist;

int is_empty()
{
	return plist==NULL;
}

int pri(char x)
{
	if (x==')') return 0;
	if (x=='+'||x=='-') return 1;
	if (x=='*'||x=='/'||x=='%') return 2;
	if (x=='(') return 0;
}

void qpush(struct Nodeee *x)
{
	struct Nodee *q=malloc(sizeof(q));
	q->data=x;
	q->nextt=qlist;
	qlist=q;
}

struct Nodeee* qpop()
{
	struct Nodee *q=malloc(sizeof(q));
	q=qlist;
	qlist=qlist->nextt;
	struct Nodeee* x=q->data;
	return x;
}

char ppop()
{
	struct Node *p=malloc(sizeof(p));
	p=plist;
	plist=plist->next;
	char x=p->ope;
	return x;
}

void simulate(char x)
{
	struct Nodeee *t=malloc(sizeof(a));
	t->typ=0;
	t->num=(int)x;
	t->r=qpop();
	t->l=qpop();
	if (x=='+')
		t->ans=t->l->ans+t->r->ans;
	if (x=='-')
		t->ans=t->l->ans-t->r->ans;
	if (x=='*')
		t->ans=t->l->ans*t->r->ans;
	if (x=='/')
		t->ans=t->l->ans/t->r->ans;
	if (x=='%')
		t->ans=t->l->ans%t->r->ans;
	qpush(t);
	tri=t;
}

void ppush(char x)
{
	struct Node *p=malloc(sizeof(p));
	p->ope=x;
	if (x==')')
	{
		while (plist->ope!='(')
			simulate(ppop());
		ppop();
	}
	else if (x=='(')
	{
		p->next=plist;
		plist=p;
	}
	else 
	{
		while ( (!is_empty()) && pri(x)<=pri(plist->ope) )
			simulate(ppop());
		p->next=plist;
		plist=p;
	}
}

void init()
{
	int i;
	for (i=0;i<strlen(s);i++)
	{
		if (s[i]==' ') continue;
		else if (s[i]=='=')
			while (!is_empty())
				simulate(ppop());
		else if (s[i]>='0'&&s[i]<='9')
		{
			int anss=s[i]-'0',j;
			for (j=i+1;s[j]>='0'&&s[j]<='9';j++)
			{
				anss*=10;
				anss+=s[j]-'0';
			}
			struct Nodeee *t=malloc(sizeof(a));
			t->num=anss;
			t->typ=1;
			t->l=NULL;
			t->r=NULL;
			t->ans=anss;
			qpush(t);
			i=j-1;
		}
		else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'||s[i]=='('||s[i]==')')
			ppush(s[i]);
	}
}

void output(struct Nodeee *t,int x)
{
	if (x==2)
		return;
	if (t->typ==0)
		printf("%c ",t->num);
	else printf("%d ",t->num);
	output(t->l,x+1);
	output(t->r,x+1);
}

int main()
{
	scanf("%[^\n]",s);
	init();
	
	output(tri,0);
	printf("\n%d\n",tri->ans);
	return 0;
}
