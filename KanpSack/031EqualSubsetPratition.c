#include <stdio.h>
#include <conio.h>

int SS(int num[],int sum,int n){
        int result=0;
        if(n==0 || sum==0){
                if(n==0)
                        result = 0;
                if(sum==0)
                        result = 1;
                return result;
        }
        if(num[n-1]<=sum)
                return (SS(num,sum-num[n-1],n-1) || SS(num,sum,n-1) );
        else if(num[n-1]>sum)
                return SS(num,sum,n-1);
}
int ESP(int num[],int n){
        int sum=0;
        int result=0;
        for(int i=0;i<n;i++)
                sum+=num[i];
        //---------------Calculate sum------------------
        if(sum%2 == 1) //   Odd
                return 0; 
        if(sum%2 == 0){  // Even
                result=SS(num,sum/2,n);
                // printf("subset sum %d : %d\n",sum/2,result);
                return result;
        }
}
int main()
{
        int n=0,num[10];
        printf("Hello, world!\n");
        printf("Enter the size of arr : ");
        scanf("%d", &n);
        
        printf("Enter the arr : ");
        for(int i=0;i<n;i++)
                scanf("%d",&num[i]);

        printf("Result : %d\n",ESP(num,n));
        return 0;
}