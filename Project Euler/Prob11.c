#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int find(int arr[20][20]){
    int rmax,dmax,TRDmax,DLDmax,mul;
    int tmax;
    for(int i=0;i<20;i++)
        for(int j=0;j<17;j++){
            mul=arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3];
            rmax=max(rmax,mul);
        }
    
    for(int i=0;i<17;i++)
        for(int j=0;j<20;j++){
            mul=arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j];
            dmax=max(dmax,mul);
        }
    
    for(int i=0;i<17;i++)
        for(int j=0;j<17;j++){
            mul=arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3];
            TRDmax=max(TRDmax,mul);

        }
    for(int i=0;i<17;i++)
        for(int j=3;j<20;j++){
            mul=arr[i][j]*arr[i+1][j-1]*arr[i+2][j-2]*arr[i+3][j-3];
            DLDmax=max(DLDmax,mul);

        }

    tmax=max(rmax,dmax);
    tmax=max(tmax,TRDmax);
    tmax=max(tmax,DLDmax);
    return tmax;


}
int main(){
    int arr[20][20];
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            scanf("%d",&arr[i][j]);
        
    printf("The Result : %d",find(arr));
    return 0;
}