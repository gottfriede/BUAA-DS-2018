#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int m[23][23];

void init()
{
	int i,j;
	for (i=1;i<=19;i++)
		for (j=1;j<=19;j++)
			scanf("%d",&m[i][j]);
}

int solve(int x,int y)
{
	int d=m[x][y];
	if (y<=15)
		if (m[x][y+1]==d&&m[x][y+2]==d&&m[x][y+3]==d&&m[x][y+4]==0)
			return d;
	if (x<=15)
		if (m[x+1][y]==d&&m[x+2][y]==d&&m[x+3][y]==d&&m[x+4][y]==0)
			return d;
	if (x<=15&&y<=15)
		if (m[x+1][y+1]==d&&m[x+2][y+2]==d&&m[x+3][y+3]==d&&m[x+4][y+4]==0)
			return d;
	if (x<=15&&y>=5)
		if (m[x+1][y-1]==d&&m[x+2][y-2]==d&&m[x+3][y-3]==d&&m[x+4][y-4]==0)
			return d;
	return 0;
}

int main()
{
	init();
	int i,j;
	for (i=1;i<=19;i++)
		for (j=1;j<=19;j++)
			{
				int ans=solve(i,j);
				if (ans==0)
					continue;
				else
				{
					printf("%d:%d,%d\n",ans,i,j);
					return 0;
				}
			}
	printf("No\n");
	return 0;
}


