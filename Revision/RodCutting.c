#include<stdio.h>
/*
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20
10=27
4=10
*/
int max(int a,int b){
	if(a<b)
		return b;
	return a;
}
int RC(int len[],int val[],int L,int n){
	if(L==0 || n==0)
		return 0;

	if(len[n-1]<=L)
		return max(val[n-1]+RC(len,val,L-len[n-1],n) , RC(len,val,L,n-1));
	else if(len[n-1]>L)
		return RC(len,val,L,n-1);
}
int main(){
	int len[10],val[10],L,n;
	printf("Enter the n,L,len,val\n");
	scanf("%d",&n);
	scanf("%d",&L);
	for(int i=0;i<n;i++)
		scanf("%d",&len[i]);
	
	for(int i=0;i<n;i++)
		scanf("%d",&val[i]);
	
	printf("The net max Profit : %d",RC(len,val,L,n));
    return 0;
}