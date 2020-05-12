#include<stdio.h>
#define INT_MAX 32768
int TD[20][20];
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int MNC(int coin[],int amt,int n){

    //Initialization
    for(int i=0;i<n+1;i++)
        for(int j=0;j<amt+1;j++)
            if(i==0)
                TD[i][j]=INT_MAX;
            else if(j==0)
                TD[i][j]=0;
    
    // Second row initialization
    for(int j=1;j<amt+1;j++)
        if(j%coin[0]==0)
            TD[1][j]=j/coin[0];
        else if(j%coin[0]!=0)
            TD[1][j]=INT_MAX;

    //Filling the matrix
    for(int i=2;i<n+1;i++)
        for(int j=1;j<amt+1;j++)
            if(coin[i-1]<=j)
                TD[i][j]=min(1+TD[i][j-coin[i-1]], TD[i-1][j]);
            else if(coin[i-1]>j)
                TD[i][j]=TD[i-1][j];

    return TD[n][amt];
}
int main(){
    int coin[20],n,amt;
    printf("Enter the n,amt,coin : \n");
    scanf("%d %d",&n,&amt);
    for(int i=0;i<n;i++)
        scanf("%d",&coin[i]);

    printf("Minimum number of the coins : %d\n",MNC(coin,amt,n));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<amt+1;j++)
            printf("%d\t",TD[i][j]);
        printf("\n");    
    }
    return 0;
}