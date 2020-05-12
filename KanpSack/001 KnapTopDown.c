#include <stdio.h>

int max(int a, int b){
        if(a<=b)
                return b;
        return a;
}

int check(int wt[], int val[], int i, int j,int TD[][19]){
        int v1=-1, v2=-1;
        if(wt[i-1]<=j)
                v1=val[i-1]+TD[i-1][j-wt[i-1]];
        v2=TD[i-1][j];
        if(v1<v2)
                return j;
        else if(v1>v2)
                return (j-wt[i-1]);
        else if(v1==v2)
                return 0;
}

int Recheck(int wt[], int val[], int i, int j,int TD[][19]){
        int out=0;
        if(j==0)
                return 0;
        out=check(wt,val,i-1,3,TD);
        printf("%d\t",out);
        return Recheck(wt,val,i-1,out,TD);
}
int TD[19][19];
void show(int wt[], int val[], int W, int n){
        int y=0;
        int out=0;
        printf("\t");
        for(int i=0;i<=W;i++){
                printf("%d ",i);
        }
        printf("\n");
        for(int i=0;i<=n;i++){
                for(int j=0;j<=W;j++){
                        if(i==0 || j==0){
                                if(i>0 && j==0)
                                        printf("%d %d\t",wt[i-1],val[i-1]);
                                else if(i==0 && j==0)
                                        printf("0 0\t");
                        }
                        
                printf("%d ",TD[i][j]);
/*                if(i==n && j==W){
                        // out= check(wt,val,i,j,TD);
                        // out= check(wt,val,i-1,3,TD);
                        y=j;
                        for(int x=i;x>=0;x){
                                y=check(wt,val,x--,y,TD);
                                printf("%d\t",y);
                        }
                }
                        // out= check(wt,val,i-2,1,TD);
                // printf("\n");
                //         Recheck(wt,val,i,j,TD);*/
                }
                printf("\n");
        }
        // return out;
}
int main()
{
        int wt[20],val[20];
        int n,W;
        int lst=0;
        int y;
        printf("Hello, world!\n");
        
        printf("Enter the no. of Items : ");
        scanf("%d",&n);
        
        printf("Enter the Total Weight : ");
        scanf("%d",&W);

        printf("Enter the weight array : ");
        for(int i=0;i<n;i++)
                scanf("%d",&wt[i]);
        printf("Enter the value array : ");
        for(int i=0;i<n;i++)
                scanf("%d",&val[i]);

        // Initialization
        for(int i=0;i<=n;i++)
                for(int j=0;j<=W;j++)
                        if(i==0 || j==0)
                                TD[i][j]=0;
        
        for(int i=1;i<=n;i++)
                for(int j=1;j<=W;j++){
                        if(wt[i-1]<=j){
                                TD[i][j]=max(val[i-1]+TD[i-1][j-wt[i-1]],TD[i-1][j]);
                        }
                        else if(wt[i-1]>W){
                                TD[i][j]=TD[i-1][j];
                        }
                }
                
        // printf("\n%d",show(wt,val,W,n));
        show(wt, val,W,n);
        y=W;
        for(int x=n;x>=0;x){
                y=check(wt,val,x--,y,TD);
                printf("%d\t",y);
        }

        return 0;
}