// Maximum number of ways to Total money equal M
#include<stdio.h>

int CoinChange(int coin[],int sum,int n){
        int result=0;

        if(sum==0 || n==0 ){
                if(n==0)
                        result=0;
                if(sum==0)
                        result=1;
                return result;
        }

        if(coin[n-1]<=sum)
                return (CoinChange(coin,sum-coin[n-1],n) + CoinChange(coin,sum,n-1));
        else if(coin[n-1]>sum)
                return CoinChange(coin,sum,n-1);
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

        printf("number of ways : %d",CoinChange(coin,sum,n));
        

        return 0;
}