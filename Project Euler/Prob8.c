#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
long int find(int N[]){
    long int mul=0;
    long int result=0;
    for(int i=0;i<996;i++){
        mul=N[i]*N[i+1]*N[i+2]*N[i+3]*N[i+4];
        // mul=N[i]*N[i+1]*N[i+2]*N[i+3]*N[i+4]*N[i+5]*N[i+6]*N[i+7]*N[i+8]*N[i+9]*N[i+10]*N[i+11]*N[i+12];
        result=max(result,mul);
    }
    return result;
}
int main(){
    int N[1000];
    printf("Enter the Array : ");
    for(int i=0;i<1000;i++)
        scanf("%d",N+i);

    printf("result : %ld",(long)find(N));
    return 0;
}