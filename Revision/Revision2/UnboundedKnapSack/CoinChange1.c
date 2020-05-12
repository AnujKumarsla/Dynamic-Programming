// Total number of ways possible to an amount

#include<stdio.h>

int CC(int a[],int amt,int n){
    if(amt==0)
        return 1;
    if(n==0)
        return 0;
    if(a[n-1]<=amt)
        return (CC(a,amt-a[n-1],n) + CC(a,amt,n-1));
    else
        return CC(a,amt,n-1);
}
int main(){
    int a[]={1,2,3,5},n=4;
    int amt=17;
    for(int i=0;i<amt;i++)
        printf("n=%d ways=%d\n",i,CC(a,i,n));
    return 0;
}