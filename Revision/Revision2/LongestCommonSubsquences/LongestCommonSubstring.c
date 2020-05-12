#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}

//TopDown

int TD[20][20];
int LCStr(char a[],char b[],int m,int n){
    int result=0;
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            if(j==0 || i==0)
                TD[i][j]=0;
    
    for(int i=1;i<m+1;i++)
        for(int j=1;j<n+1;j++){
            if(a[i-1]==b[j-1])
                result = max(TD[i][j]=1+TD[i-1][j-1],result);
            else
                TD[i][j]=0;
        }
    
    return result;
}

int main(){
    char a[]={'A','B','Z','C','E'};
    int m=5,n=6;
    char b[]="ABZels";
    // char b[]={'X','A','Z','Z','C','E'};
    printf("LCS %d",LCStr(a,b,m,n));
    return 0;
}