#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int static counter;
// Recursion
/* 
int RC(int len[],int val[],int Len,int n){
    if(Len<=0 || n<=0)
        return 0;
    if(len[n-1]<=Len)
        return max(val[n-1]+RC(len,val,Len-len[n-1],n) , RC(len,val,Len,n-1));
    else 
        return RC(len,val,Len,n-1);
}*/

// Memoization
/*
int TD[20][20];
void Minit(int Len,int n){
    for(int i=0;i<n+1;i++)
        for(int j=0;j<Len+1;j++)
            TD[i][j]=-1;
}
int MRC(int len[],int val[],int Len,int n){
    if(Len==0 || n==0)
        return 0;
    if(TD[n][Len]!= -1)
        return TD[n][Len];
    if(len[n-1]<=Len)
        return max(val[n-1]+MRC(len,val,Len-len[n-1],n) , MRC(len,val,Len,n-1));
    else 
        return MRC(len,val, Len,n-1);
}
*/

// TopDown Approach
int TD[20][20];
int TRC(int len[],int val[],int Len,int n){
    for(int i=0;i<n+1;i++)
        for(int j=0;j<Len+1;j++)
            if(i==0 || j==0)
                TD[i][j]=0;
    
    for(int i=1;i<n+1;i++)
        for(int j=1;j<Len+1;j++){
            if(len[i-1]<=Len)
                TD[i][j]=max(val[i-1]+TD[i][j-len[i-1]], TD[i-1][j]);
            else
                TD[i][j]=TD[i-1][j];
        }
    
    return TD[n][Len];
}
int main(){
    int len[]={4,5,6,3},val[]={3,4,2,1},n=4;
    int Len=10;
    // for(int i=0;i<=Len;i++){
    //     Minit(i,n);
    //     printf("Len=%d max Profit: %d\n",i,MRC(len,val,i,n));
    // }
    for(int i=0;i<=Len;i++){
        printf("Len=%d max Profit: %d\n",i,TRC(len,val,i,n));
    }
    printf("hell0");
    

    return 0;
}