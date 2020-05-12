#include<stdio.h>
/*
8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20
10=26
*/
int max(int a,int b){
	if(a<b)
		return b;
	return a;
}
// == Recursive Approach()===============
int Knap(int wt[],int val[],int W,int n){
	if(n==0 || W==0)
		return 0;

	if(wt[n-1]<=W)
		return max(val[n-1]+Knap(wt,val,W-wt[n-1],n-1) , Knap(wt,val,W,n-1));
	else if(wt[n-1]>W)
		return Knap(wt,val,W,n-1);

}
int main(){
	int wt[10],val[10],W,n;
	printf("Enter the W,n,wt,val\n");
	scanf("%d",&W);
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",&wt[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&val[i]);
	printf("\nThe max Profit : %d",Knap(wt,val,W,n));
    return 0;
}