#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
//  Recursive
/*
int LCS(char a[],char b[],int m,int n){
    if(n==0 || m==0)
        return 0;
    if(a[m-1]==b[n-1])
        return 1+LCS(a,b,m-1,n-1);
    else
        return max(LCS(a,b,m-1,n), LCS(a,b,m,n-1));
}*/
// TopDown
int TD[20][20];
int TLCS(char a[],char b[],int m,int n){
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            if(i==0 || j==0)
                TD[i][j]=0;
    
    for(int i=1;i<m+1;i++)
        for(int j=1;j<n+1;j++){
            if(a[i-1]==b[j-1])
                TD[i][j]=1+TD[i-1][j-1];
            else 
                TD[i][j]=max(TD[i-1][j],TD[i][j-1]);
        }
    
    return TD[m][n];
}
int main(){
    char a[]={'A','B','Z','C','E'},b[]={'X','A','Z','B','C','E'};
    int m=5,n=6;
    printf("LCS %d",TLCS(a,b,m,n));
    return 0;
}