#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char be_re[103],re[103],now[1103];
char be_re0[103],re0[103],now0[1103];

void loower(char c[])
{
	int i;
	for (i=0;i<strlen(c);i++)
		if (c[i]>='A'&&c[i]<='Z')
			c[i]=c[i]-'A'+'a';
}

int main()
{
	FILE *in  = fopen("filein.txt","r");
	FILE *out = fopen("fileout.txt","w");
	
	scanf("%s",be_re);
	scanf("%s",re);
	strcpy(be_re0,be_re);
	strcpy(re0,re);
	loower(be_re);
	loower(re);
	while (fgets(now,1103,in))
	{
		int i;
		strcpy(now0,now);
		loower(now);
		for (i=0;i<strlen(now);i++)
		{
			if (now[i]==be_re[0])
			{
				int j,d=i;
				for (j=0;j<strlen(be_re);j++,i++)
					if (now[i]!=be_re[j])
						break;
				if (j==strlen(be_re))
				{
					fprintf(out,"%s",re0);
					i--;
				}
					
				else
				{
					i=d;
					fprintf(out,"%c",now0[i]);
				}
			}
			else 
				fprintf(out,"%c",now0[i]);
		}
	}
	
	fclose (in);
	fclose (out);
	return 0;
}
