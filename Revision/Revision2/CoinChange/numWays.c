// number of ways to collect certain amount of money
#include<stdio.h>

int CC(int coin[],int amt,int n){
    if(amt==0)
        return 1;
    if(n==0)
        return 0;
    if(coin[n-1]<=amt)
        return (CC(coin,amt-coin[n-1],n) + CC(coin,amt,n-1));
    else
        return CC(coin,amt,n-1);
}
int main(){
    int coin[]={1,2,3};
    int amt=10,n=3;
    for(int i=0;i<amt+1;i++)
        printf("amt %d ways %d\n",i,CC(coin,i,n));
    return 0;
}