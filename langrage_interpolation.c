#include<stdio.h>

int main(){
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    float x,xarr[n],farr[n],prodfun;
    printf("Enter value of x at which point is to be interpolated: ");
    scanf("%f",&x);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter value of x[%d] and f[%d]: ",i,i);
        scanf("%f , %f",&xarr[i],farr[i]);
    }
    
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        prodfun = 1;
        for (int j = 1; j <= n; j++)
        {
            if (j != i)
            {
                prodfun *= (x - xarr[i]) / (xarr[i] - xarr[j]);
            }
        }
        sum += farr[i] * prodfun;
    }
    printf("At x = %f , functional value = %f",x,sum);
    return 0;
}