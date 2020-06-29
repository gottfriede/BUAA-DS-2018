#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char a[4005][23];
char b[23];
int alpha_end[27];
int max_words;
struct Node
{
	char s[23];
	struct Node *next;
}node,*list[3003];

void order_find()
{
	int i;
	for (i=0;i<max_words;i++)
	{
		int dis=strcmp(a[i],b);
		if (dis==0)
		{
			printf("1 %d\n",i+1);
			break;
		}
		if (dis>0)
		{
			printf("0 %d\n",i+1);
			break;
		}
	}	
}

void binary_find(int l,int r)
{
	int mid,ans=0;
	while (l<=r)
	{
		ans++;
		mid=(l+r)/2;
		int dis=strcmp(a[mid],b);
		if (dis==0)
		{
			printf("1 %d\n",ans);
			return;
		}
		if (dis<0)
			l=mid+1;
		if (dis>0)
			r=mid-1;
	}
	printf("0 %d\n",ans);
}

void insert(int x,char *ch)
{
	struct Node *p=malloc(sizeof(node));
	p->next=NULL;
	strcpy(p->s,ch);
	if(list[x]==NULL)
		list[x]=p;
	else 
	{
		struct Node *now=list[x];
		while (now->next!=NULL)
			now=now->next;
		now->next=p;
	}
}

unsigned int hash(char *str)
{
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
              h = 37*h + *p;
       return h % 3001;
}

void build_hash()
{
	int i;
	for (i=0;i<max_words;i++)
	{
		int h=hash(a[i]);
		insert(h,a[i]);
	}
}

void hash_find()
{
	int h=hash(b),ans=0;
	struct Node *now=list[h];
	while (now!=NULL)
	{
		ans++;
		int dis=strcmp(b,now->s);
		if (dis==0)
		{
			printf("1 %d\n",ans);
			return;
		}
		if (dis<0)
		{
			printf("0 %d\n",ans);
			return;
		}
		now=now->next;
	}
	printf("0 %d\n",ans);
}

int main()
{
	FILE *in=fopen("dictionary3000.txt","r");
	int i=0,d;
	while (fscanf(in,"%s",a[i])!=EOF)
	{
		alpha_end[a[i][0]-'a'+1]=i;
		i++;
	}
	max_words=i;
			
	scanf("%s",b);
	scanf("%d",&d);
	if (d==1) 
		order_find();
	if (d==2)
		binary_find(0,max_words-1);
	if (d==3)
	{
		if (alpha_end[b[0]-'a'+1]==0)
			printf("0 0\n");
		else
		{
			int xl=b[0]-'a';
			while (alpha_end[xl]==0&&xl>0)
				xl--;
			binary_find(alpha_end[xl]+1,alpha_end[b[0]-'a'+1]);
		}
	}
		
	if (d==4)
	{
		build_hash();
		hash_find();
	}
	fclose(in);
	return 0;
}



