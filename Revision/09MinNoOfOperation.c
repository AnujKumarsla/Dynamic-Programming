#include<stdio.h>

int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int LCS(char str1[],char str2[],int a,int b){
    if(a==0 || b==0)
        return 0;
    if(str1[a-1]==str2[b-1])
        return 1+LCS(str1,str2,a-1,b-1);
    else
        return max(LCS(str1,str2,a-1,b), LCS(str1,str2,a,b-1));
}
int nOp(char str1[],char str2[],int a,int b,int op[]){
    int lcs=0,del=0,ins=0;
    lcs=LCS(str1,str2,a,b);
    ins=b-lcs;
    del=a-lcs;
    op[0]=ins;
    op[1]=del;
    return ins+del;
}

int TD[20][20];
int LCStr(char str1[],char str2[],int a,int b){
    int result=0;
    for(int i=0;i<a+1;i++)
        for(int j=0;j<b+1;j++){
            if(i==0 || j==0)
                TD[i][j]=0;
        }
    for(int i=1;i<a+1;i++)
        for(int j=1;j<b+1;j++){
            if(str1[i-1]==str2[j-1]){
                result=max(TD[i][j]=1+TD[i-1][j-1],result);
                }
            else
                TD[i][j]=0;
        }

    return result;
}
int SCSS(char str1[],char str2[],int a,int b){
    int lcs;
    lcs=LCS(str1,str2,a,b);
    return a+b-lcs;
}
int main(){
    char str1[10],str2[10];
    int m,n;
    int op[2];
    printf("Enter the Size of the str1, and str2 : ");
    scanf("%d %d",&m,&n);

    printf("Enter the String str1,str2 : ");
    scanf("%s %s",str1,str2);

    printf("The Longest Common Substr : %d\n",LCStr(str1,str2,m,n));
    printf("The Longest Common Subsquences : %d\n",LCS(str1,str2,m,n));
    printf("The Shortest Common SuperSequences : %d\n",SCSS(str1,str2,m,n));
    printf("The Number of Operations : %d\n",nOp(str1,str2,m,n,op));
    printf("insert = %d\tdel = %d",op[0],op[1]);

    return 0;
}