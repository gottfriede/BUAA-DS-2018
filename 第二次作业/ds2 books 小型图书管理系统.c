#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n=1;
struct Node
{
	char name[55];
	char author[25];
	char publish[35];
	char date[15];
}b[1003];

void choose_sort(int lth)
{
	int i,j;
	for (i=1;i<=lth;i++)
		for (j=1;j<i;j++)
			if (strcmp(b[i].name,b[j].name)<0)
			{
				struct Node tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
			}
}

void ppush(int lth)
{
	struct Node t;
	scanf("%s",t.name);
	scanf("%s",t.author);
	scanf("%s",t.publish);
	scanf("%s",t.date);
	int i=1;
	while (strcmp(t.name,b[i].name)>0&&i<=lth)
		i++;
	int j;
	for (j=n+1;j>i;j--)
		b[j]=b[j-1];
	b[i]=t;
	n++;
	return ;
}

void ffind(int lth)
{
	char s[55];
	scanf("%s",s);
	int i;
	for (i=1;i<=lth;i++)
		if (strstr(b[i].name,s)!=NULL)
			printf("%-50s%-20s%-30s%-10s\n",b[i].name,b[i].author,b[i].publish,b[i].date);
	return ;
}

void ddelet(int lth)
{
	char s[55];
	scanf("%s",s);
	int i;
	for (i=1;i<=lth;i++)
		if (strstr(b[i].name,s)!=NULL)
		{
			int j;
			for (j=i;j<=lth;j++)
				b[j]=b[j+1];
			n--;
			lth--;
			i--;
		}
	return ;
}

void pprint(int lth,FILE *out)
{
	int i;
	for (i=1;i<=lth;i++)
		fprintf(out,"%-50s%-20s%-30s%-10s\n",b[i].name,b[i].author,b[i].publish,b[i].date);
}

int main()
{
	FILE *in  = fopen("books.txt","r");
	FILE *out = fopen("ordered.txt","w");
	
	while (~fscanf(in,"%s",b[n].name))
	{
		fscanf(in,"%s",b[n].author);
		fscanf(in,"%s",b[n].publish);
		fscanf(in,"%s",b[n].date);
		n++;
	}
	n--;
	
	choose_sort(n);
	
	int a;
	while (~scanf("%d",&a))
	{
		if (a==1) ppush(n);
		if (a==2) ffind(n);
		if (a==3) ddelet(n);
		if (a==0)
		{
			pprint(n,out);
			break;
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
