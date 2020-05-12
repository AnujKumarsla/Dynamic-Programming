#include<stdio.h>
// #include<math.h>
#define INT_MAX 32768;
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
// int counter=0;
int mcm(int a[],int i,int j){
    int temp=0,mm=INT_MAX;
    // counter++;
    if(i>=j){
        // printf("%d. i%d, j%d \n",counter,i,j);
        return 0;}
    for(int k=i;k<=j-1;k++){
        temp = mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        // printf("%d. c1%d c2%d c3%d temp %d i%d,k%d,j%d \n",counter,c1,c2,c3,temp,i,k,j);
        if(temp<mm)
            mm=temp;
    }
    return mm;
}
int main(){
    int a[]={4,2,3,5};
    int i=1,j=3;
    printf("The result is the : %d",mcm(a,i,j));
    return 0;
}