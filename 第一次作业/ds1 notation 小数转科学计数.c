#include<stdio.h>
#include<math.h>
#include<string.h>
char s[105];

int find_point()
{
	int i;
	for (i=0;i<strlen(s);i++)
		if (s[i]=='.')
			break;
	return i;
}

void solve()
{
	int p=find_point();
	if (p==1&&s[0]!='0')
	{
		int i;
		for (i=0;i<strlen(s);i++)
			printf("%c",s[i]);
		printf("e0");
		return;
	}
	else if (p==1&&s[0]=='0')
	{
		int mi=1,i=p+1;
		while (s[i]=='0')
		{
			i++;
			mi++;
		}
		if (i==strlen(s)-1)
		{
			printf("%ce-%d",s[i],mi);
			return;
		}
		else
		{
			printf("%c.",s[i]);
			for (i=i+1;i<strlen(s);i++)
				printf("%c",s[i]);
			printf("e-%d",mi);
			return;
		}
	}
	else
	{
		int i;
		printf("%c.",s[0]);
		for (i=1;i<strlen(s);i++)
			if (s[i]!='.')
				printf("%c",s[i]);
		printf("e%d",p-1);
		return;
	}
}

int main()
{
 	scanf("%[^\n]",s);
 	solve();
 	return 0;
}
