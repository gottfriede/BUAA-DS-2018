#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[55],key[30],ge[1130];
int v[30];

void simp_key()
{
	int i,d=0;
	for (i=1;i<=26;i++)
		v[i]=0;
	for (i=0;i<strlen(s);i++)
		if (!v[s[i]-'a'+1])
		{
			d++;
			key[d]=s[i];
			v[s[i]-'a'+1]=1;
		}
	for (i=26;i>=1;i--)
		if (!v[i])
		{
			d++;
			key[d]=i+'a'-1;
		}
}
 
int main()
{
	FILE *in  = fopen("encrypt.txt","r");
	FILE *out = fopen("output.txt","w");
	
	scanf("%s",s);
	simp_key();
	
	while (fgets(ge,1130,in))
	{
		char ch;
		int i;
		for (i=0;i<strlen(ge);i++)
		{
			ch=ge[i];
			if (ch>='a'&&ch<='z')
				ch=key[ch-'a'+1];
			fputc(ch,out);
		}
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
