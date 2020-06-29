#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char s[1003];

struct Node
{
	char ope;
	struct Node *next;
}p,*plist;

struct Nodee
{
	int data;
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

void qpush(int x)
{
	struct Nodee *q=malloc(sizeof(q));
	q->data=x;
	q->nextt=qlist;
	qlist=q;
}

int qpop()
{
	struct Nodee *q=malloc(sizeof(q));
	q=qlist;
	qlist=qlist->nextt;
	int x=q->data;
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
	if (x=='+') qpush(qpop()+qpop());
	if (x=='-')
	{
		int a=qpop(),b=qpop();
		qpush(b-a);
	}
	if (x=='*') qpush(qpop()*qpop());
	if (x=='/') 
	{
		int a=qpop(),b=qpop();
		qpush(b/a);
	}
	if (x=='%') 
	{
		int a=qpop(),b=qpop();
		qpush(b%a);
	}
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
			int ans=s[i]-'0',j;
			for (j=i+1;s[j]>='0'&&s[j]<='9';j++)
			{
				ans*=10;
				ans+=s[j]-'0';
			}
			qpush(ans);
			i=j-1;
		}
		else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'||s[i]=='('||s[i]==')')
			ppush(s[i]);
	}
}

int main()
{
	scanf("%[^\n]",s);
	init();
	printf("%d\n",qpop());
	return 0;
}
