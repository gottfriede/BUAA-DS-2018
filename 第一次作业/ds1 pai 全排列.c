#include<stdio.h>
#include<math.h>
int n;
int a[20],v[20];

void prit()
{
	int i;
	for (i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
	return;
}

void dfs(int x)
{
	if (x==n)
	{
		prit();
		return;
	}
	int i;
	for (i=1;i<=n;i++)
		if (!v[i])
		{
			a[x]=i;
			v[i]=1;
			dfs(x+1);
			v[i]=0;
		}
}

int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}
