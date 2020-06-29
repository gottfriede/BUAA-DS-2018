#include<stdio.h>
#include<math.h>
#include<string.h>
char s[100003],c[100003];
int a[100003];
int x=0,y=0;

int yxj(char ch)
{
	if (ch=='*'||ch=='/') return 2;
	if (ch=='+'||ch=='-') return 1;
}

void solve(char ch)
{
		c[y]=ch;
		y++;
	while (y>=2&&yxj(c[y-1])<=yxj(c[y-2]))
	{
		char t=c[y-2];
		c[y-2]=c[y-1];
		y--;
		if (t=='+') a[x-2]=a[x-2]+a[x-1];
		if (t=='-') a[x-2]=a[x-2]-a[x-1];
		if (t=='*') a[x-2]=a[x-2]*a[x-1];
		if (t=='/') a[x-2]=a[x-2]/a[x-1];
		x--;
	}
}

int main()
{
	int i;
	scanf("%[^\n]",s);
	for (i=0;i<strlen(s);i++)
	{
		if (s[i]==' ') continue;
		if (s[i]=='=')
		{
			while (y>=1)
			{
				char t=c[y-1];
				y--;
				if (t=='+') a[x-2]=a[x-2]+a[x-1];
				if (t=='-') a[x-2]=a[x-2]-a[x-1];
				if (t=='*') a[x-2]=a[x-2]*a[x-1];
				if (t=='/') a[x-2]=a[x-2]/a[x-1];
				x--;
			}
		}
		if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
			solve(s[i]);
		if (s[i]>='0'&&s[i]<='9')
		{
			int ans=s[i]-'0';
			i++;
			while (s[i]>='0'&&s[i]<='9')
			{
				ans=ans*10+s[i]-'0';
				i++;
			}
			a[x]=ans;
			x++;
			i--;	
		}
	}
	printf("%d",a[0]);
	return 0;
}
