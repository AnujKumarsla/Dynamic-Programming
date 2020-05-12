#include <stdio.h>
#define INT_MAX 32768
int NCoin(int coin[], int amt, int n)
{
    if (amt == 0)
        return 1;
    else if (n == 0)
        return 0;
    else if (coin[n - 1] <= amt)
        return (NCoin(coin, amt - coin[n - 1], n) + NCoin(coin, amt, n - 1));
    else if (coin[n - 1] > amt)
        return NCoin(coin, amt, n - 1);
}
int main()
{
    int coin[20], n, amt;
    printf("Enter the n,amt,coin : \n");+
    scanf("%d %d", &n, &amt);
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);
    printf("number of Ways coins : %d\n", NCoin(coin, amt, n));
    printf("Hello, World!");
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<amt+1;j++)
    //         printf("%d\t",TD[i][j]);
    //     printf("\n");
    // }
    return 0;
}