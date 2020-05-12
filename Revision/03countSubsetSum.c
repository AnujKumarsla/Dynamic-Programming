#include<stdio.h>


int CSS(int num[],int sum,int n){
	if(sum==0)
		return 1;
	if(n==0)
		return 0;

	if(num[n-1]<=sum)
		return (CSS(num,sum-num[n-1],n-1) + CSS(num,sum,n-1) );
	else if(num[n-1]>sum)
		return CSS(num,sum,n-1);
}
int main(){
	int num[10],sum,n;
	printf("Enter the n,sum,num\n");
	scanf("%d",&n);
	scanf("%d",&sum);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);

	printf("The no. of times sum is exist in set : %d",CSS(num,sum,n));

    return 0;
}