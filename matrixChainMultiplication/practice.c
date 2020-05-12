// matrix chain multiplication
#include<stdio.h>
#define INT_MAX 32768
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int MCM(int a[],int i,int j){
    int temp=0;
    int mm=INT_MAX;
    if(i>=j)
        return 0;

    for(int k=i;k<=j-1;k++){
        temp=MCM(a,i,k)+MCM(a,k+1,j)+a[i-1]*a[k]*a[j];
        printf("%d \n",temp);
        mm=min(mm,temp);
    }
    return mm;
}
int main(){
    int a[]={4,2,3,5},i=1,j=3;
    printf("The minimum cost of matrix multiplication : %d",MCM(a,i,j));
    return 0;
}