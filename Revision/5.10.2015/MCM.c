#include<stdio.h>
#define INT_MAX 32768
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int MCM(int a[],int start,int end){
    int mm=INT_MAX,temp;
    if(start>=end)
        return 0;
    for(int k=start;k<=end-1;k++){
        temp=MCM(a,start,k)+MCM(a,k+1,end)+a[start-1]*a[k]*a[end];
        mm=min(temp,mm);
    }
    return mm;
}
int main(){
    int a[]={4,2,3,5};
    int start=1,end=3;
    printf("Result : %d",MCM(a,start,end));
    return 0;
}