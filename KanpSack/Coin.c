#include<stdio.h>

int min(int a, int b){
        if(a<b)
                return a;
        return b;
}
int CC(int coin[],int total,int n){
        int result=0;
        if(total==0 || n==0){
                if(n==0)
                        result=0;
                if(total==0)
                        result=1;
                return result;
        }

        if(coin[n-1]<=total)
                return (1+ min(CC(coin,total-coin[n-1],n) , CC(coin,total,n-1) ));
        else 
                return (1+CC(coin,total,n-1));
}
int main(){
        int arr[10],n=0,total=0;
        printf("Enter the size of the array : ");
        scanf("%d",&n);
        printf("Enter the array : ");
        for(int i=0;i<n;i++)
                scanf("%d",&arr[i]);
        printf("Enter the total : ");
        scanf("%d",&total);
        printf("total no. of Ways : %d",CC(arr,total,n));
        return 0;
}