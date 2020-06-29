#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char inl[203];
int d=0,now_line=0;

struct Nodee
{
	char kuo;
	int hang;
}pa[203],wrong_one;

struct Node
{
	int line;
	char type;
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


void ppop()
{
		struct Node *p=malloc(sizeof(a));
		p=list;
		list=list->next;
		free(p);
}

void solve()                                          //create linked list and examin
{
	int i;
	for (i=1;i<=d;i++)
	{
		struct Node *p=malloc(sizeof(a));
		p->line=pa[i].hang;
		p->type=pa[i].kuo;
		if (p->type=='(')
		{
			p->next=list;
			list=p;
		}
		if (p->type=='{')
		{
			if (list!=NULL&&list->type=='(')
			{
				wrong_one.kuo=list->type;
				wrong_one.hang=list->line;
			}
			else
			{
				p->next=list;
				list=p;
			}
		}
		if (p->type==')')
		{
			if (list==NULL||list->type=='{')
			{
				wrong_one.hang=p->line;
				wrong_one.kuo=p->type;
			}
			else ppop();
		}
		if (p->type=='}')
		{
			if (list==NULL||list->type=='(')
			{
				wrong_one.hang=p->line;
				wrong_one.kuo=p->type;
			}
			else ppop();
		}
	}
	if (list!=NULL)
	{
		wrong_one.hang=list->line;
		wrong_one.kuo=list->type;
	}
}

void pprintf()
{
	int i;
	if (wrong_one.hang==-1&&wrong_one.kuo==1)
		for (i=1;i<=d;i++)
			printf("%c",pa[i].kuo);
	else printf("without maching '%c' at line %d",wrong_one.kuo,wrong_one.hang);
}

int main()
{
	FILE *in=fopen("example.c","r");
	wrong_one.hang=-1;wrong_one.kuo=1;
	while (fgets(inl,203,in))
	{
		now_line++;
		int i;
		for (i=0;i<strlen(inl);i++)
		{
			if (inl[i]=='/'&&i<strlen(inl)-1&&inl[i+1]=='/')    //annotation in one line
				break;
				
			if (inl[i]=='/'&&i<strlen(inl)-1&&inl[i+1]=='*')   //annotation in several lines
			{
				int same=0;
				for (i=i+2;i<strlen(inl)-1;i++)
					if (inl[i]=='*'&&inl[i+1]=='/')
						same=1;
				if (same==0)
					while (fgets(inl,203,in))
					{
						now_line++; 
						int ok=0;
						int j;
						for (j=0;j<strlen(inl);j++)
							if (inl[j]=='*'&&j<strlen(inl)-1&&inl[j+1]=='/')
							{
								ok=1;
								break;
							}
						if (ok==1) break;
					}
			}
				
			if (inl[i]==39)                                    //quotation mark
			{
				i++;
				while(inl[i]!=39)
					i++;
				i++;
			}
				
			if (inl[i]==34)                                    //quotation mark
			{
				i++;
				while (inl[i]!=34)
					i++;
				i++;
			}
			
			if (inl[i]=='('||inl[i]==')'||inl[i]=='{'||inl[i]=='}')
			{
				d++;
				pa[d].hang=now_line;
				pa[d].kuo=inl[i];
			}
		}
	}
	
	solve();
	pprintf();
//	int i;
//	for (i=1;i<=d;i++)
//		printf("%c %d\n",pa[i].kuo,pa[i].hang);
	fclose(in);
	return 0;
}

