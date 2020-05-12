// coin change problem mininum number of coins 
#include<stdio.h>
#define INT_MAX 32768

int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int TD[20][20];
int CC(int a[],int amt,int n){
    for(int i=0;i<n+1;i++)
        for(int j=0;j<amt+1;j++){
            if(i==0)
                TD[i][j]=INT_MAX;
            if(j==0)
                TD[i][j]=0;
        }

    for(int j=1;j<amt+1;j++)
        TD[1][j]=(j%a[0]==0)?j/amt:INT_MAX;
    
    for(int i=1;i<n+1;i++)
        for(int j=1;j<amt+1;j++){
            if(a[i-1]<=j)
                TD[i][j]=min(1+TD[i][j-a[i-1]],TD[i-1][j]);
            else
                TD[i][j]=TD[i-1][j];
        }
    
    return TD[n][amt];
}
int main(){
    int a[]={1,2,3,5},n=4;
    int amt=9;
    // for(int i=0;i<11;i++){
    //     // for(int x=n)
    //     printf("%d coins is %d\n",i,CC(a,i,n));}
         printf("amt %d coins %d\n",20,CC(coin,20,n));
    return 0;
}