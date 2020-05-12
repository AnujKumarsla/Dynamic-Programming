#include<stdio.h>

int SS(int num[],int sum,int n){
	if(sum==0)
		return 1;
	if(n==0)
		return 0;
	
	if(num[n-1]<=sum)
		return (SS(num,sum-num[n-1],n-1) || SS(num,sum,n-1));
	if(num[n-1])
		return SS(num,sum,n-1);
}
int main(){
	int num[10],sum,n;
	printf("Enter the n,num,sum\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	
	scanf("%d",&sum);

	printf("is the sum exist in the set : %d",SS(num,sum,n));
    return 0;
}