#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int n,m,ans=0;
int a[103];

void swapp(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}

void choose_sort(int k[])
{
	int i,j;
	for (i=0;i<n;i++)
	{
		int min_n=0x7fffffff,min_x=0;
		for (j=i;j<n;j++)
			if (k[j]<min_n)
			{
				min_n=k[j];
				min_x=j;
			}
		swapp(&k[i],&k[min_x]);
	}
		
}

void bubble_sort(int k[])
{
	int i,j;
	for (i=0;i<n;i++)
	{
		int huan=0;
		for (j=0;j<n-i-1;j++)
		{
			ans++;
			if (k[j]>k[j+1])
			{
				huan=1;
				swapp(&k[j],&k[j+1]);
			}
		}
		if (huan==0) return;
	}
}

void adjust(int k[],int i,int n)
{
	int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n)
	{
        if(j<n-1 && k[j]<k[j+1])
            j++;
        ans++;
        if(temp>=k[j]) 
            break;
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
    k[(j-1)/2]=temp;
}

void heap_sort(int k[],int n)
{
	int i;
	for (i=n/2;i>=0;i--)
		adjust(k,i,n);
	for (i=n-1;i>=0;i--)
	{
		swapp(&k[i],&k[0]);
		adjust(k,0,i);
	}
}

void merge(int x[],int tmp[],int left,int leftend,int rightend)
{     
    int i=left, j=leftend+1, q=left;
    while(i<=leftend && j<=rightend)
    {
    	ans++;
        if(x[i]<=x[j]) 
            tmp[q++]=x[i++];
        else
            tmp[q++]=x[j++];
    }
    while(i<=leftend)
        tmp[q++]=x[i++];
    while(j<=rightend)
        tmp[q++]=x[j++];
    for(i=left; i<=rightend; i++)
        x[i]=tmp[i];
}

void mSort(int k[],int tmp[],int left,int right)
{
    int center;
    if(left < right)
	{
        center = (left+right)/2;
        mSort(k, tmp, left, center);
        mSort(k, tmp, center+1, right);
        merge(k, tmp, left,center, right);
    }
}

void merge_sort(int k[],int n)
{
    int *tmp;
    tmp = (int *)malloc(sizeof(int) * n);
    mSort(k, tmp, 0, n-1);
    free(tmp);

}

void quick_sort(int k[],int l,int r)
{
	int i,mid;
	if (l<r)
	{
		mid=l;
		for (i=l+1;i<=r;i++)
		{
			ans++;
			if (k[i]<k[l])
				swapp(&k[++mid],&k[i]);
		}
		swapp(&k[l],&k[mid]);
		quick_sort(k,l,mid-1);
		quick_sort(k,mid+1,r);
	}
}

void init()
{
	scanf("%d%d",&n,&m);
	int i;
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	if (m==1)
	{
		choose_sort(a);
		for (i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		printf("%d\n",(n-1)*n/2);
	}
	if (m==2)
	{
		bubble_sort(a);
		for (i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		printf("%d\n",ans);
	}
	if (m==3)
	{
		heap_sort(a,n);
		for (i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		printf("%d\n",ans);
	}
	if (m==4)
	{
		merge_sort(a,n);
		for (i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		printf("%d\n",ans);
	}
	if (m==5)
	{
		quick_sort(a,0,n-1);
		for (i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		printf("%d\n",ans);
	}
}

int main()
{
	init();
	return 0;
}


