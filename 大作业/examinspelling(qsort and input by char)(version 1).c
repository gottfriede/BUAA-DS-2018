/*
-----------------------------------------------------------------
Username : Gottfried
Ways of sort : qsort
Ways of input : char by char 
Result : AC
Average time : 1.32s 
Last submission : 2019.4.15
-----------------------------------------------------------------
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int tri[2000003][27];
int val[2000003];
int sz,tot_loc=-1,wown=0;
char inn[2000007];
char wor[1003];

struct Node
{
	int t,w;
	char wo[203];
}wow[2000003];     //wow can not be smaller, otherwise it will be SIG

int idx(char c)
{
	return c-'a';
}

void insert(char *s)         //build the Tri using the dictionary
{
	int u=0,n=strlen(s),i;
	for (i=0;i<n&&s[i]!='\n'&&s[i]!='\r';i++)  //remove the '\n' and '\r' input by 'fgets' 
	{                                          //quite important
		int c=idx(s[i]);
		if (!tri[u][c])
		{
			memset(tri[sz],0,sizeof(tri[sz]));
			tri[u][c]=sz++;
		}
		u=tri[u][c];
	}
	val[u]=1;                //val=1 means there is a word here 
}

void findd(char *s,int loc)
{
	int u=0,n=strlen(s),i;
	for (i=0;i<n;i++)
	{
		int c=idx(s[i]);
		if (!tri[u][c])                     //can not be found 
		{
			wow[wown].w=loc;
			strcpy(wow[wown].wo,s);
			wown++;
			return;
		}
		u=tri[u][c];
	}
	if (val[u]!=1)                          //there is not a word here
	{
		wow[wown].w=loc;
		strcpy(wow[wown].wo,s);
		wown++;
		return;
	}	
}

void process_find(FILE *in)
{
	int noww=0,locc=tot_loc;
	char ch;
	while (fscanf(in,"%c",&ch)!=EOF) 
	{
		if (ch!='\r') tot_loc++;              //remove the '\r' 
		if (ch>='A'&&ch<='Z')
		{
			if (noww==0)
				locc=tot_loc;
			wor[noww]=ch-'A'+'a';
			noww++;
		}
		else if (ch>='a'&&ch<='z')
		{
			if (noww==0)
				locc=tot_loc;
			wor[noww]=ch;
			noww++;
		}                     //lowercase and be ready to search in the Tri
		else if (noww!=0) 
		{
			wor[noww]='\0';
			findd(wor,locc);
			strcpy(wor,"\0");
			noww=0;
		}
	}
}

int cmp(const void *a,const void *b)         //string > location
{
	struct Node *c=(struct Node *)a;
	struct Node *d=(struct Node *)b;
	if (strcmp(c->wo,d->wo)==0)
		return c->w - d->w;
	else return strcmp(c->wo,d->wo);
}

int cmp2(const void *a,const void *b)        //times > string > location 
{
	struct Node *c=(struct Node *)a;
	struct Node *d=(struct Node *)b;
	if (c->t!=d->t)
		return d->t - c->t;
	if (strcmp(c->wo,d->wo)==0)
		return c->w - d->w;
	return strcmp(c->wo,d->wo);
}

void sort_combine()
{
	qsort(wow,wown,sizeof(wow[0]),cmp);      //sort once using cmp1 
	
	int i;
	for (i=0;i<wown;i++)
	{
		int ori_i=i,p;
		while (i<wown-1&&strcmp(wow[i].wo,wow[i+1].wo)==0) //calculate and record times
			i++;
		for (p=0;p<i-ori_i+1;p++)
			wow[ori_i+p].t=i-ori_i+1;
	}
	
	qsort(wow,wown,sizeof(wow[0]),cmp2);     //sort twice using cmp2
}

void init()                                     //init the Tri 
{
	sz=1;
	memset(tri[0],0,sizeof(tri[0]));
}

int main()
{
	FILE *ind=fopen("dictionary.txt","r");
	FILE *ina=fopen("article.txt","r");
	FILE *out=fopen("misspelling.txt","w");
	init();
	
	while (fgets(inn,100007,ind))             //input the dictionary and lowercase
	{
		int i;
		for (i=0;i<strlen(inn);i++)
			if (inn[i]>='A'&&inn[i]<='Z')
				inn[i]=inn[i]-'A'+'a';
		insert(inn);	                      //insert into the Tri 
	}
	
	process_find(ina);                        //input and process the article 
	
	sort_combine();
	
	int i;                                                  //output
	fprintf(out,"%s %d %d",wow[0].wo,wow[0].t,wow[0].w);
	for (i=1;i<wown;i++)
	{
		if (strcmp(wow[i-1].wo,wow[i].wo)!=0)
			fprintf(out,"\n%s %d %d",wow[i].wo,wow[i].t,wow[i].w);
		else fprintf(out," %d",wow[i].w);
	}
	fprintf(out,"\n");
	
	fclose(ind);
	fclose(ina);
	fclose(out);
	return 0;
}
