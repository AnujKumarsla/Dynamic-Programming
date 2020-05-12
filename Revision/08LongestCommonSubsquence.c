#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int LCS(char str1[],char str2[],int m,int n){
    if(m==0 || n==0)
        return 0;
    else if(str1[m-1]==str2[n-1])
        return 1+LCS(str1,str2,m-1,n-1);
    else if(str1[m-1]!=str2[n-1])
        return max(LCS(str1,str2,m-1,n),LCS(str1,str2,m,n-1));
}

int SCSS(char str1[],char str2[],int a,int b){
    return (a+b-LCS(str1,str2,a,b));
}
int TD[20][20];
int result =0;
int LCStr(char str1[],char str2[],int a,int b){
    for(int i=0;i<a+1;i++)
        for(int j=0;j<b+1;j++){
            if(i==0 || j==0)
                TD[i][j]=0;
        }

    for(int i=1;i<a+1;i++)
        for(int j=1;j<b+1;j++){
            if(str1[i-1]==str2[j-1])
                // result=max(result,TD[i][j]=1+TD[i-1][j-1]);
                result,TD[i][j]=1+TD[i-1][j-1];
            else 
                TD[i][j]=0;
            result=max(result,TD[i][j]);

        }
    
    return result;
}
int main(){
    char str1[10],str2[10];
    int m,n;
    printf("Enter the Size of the str1, and str2 : ");
    scanf("%d %d",&m,&n);

    printf("Enter the String str1,str2 : ");
    scanf("%s %s",str1,str2);

    printf("The Longest Common Subsquences : %d\n",LCS(str1,str2,m,n));
    printf("The Longest Common SubString : %d\n",LCStr(str1,str2,m,n));
    printf("The Length of Shortest Common Subsquences : %d\n",SCSS(str1,str2,m,n));

    return 0;
}