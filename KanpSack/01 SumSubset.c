/*
input : 
6
16
12 3 3 5 9 6
*/
#include <stdio.h>
int SS(int arr[],int sum, int n){
        int out=0;
        if(n==0)
                out = 0;
        if(sum==0)
                out = 1;
        // Choice
        if(arr[n-1]<=sum){
                out = ( SS(arr, sum-arr[n-1], n-1) || SS(arr, sum, n-1) );
        }
        else if(arr[n-1]>sum){
                out = SS(arr, sum, n-1);
        }
        return out;
}
int TD[20][20];

int main()
{
        int sum, n, arr[10];

        
        printf("Hello, world!\n");
        printf("Enter the number of items : ");
        scanf("%d",&n);
        printf("Enter the sum : ");
        scanf("%d",&sum);
        printf("Enter the Array : ");
        for(int i=0;i<n;i++)
                scanf("%d",&arr[i]);
        // Initialise
        for(int i=0;i<n+1;i++)
                for(int j=0;j<sum+1;j++){
                        if(i==0)
                                TD[i][j]=0;
                        if(j==0)
                                TD[i][j]=1;
                }
                /*
        for(int i=0;i<n+1;i++){
                if(i>0)
                        printf("%d\t",arr[i-1]);
                else
                        printf("\t");
                for(int j=0;j<sum+1;j++)
                        printf("%d\t",TD[i][j]);
                printf("\n");        
                }*/
        //Choice Code\
        // Beware of the loop initialization starts from 0ne dont, change the value at PreInitialised value
        for(int i=1;i<n+1;i++)
                for(int j=1;j<sum+1;j++){
                        if(arr[i-1]<=j)
                                TD[i][j]=(  TD[i-1][j-arr[i-1]] || TD[i-1][j]  );
                        else if(arr[i-1]>j)
                                TD[i][j]=TD[i-1][j];
                }
        // printf("Result : %d\n",SS(arr,sum,n));
        printf("Result : %d\n",TD[n][sum]);
        printf("\t");
        for(int i=0;i<=sum;i++)
                printf("%d  ",i%10);

        printf("\n");
        for(int i=0;i<n+1;i++){
                if(i>0)
                        printf("%d\t",arr[i-1]);
                else
                        printf("\t");
                for(int j=0;j<sum+1;j++)
                        printf("%d  ",TD[i][j]);
                printf("\n");        
                }
        return 0;
}
