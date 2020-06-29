#include<stdio.h>
#include<string.h>
char s[1000003];

int sam(char a,char b)
{
	if (a>='0'&&a<='9'&&b>='0'&&b<='9') return 1;
	if (a>='a'&&a<='z'&&b>='a'&&b<='z') return 1;
	if (a>='A'&&a<='Z'&&b>='A'&&b<='Z') return 1;
	return 0;
}

int main()
{
	scanf("%s",s);
	int i;
	for (i=0;i<=strlen(s);i++)
	{
		if (s[i]=='-')
		{
			if (i>=1&&i<=strlen(s)-2&&sam(s[i-1],s[i+1]))
			{
				char c;
				for (c=s[i-1]+1;c<s[i+1];c++)
					printf("%c",c);
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	return 0;
}


