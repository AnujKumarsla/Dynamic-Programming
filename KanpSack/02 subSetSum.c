#include<stdio.h>
int TD[10][40];
/*

int SS(int arr[], int sum, int n){
        if(sum==0)
                return 1;
        if(n==0)
                return 0;

        if(arr[n-1]<=sum){
                return ( SS(arr, sum-arr[n-1], n-1) || SS(arr, sum, n-1) );
        }
        else if(arr[n-1]>sum){
                return SS(arr, sum, n-1);
        }
}

int ESP(int arr[], int n){
        int sum=0;
        for(int i=0;i<n;i++)
                sum+=arr[i];

        sum/=2;
        if(sum%2 != 0){
                return 0;
        }
        else if(sum%2 == 0){
                return SS(arr, sum, n);
        }
}
*/
void print(int arr[], int i,int j){
        int x=arr[i-1];
        if(x==j){
                printf("%d ",x);
                if(TD[i-1][j]==1){
                        printf("\n");
                        print(arr,i-1,j);
                }
                // return;
        }
        if(x<j){
                if(TD[i-1][j-x]==1){
                        printf("%d ",x);
                        print(arr,i-1,j-x);
                        // return;
                }
                // else
                // {
                //         print(arr,i-1,j);
                //         return;
                // }
        }
        if(x>j && TD[i-1][j]){
                print(arr,i-1,j);
                // return;
        }
}
int count=0;
void counter(int num[],int i,int j){
        int x=num[i-1];
        if(x==j){
                count++;
        }
        if(x<=j){
                if(TD[i-1][j-x]){
                        counter(num, i-1,j-x);
                }
                if(TD[i-1][j]){
                        counter(num,i-1,j);
                }  
        }
        if(x>j){
                if(TD[i-1][j]==1){
                        counter(num,i-1,j);
                }
        }
}
void counter2(int num[],int i,int j){
        int x=num[i-1];
        if(x==j){
                count++;
        }
        if(x<=j){
                if(TD[i-1][j-x]){
                        counter(num, i-1,j-x);
                }
        }
        if(TD[i-1][j]==1){
                counter(num,i-1,j);
        }
}
int main(){
        int n=0, sum=0, num[10];
        int result=0;
        int i=0,j=0;
        printf("Enter the size of arr : ");
        scanf("%d", &n);
        // printf("Enter the sum : ");
        // scanf("%d", &sum);
        
        printf("Enter the arr : ");
        for(int i=0;i<n;i++)
                scanf("%d",&num[i]);
        
        // printf("Hello,");
        // printf("Result : %d", SS(num, sum,n));
// =============== SubSetSumProblem()
        //Initialization
        
        for(int i=0;i<n+1;i++){
                for(int j=0;j<sum+1;j++){
                        if(i==0)
                                TD[i][j]=0;
                        if(j==0)
                                TD[i][j]=1;
                }
        }
// Equal sum Partition
        for(int i=0;i<n;i++)
                sum+=num[i];
        if(sum%2!=0)
                result=0;
        else if(sum%2 == 0){
                sum/=2;

                //Subset sum problem
                for(int i=1;i<n+1;i++){
                        for(int j=1;j<sum+1;j++){
                                if(num[i-1]<=j){
                                        TD[i][j]= ( TD[i-1][j-num[i-1]] || TD[i-1][j] );
                                }
                                else if(num[i-1]>j)
                                        TD[i][j]=TD[i-1][j];
                        }
                }
                //Final result
                result=TD[n][sum];
        }
        printf("Result : %d\n", result);
        for(int i=0;i<=n;i++){
                for(int j=0;j<=sum;j++)
                        printf("%d\t", TD[i][j]);
                printf("\n");        
        }

        print(num,n,sum);
        counter(num,n,sum);
        printf("\nnumber of subset of sum : %d",count);

        // i=n;
        // j=sum;
        // printf("--------------------------\nArray : ");
        // while(i>0 && j>0 ){
        //         if(TD[i-1][j]==1){
        //                 i=i-1;
        //                 continue;
        //         }
        //         else if(j-num[i-1]>=0){
        //                 i--;
        //                 j=j-num[i-1];
        //                 printf("%d\t",num[i]);
        //         }
        // }
        return 0;
}