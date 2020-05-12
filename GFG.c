#include <stdio.h>
int TD[20][100];

// int min(int a,int b){
//     if(a<b)
//         return a;
//     return b;
// }


int SS(int num[],int sum,int n){
    
    for(int i=0;i<n+1;i++)
        for(int j=0;j<sum+1;j++){
            if(i==0)
                TD[i][j]=0;
            if(j==0)
                TD[i][j]=1;
        }
            
        
    for(int i=1;i<n+1;i++)
        for(int j=1;j<sum+1;j++){
            if(num[i-1]<=j)
                TD[i][j]=( TD[i-1][j-num[i-1]] || TD[i-1][j] );
            else if(num[i-1]>j)
                TD[i][j]=TD[i-1][j];
        }
    
    return TD[n][sum];
}

int MSD(int num[],int n){
    int i,sum=0,s1=0;
    for(i=0;i<n;i++)
        sum+=num[i];

        // printf("sum : %d\n",sum);
    SS(num,sum/2,n);
    
    for(i=sum/2;i>0;i--){
        //     printf("HEllo, i=%d, TD=%d\n",i,TD[n][i]);
        if(TD[n][i]){
            return (sum-(2*i));
            break;
        }
        //     s1=i;
        //     printf("Hell0 i=%d, s1=%d",i,s1);
        //     break;
    }
    return 0;
//     printf("%d s1=%d\n",sum-(2*s1),s1);
}
int main() {
	int T=0,n[5],num[5][19];
	scanf("%d",&T);
	for(int i=0;i<T;i++){
	    
	    scanf("%d",&n[i]);
	    for(int j=0;j<n[i];j++)
	        scanf("%d",&num[i][j]);
	        
	}
	for(int i=0;i<T;i++){
	    printf("%d\n",MSD(num[i],n[i]) );
	}
	
	return 0;
}