#include <stdio.h>
# define INT_MAX 214748364
int TD[20][20];
int min(int a,int b){
        if(a<b)
                return a;
        return b;
}
int CoinChange(int coin[],int sum,int n){
        for(int i=0;i<n+1;i++)
                for(int j=0;j<sum+1;j++){
                        if(i==0)
                                TD[i][j]=INT_MAX;
                        if(j==0)
                                TD[i][j]=0;
                }
        
        for(int j=1;j<sum+1;j++){
                if(j%coin[n-1]==0)
                        TD[1][j]=j%coin[n-1];
                else 
                        TD[1][j]=INT_MAX;
        }

        for(int i=1;i<n+1;i++)
                for(int j=0;j<sum+1;j++){
                        if(coin[i-1]<=j)
                                TD[i][j]= min(1+TD[i][j-coin[n-1]], TD[i-1][j] );
                        else
                                TD[i][j]= TD[i-1][j];
                }
        
        return TD[n][sum];
}
int main()
{
        int coin[10],n=0,sum=0;
        printf("Hello, world!\n");
        printf("Enter the size of the array : ");
        scanf("%d",&n);

        printf("Enter the array : ");
        for(int i=0;i<n;i++){
                // printf("%d. %d. \n",i,n);
                scanf("%d",&coin[i]);}

        printf("Enter the sum : ");
        scanf("%d",&sum);

        printf("minimum no. of coins : %d",CoinChange(coin,sum,n));
        

        return 0;
}