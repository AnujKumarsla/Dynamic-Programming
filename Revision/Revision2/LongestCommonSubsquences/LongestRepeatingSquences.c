// Longest REapeating Squences

#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int TD[20][20];
int LRS(char a[],int n){
    int lrs=0;
    for(int i=0;i<n+1;i++)
        for(int j=0;j<n+1;j++)
            if(i==0 || j==0)
                TD[i][j]=0;
    
    for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++){
            if(a[i-1]==a[j-1] && i!=j)
                lrs++;
        }
    
    return (lrs/2);
}
int main(){
    char a[]="ABACBC";
    int n=6;
    printf("The LRS %d",LRS(a,n));
    return 0;
}