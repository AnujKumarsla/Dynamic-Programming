// Minimum number of palindrom partition
// here start is the first index, end is last index of the string;
#include<stdio.h>
#define INT_MAX 32768
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int isPalindrome(char a[],int start,int end){
    int n=end-start+1;
    for(int i=0;i<n/2;i++){
        // printf("H %c %d %c %d\n",a[start+i],start+i,a[end-i],end-i);
        if(a[start+i]!=a[end-i])
            return 0;}
    
    return 1;
}
int MNP(char a[],int start,int end){
    int temp=0,mm=INT_MAX;
    if(start>=end)
        return 0;
    if(isPalindrome(a,start,end))
        return 0;
    for(int k=start;k<=end-1;k++){
        temp=MNP(a,start,k)+MNP(a,k+1,end)+1;
        mm=min(mm,temp);
    }

    return mm;
}

int main(){
    char a[]="ABCBAisi";
    int start=0,end=7;
    // printf("is Plindrom %s %d\n",a,isPalindrome(a,start,4));
    // printf("is Plindrom %s %d\n",a,isPalindrome(a,5,end));
    printf("The minimum number of Plindrome Partition : %d",MNP(a,start,end));
    return 0;
}