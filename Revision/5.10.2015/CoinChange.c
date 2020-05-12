// minimum number of coins
#include<stdio.h>
#define INT_MAX 32768
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int TD[40][40];
int MNC(int coin[],int amt,int n){
    for(int i=0;i<n+1;i++)
        for(int j=0;j<amt+1;j++){
            if(i==0)
                TD[i][j]=INT_MAX;
            if(j==0)
                TD[i][j]=0;
        }
    
    for(int j=1;j<amt+1;j++)
        TD[1][j]=(j%coin[0]==0?j/coin[0]:INT_MAX);
    
    for(int i=2;i<n+1;i++)
        for(int j=1;j<amt+1;j++){
            if(coin[i-1]<=j)
                TD[i][j]=min(1+TD[i][j-coin[i-1]],TD[i-1][j]);
            else
                TD[i][j]=TD[i-1][j];
        }
    
    return TD[n][amt];
}
int main(){
    int coin[]={1,2,5,10};
    int amt=40,n=4;
    // printf("The result : %d",MNC(coin,amt,n));
    for(int i=0;i<amt+1;i++)
        printf("amt: %d coins: %d\n",i,MNC(coin,i,n));
        
    return 0;
}