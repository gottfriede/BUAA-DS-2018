#include<stdio.h>
#include<string.h>
char a[10003],b[10003];
int x[10003],y[10003],ans[10003];

void zhuan(char c[],int d[])
{
	int i=0,j=0;
	while (c[i]=='0')
	{
		i++;j++;
	}
	d[0]=strlen(c)-j;
	for (i=1;i<=d[0];i++)
		d[i]=c[strlen(c)-i]-'0';
}

int com(int c[],int d[])
{
	if (c[0]>d[0]) return 1;
	if (c[0]<d[0]) return 0;
	int i=c[0];
	for (;i>=1;i--)
	{
		if (c[i]>d[i]) return 1;
		if (c[i]<d[i]) return 0;
	}
	return 1;	
}

void jian(int c[],int d[])
{
	int i,j;
	for (i=d[0]+1;i<=c[0];i++)
		d[i]=0;
	for (i=1;i<=c[0];i++)
	{
		c[i]-=d[i];
		while (c[i]<0)
		{c[i+1]--;c[i]+=10;}
	}
	for (i=c[0];i>=1;i--)
		if (c[i])
			break;
	if (i==0) printf("0");
	else for (j=i;j>=1;j--)
		printf("%d",c[j]);
}

int main()
{
	int i,j;
	scanf("%s",a);
	scanf("%s",b);
	zhuan(a,x);
	zhuan(b,y);
	if (com(x,y)) jian(x,y);
	else {printf("-");jian(y,x);}
	return 0;
}

