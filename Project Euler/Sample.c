
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int a,int b)
{
    if(a<b)
        return b;
    return a;
}
int main()
{
    int A[20][20],B[20][17],C[17][20];
    int D[17][17],E[17][17];int LG=0;
    int lb=0,lc=0,ld=0,le=0;
    int row,col;

    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            scanf("%d",&A[i][j]);
    // Along the row --->
    for(int i=0;i<20;i++)
        for(int j=0;j<17;j++)
            B[i][j]= A[i][j]*A[i][j+1]*A[i][j+2]*A[i][j+3];

    //Along the column   ^
    for(int i=0;i<17;i++)
        for(int j=0;j<20;j++)
            C[i][j]= A[i][j]*A[i+1][j]*A[i+2][j]*A[i+3][j];
    //Digonal /*  \ */
    for(int i=0;i<17;i++)
        for(int j=0;j<17;j++)
        {
            row=i;col=j+3;
            D[i][j]=A[row][col]*A[row+1][col+1]*A[row+2][col+2]*A[row+3][col+3];
        }
    //Digonal /
    for(int i=0;i<17;i++)
        for(int j=0;j<17;j++)
        {
            row=i+3;col=j;
            E[i][j]=A[row][col]*A[row-1][col+1]*A[row-2][col+2]*A[row-3][col+3];
        }

    for(int i=0;i<20;i++)
        for(int j=0;j<17;j++)
            if(lb<B[i][j])
                lb=B[i][j];
    printf("Result : %d\n",lb);
    
    for(int i=0;i<17;i++)
        for(int j=0;j<20;j++)
            if(lc<C[i][j])
                lc=C[i][j];
    printf("Result : %d\n",lc);

    for(int i=0;i<17;i++)
        for(int j=0;j<17;j++)
            if(ld<D[i][j])
                ld=D[i][j];
    printf("Result : %d\n",ld);

    for(int i=0;i<17;i++)
        for(int j=0;j<17;j++)
            if(le<E[i][j])
                le=E[i][j];
    printf("Result : %d\n",le);

    LG=Max(lb,lc);
    LG=Max(LG,ld);
    LG=Max(LG,le);
    printf("%d",LG);
    return 0;
}

