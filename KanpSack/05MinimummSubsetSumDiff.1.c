#include<stdio.h>

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

int MSD(int num[],int n){
        int sum=0;
        int result=0;
        for(int i=0;i<n;i++)
                sum+=num[i];
        if(sum%2==0){
                sum/=2;
                for(int i=sum;i>=0;i--){
                        if(SS(num,i,n)){
                                result=i;
                                break;
                        }
                }
                printf("%d\n",result);
                return ((sum-result)*2);
        }
        else{
                sum=sum/2;
                for(int i=sum;i>=0;i--){
                        if(SS(num,i,n)){
                                result=i;
                                break;
                        }
                }
                printf("%d\n",result);
                return ((sum-result)*2+1);
                // if(result%2==0)
                //         return ((sum-result)*2-1);
                // else
                        // return ((sum-result)*2+1);
        }
}
void fun(int num[],int n){
        int sum=0,s1=0;
        for(int i=0;i<n;i++)
                sum+=num[i];
        
        for(int i=0;i<n;i++)
                if(s1+num[i]<=sum/2)
                        s1+=num[i];
        
        printf("The greatest Possible close to mid : %d and diff = %d",s1,(sum-2*s1));

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
        fun(num,n);
        // printf("Result : %d\n",MSD(num,n));
        return 0;
}