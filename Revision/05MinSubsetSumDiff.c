#include<stdio.h>

int TD[20][20];

int TDSS(int num[],int sum,int n){
	for(int i=0;i<n+1;i++)
		for(int j=0;j<sum+1;j++)
			if(j==0)
				TD[i][j]=1;
			else if(i==0)
				TD[i][j]=1;
	
	for(int i=1;i<n+1;i++)
		for(int j=1;j<sum+1;j++){
			if(num[i-1]<j)
				TD[i][j]=(TD[i-1][j-num[i-1]] || TD[i-1][j]);
			else if(num[i-1]>j)
				TD[i][j]=TD[i-1][j];
		}
	
	return TD[n][sum];
}
int MSD(int num[],int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=num[i-1];
	
	TDSS(num,sum/2,n);

	for(int i=sum/2;i>=0;i--)
		if(TD[n][i])
			return (sum-2*i);
}
int main(){
	int num[10],n;
	printf("Enter the n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);

	printf("Minimumm Subset Sum Diff : %d",MSD(num,n));
	return 0;
}