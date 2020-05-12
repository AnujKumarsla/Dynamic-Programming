#include<stdio.h>
#include<conio.h>

int counter=0;
// Recursion===================================
int count(int num[],int sum,int n){
        
        // printf("%d. n=%d , sum=%d \n",counter++,n,sum);
        int result;
        printf("%d,",counter++);
        // ------------Base Condition-------------
        if(n==0 || sum==0){
                if(n==0)
                        result=0;
                if(sum==0)
                        result=1;
                return result;
        }
        // ------------ Choice -----------------------
        if(num[n-1]<=sum)
                return ( count(num,sum-num[n-1],n-1) + count(num,sum,n-1) );
        else if(num[n-1]>sum)
                return count(num,sum,n-1);
}
int TD[12][20];
//======================  Recursion + Memoization ==========================

void Minit(int n,int sum){
        for(int i=0;i<n+1;i++)
                for(int j=0;j<sum+1;j++){
                counter++;
                        TD[i][j]=-1;
                        }
}
int Mcount(int num[],int sum,int n){
        int result =0;
                counter++;
        //Base Condition -------------------------------------------------
        if(n==0 || sum==0){
                if(n==0)
                        result = 0;
                if(sum==0)
                        result = 1;
                // return TD[n][sum]=result;
                return result;
        }
        // Fetch result from Matrix -------------------------------------------------
        if(TD[n][sum] != -1)
                return TD[n][sum];
        // Choice Code -------------------------------------------------
        if(num[n-1]<=sum)
                return TD[n][sum]= ( Mcount(num, sum, n-1) + Mcount(num,sum-num[n-1], n-1) );
        else if(num[n-1]>sum)
                return TD[n][sum]= Mcount(num,sum,n-1);
}
// ?========================Top Down Approach======================
void TDinit(int n,int sum){
        for(int i=0;i<n+1;i++)
                for(int j=0;j<sum+1;j++){
                        counter++;
                        if(i==0)
                                TD[i][j]=0;
                        if(j==0)
                                TD[i][j]=1;
                }
}
int TDcount(int num[],int sum,int n){
        for(int i=1;i<n+1;i++)
                for(int j=1;j<sum+1;j++){
                        counter++;
                        if(num[i-1] <= j){
                                TD[i][j]= (TD[i-1][j-num[i-1]] + TD[i-1][j] );
                        }
                        else if(num[i-1] > j)
                                TD[i][j]= TD[i-1][j];
                }
        return TD[n][sum];
}
int main()
{
        int n=0, sum=0, num[10];
        printf("Hello, world!\n");
        printf("Enter the size of arr : ");
        scanf("%d", &n);
        printf("Enter the sum : ");
        scanf("%d", &sum);
        
        printf("Enter the arr : ");
        for(int i=0;i<n;i++)
                scanf("%d",&num[i]);

        // TDinit(n,sum);
        // printf("Result : %d, TDcount=%d",TDcount(num,sum,n),counter);
        // Minit(n,sum);
        // printf("Result : %d, count=%d",Mcount(num,sum,n),counter);

        printf("Result : %d, count=%d",count(num,sum,n),counter);
        return 0;
}