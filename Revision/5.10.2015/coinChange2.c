#include<stdio.h>
/*
int NWC(int coin[],int amt,int n){
    // Recursive
    if(amt==0)
        return 1;
    if(n==0)
        return 0;
    if(coin[n-1]<=amt)
        return (NWC(coin,amt-coin[n-1],n)+NWC(coin,amt,n-1));
    else 
        return NWC(coin,amt,n-1);
}
*/

int TD[40][40];
void menset(int n,int amt){
    for(int i=0;i<n+1;i++)
        for(int j=0;j<amt+1;j++)
            TD[i][j]=-1;
}
int TNC(int coin[],int amt,int n){
    if(amt==0)
        return 1;
    if(n==0)
        return 0;
    if(coin[n-1]<=amt)
        return (TD[n][amt] = ((TD[n][amt-coin[n-1]]!=-1)?TD[n][amt-coin[n-1]]:TNC(coin,amt-coin[n-1],n)+
        (TD[n-1][amt]!=-1)?TD[n-1][amt]:TNC(coin,amt,n-1)));
    else
        return (TD[n][amt] = TD[n-1][amt]!=-1?TD[n-1][amt]:TNC(coin,amt,n-1));
}
int main(){
    int coin[]={1,2,3,5,10};
    int amt=10,n=4;
        printf("amt %d, ways %d\n",amt,TNC(coin,amt,n));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<amt+1;j++)
            printf("%d\t",TD[i][j]);
        printf("\n");    
    }
    // for(int i=0;i<=amt;i++)
        // printf("amt %d, ways %d\n",i,TNC(coin,i,n));
    return 0;
}