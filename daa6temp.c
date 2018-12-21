#include<stdio.h>
int cost(int n,int k,int ar[]);
void print(int pi[],int ar[], int n);
void main()
{
	int n,k,i,ar[20],mc,flag=0;
	printf("\nEnter the no. of elements:");
	scanf("%d",&n);
	printf("\nEnter the no. of partition:");
	scanf("%d",&k);
	if(k>=n)
	{
		printf("\nNo. of partition should be less then no. of elements");
		flag=1;
	}
	if(flag==0)
	{
		printf("\nEnter the elements:");
		for(i=0;i<n;i++)
			scanf("%d",&ar[i]);
		mc=cost(n,k,ar);
		printf("\n Minimum Cost of partition=%d",mc);
	}
}
int cost(int n,int k,int ar[])
{
	int kn[n+1][k+1],i,j,r,small,mat[n*k],inc=0,pi[k],ti,tj;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
			kn[i][j]=999;
	}
	kn[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			r=i-1;
			while(r>=0)
			{
				small=kn[r][j-1]+(ar[i-1]-ar[r])*(ar[i-1]-ar[r]);
				if(small<kn[i][j])
				{
					mat[inc]=r;
					kn[i][j]=small;
				}
				r--;
			}
			inc++;
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
			printf("%d\t",kn[i][j]);
		printf("\n");
	}
	ti = k-2;
	tj = inc-1;
	while(ti>=0)
    {
        pi[ti--] = mat[tj]-1;
        tj = tj -((n-mat[tj])*k)-1;
    }
	print(pi,ar,n);
	return kn[n][k];
}
void print(int pi[],int ar[], int n)
{
    int i, j = 0;
	printf("\nPartitions:");
	printf("\nPartition 1: ");
    for(i=0; i<n; i++)
    {
        printf("%d  ",ar[i]);
        if(i==pi[j])
        {
            printf("\nPartition %d: ", (j+2));
            j++;
        }
    }
}
		 
/*Output
tejal@ubuntu:~/Desktop$ gcc daa6temp.c
tejal@ubuntu:~/Desktop$ ./a.out

Enter the no. of elements:8

Enter the no. of partition:3

Enter the elements:1 3 5 7 9 11 13 15
0	999	999	999	
999	0	999	999	
999	4	0	999	
999	16	4	0	
999	36	8	4	
999	64	20	8	
999	100	32	12	
999	144	52	24	
999	196	72	36	

Partitions:
Partition 1: 1  3  5  
Partition 2: 7  9  11  
Partition 3: 13  15  
 Minimum Cost of partition=36

Descending order
tejal@ubuntu:~/Desktop$ gcc daa6temp.c
tejal@ubuntu:~/Desktop$ ./a.out

Enter the no. of elements:8

Enter the no. of partition:3

Enter the elements:15 13 11 9 7 5 3 1
0	999	999	999	
999	0	999	999	
999	4	0	999	
999	16	4	0	
999	36	8	4	
999	64	20	8	
999	100	32	12	
999	144	52	24	
999	196	72	36	

Partitions:
Partition 1: 15  13  11  
Partition 2: 9  7  5  
Partition 3: 3  1  
 Minimum Cost of partition=36

Random order
tejal@ubuntu:~/Desktop$ gcc daa6temp.c
tejal@ubuntu:~/Desktop$ ./a.out

Enter the no. of elements:8

Enter the no. of partition:3

Enter the elements:9 7 5 1 3 11 15 13
0	999	999	999	
999	0	999	999	
999	4	0	999	
999	16	4	0	
999	64	16	4	
999	36	8	4	
999	4	16	8	
999	36	4	16	
999	16	8	4	

Partitions:
Partition 1: 9  7  5  1  3  11  
Partition 2: 15  
Partition 3: 13  
 Minimum Cost of partition=4
*/

