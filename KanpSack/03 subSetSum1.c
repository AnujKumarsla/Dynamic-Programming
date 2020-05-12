#include<stdio.h>
int TD[10][40];
void print(int arr[], int i,int j){
        int x=arr[i-1];
        if(x==j){
                printf("%d ",x);
                if(TD[i-1][j]==1){
                        printf("\n");
                        print(arr,i-1,j);
                }
        }
        if(x<j){
                if(TD[i-1][j-x]==1){
                        printf("%d ",x);
                        print(arr,i-1,j-x);
                }
        }
        if(x>j && TD[i-1][j]){
                print(arr,i-1,j);
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
int myCount=0;
int printer(int num[],int i,int j){
        int x=num[i-1];
        printf("%d. i %d j %d x %d TD[%d][%d] num[%d]=%d \n",myCount++,i,j,x,i,j,i-1,num[i-1]);
        int success=0;
        if(x==j){
                count++;
                printf("%d\n",x);
                success=1;
        }
        if(x<=j){
                if(TD[i-1][j-x]){
                        success=printer(num, i-1,j-x);
                        if(success){
                                printf("%d ",x);
                        }
                }
        }
        if(TD[i-1][j]==1){
                success=printer(num,i-1,j);
        }
        return success;
}
int main(){
        int n=0, sum=0, num[10];
        int result=0;
        int i=0,j=0;
        printf("Enter the size of arr : ");
        scanf("%d", &n);
        printf("Enter the sum : ");
        scanf("%d", &sum);
        
        printf("Enter the arr : ");
        for(int i=0;i<n;i++)
                scanf("%d",&num[i]);
        
        //initialize
        for(int i=0;i<n+1;i++){
                for(int j=0;j<sum+1;j++){
                        if(i==0)
                                TD[i][j]=0;
                        if(j==0)
                                TD[i][j]=1;
                }
        }

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
        printf("Subset Sum Result : %d\n", result);
        for(int i=0;i<=n;i++){
                for(int j=0;j<=sum;j++)
                        printf("%d\t", TD[i][j]);
                printf("\n");        
        }

        // print(num,n,sum);
        printer(num,n,sum);
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