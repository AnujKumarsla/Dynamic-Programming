#include <stdio.h>

int TD[10][20];
int max(int a,int b){
        if(a<b)
                return b;
        return a;
}
int UK(int wt[],int val[],int W,int n){
        for(int i=0;i<n+1;i++)
                for(int j=0;j<W+1;j++){
                        if(i==0)
                                TD[i][j]=0;
                        if(j==0)
                                TD[i][j]=1;
                }

        for(int i=1;i<n+1;i++)
                for(int j=1;j<W+1;j++){
                        if(wt[i-1]<=j)
                                TD[i][j]= max(val[i-1] +TD[i][j-wt[i-1]], TD[i-1][j]);
                        else
                                TD[i][j]= TD[i-1][j];
                }
        return TD[n][W];
}

int main()
{       
        int wet[10],val[10],n=10,W;

        int profit=0; 
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
        
        profit=UK(wet, val, W, n);
        printf("The net Profit is : %d\n",profit);
        for(int i=0;i<n+1;i++){
                for(int j=0;j<W+1;j++)
                        printf("%d ",TD[i][j]);
                printf("\n");
        }
        return 0;
}
