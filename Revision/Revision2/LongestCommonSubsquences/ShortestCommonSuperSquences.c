// ShortestCommonSuperSquences
#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

int LCS(char a[],char b[],int m,int n){
    if(n==0 || m==0)
        return 0;
    if(a[m-1]==b[n-1])
        return 1+LCS(a,b,m-1,n-1);
    else
        return max(LCS(a,b,m-1,n), LCS(a,b,m,n-1));
}

int SCSS(char a[],char b[],int m,int n){
    int lcs=LCS(a,b,m,n);
    return (m+n-lcs);
}
int main(){
    char a[]="ABCXYZ",b[]="ACBYXZ";
    int m=6,n=6;
    printf("ShortestCommonSuperSquences : %d",SCSS(a,b,m,n));
    return 0;
}