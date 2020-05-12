#include<stdio.h>

// ?========================Top Down Approach======================
int TD[12][30];

void TDinit(int n,int sum){
        for(int i=0;i<n+1;i++)
                for(int j=0;j<sum+1;j++){
                        if(i==0)
                                TD[i][j]=0;
                        if(j==0)
                                TD[i][j]=1;
                }
}

void TDSS(int num[],int sum,int n){

        for(int i=1;i<n+1;i++)
                for(int j=0;j<sum+1;j++){
                        if(num[i-1]<=j)
                                TD[i][j]= ( TD[i-1][j-num[i-1]] || TD[i-1][j]);
                        else if(num[i-1]>j)
                                TD[i][j]=TD[i-1][j];
                }
}
int min(int a, int b){
        if(a<=b)
                return a;
        return b;
}

int MSD(int num[],int n){
        int range=0,mn=0;
        int candidate[30];
        for(int i=0;i<n;i++)
                range+=num[i];
        
        TDSS(num,range,n);

        mn=range/2+1;
        for(int i=0;i<=range/2;i++)
                if(TD[n][i]){
                        mn=min(mn,range-(2*TD[n][i]));
                }

        // for(int i=0;i<=range/2;i++)
        //         mn=min(mn,(range-(2*candidate[i]))  );
        
        return mn;


}
/*
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
*/
int main()
{
        int n=0,num[10];
        printf("Hello, world!\n");
        printf("Enter the size of arr : ");
        scanf("%d", &n);
        
        printf("Enter the arr : ");
        for(int i=0;i<n;i++)
                scanf("%d",&num[i]);
        // fun(num,n);
        // printf("Result : %d\n",MSD(num,n));
        printf("Result : %d\n",MSD(num,n));
        return 0;
}