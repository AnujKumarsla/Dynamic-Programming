#include<stdio.h>

int solve(char a[],int i,int j,char state){
    int lf,rf,lt,rt,ans=0;
    //  BAse case
    if(i>j)
        return 0;
    if(i==j){
        if(state=='T')//True
            return a[i]=='T';
        else//False
            return a[i]=='F';
    }
        //  Loop
    for(int k=i+1;k<=j-1;k+=2){
        //  Temp ans
        lt=solve(a,i,k-1,'T');
        lf=solve(a,i,k-1,'F');
        rt=solve(a,k+1,j,'T');
        rf=solve(a,k+1,j,'F');
        //  functional ans
        switch(a[k]){
            case '&' : if(state=='T'){
                            ans+=lt*rt;
                            }
                        else{
                            ans+=lf*rt+
                                    lt*rf+
                                    lf*rf;
                            }
                        break;
            case '|' : if(state=='T'){
                            ans+=lt*rt+
                                    lf*rt+
                                    lt*rf;
                            }
                        else{
                            ans+=lf*rf;
                            }
                        break;
            case '^' : if(state=='T'){
                            ans+=lf*rt+
                                    lt*rf;
                            }
                        else{
                            ans+=lt*rt+
                                    lf*rf;
                            }
                        break;
            default : ans=10000;
        }
    }
    return ans;
}
int main(){
    char a[]="T&F|T";
    int i=0,j=4;
    char state='F';
    printf("Result : %d",solve(a,i,j,state));
    return 0;
}
/*
Test Case :
    T&F^T|T : 5 , 0
    T&F|T : 2, 0

*/