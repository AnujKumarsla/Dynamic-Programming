#include <stdio.h>
int count=0;
int max(int a, int b){
        if(a<b)
                return b;
        return a; 
}
int result[50][50];

int Knapsack(int wet[], int val[], int W, int n){
        if(n==0 || W==0){
                return 0;
        }
        if(result[W][n]!=-1){
                count++;
                return result[W][n];
        
        }
        if(wet[n-1]<=W)
                return result[W][n]=max(val[n-1]+Knapsack(wet, val, W-wet[n-1], n-1), Knapsack(wet, val, W, n-1));
        return result[W][n]=Knapsack(wet, val, W, n-1);
}
int main()
{       
        int wet[10],val[10],n=10,W;

        int profit=0;
        for(int i=0;i<50;i++)
                for(int j=0;j<50;j++)
                        result[i][j]=-1;  
        
        printf("Hello, world!\n");
        printf("Enter the Weight : ");
        scanf("%d", &W);
        printf("Enter the size : ");
        scanf("%d", &n);
        printf("Enter the Weight Array : ");
        for(int i=0;i<n;i++)
                scanf("%d",&wet[i]);
        
        printf("Enter the value Array : ");
        for(int i=0;i<n;i++)
                scanf("%d",&val[i]);
        
        profit=Knapsack(wet, val, W, n);
        printf("The net Profit is : %d\nTotal overlapping cases : %d",profit,count);
        return 0;
}
