#include<stdio.h>
#include<string.h>
#define INI_MAX 32768
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int isPalindrom(char a[],int start,int end){
    if(start>=end)
        return 1;
    while(start<end){
        // printf("%c %c \n",a[start],a[end]);
        if(a[start++]!=a[end--])
            return 0;
    }
    return 1;
}
int counter=0;
int static TD[40][40];
void menset(int start,int end){
    for(int i=0;i<start;i++)
        for(int j=0;j<end;j++)
            TD[i][j]=-1;
}
int MPP(char a[],int start, int end){
    int temp,mm=INI_MAX;
    counter++;
    if(start>=end)
        return 0;
        
    if(isPalindrom(a,start,end))
        return 0;

    // if(TD[start][end]!=-1)
    //     return TD[start][end];

    // for(int k=start;k<=end-1;k++){
    //     temp=1+MPP(a,start,k)+MPP(a,k+1,end);
    //     mm=min(mm,temp);
    // }
    for(int k=start;k<=end-1;k++){
        temp=1+
        (TD[start][k]!=-1?TD[start][k]:MPP(a,start,k))+
        (TD[k+1][end]!=-1?TD[k+1][end]:MPP(a,k+1,end));
        mm=min(mm,temp);
    }
    return TD[start][end]=mm;
}
int main(){
    char a[]="ritik";
    int start=0,end=strlen(a)-1;
    menset(end+2,end+2);
    printf("counter %d result : %d",counter,MPP(a,start,end));
    return 0;
}