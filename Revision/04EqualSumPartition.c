#include<stdio.h>

int SS(int num[],int sum,int n){
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    
    if(num[n-1]<=sum)
        return (SS(num,sum-num[n-1],n-1) || SS(num,sum,n-1) );
    else if(num[n-1]>sum)
        return SS(num,sum,n-1);
}
int ESP(int num[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=num[i];
    
    if(sum%2==1)
        return 0;
    else if(sum%2==0)
        return SS(num,sum/2,n);
}
int main(){
    int num[10],n;
    printf("Enter the n,num:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    
    printf("Is Equal Sum Partion Exists : %d\n",ESP(num,n));
    return 0;
}