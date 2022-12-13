#include<stdio.h>

int main(){
    int n;
    float u , sum ;
    printf("Enter number of equations: ");
    scanf("%d",&n);
    float arr[n+1][n+2];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            printf("Enter arr[%d][%d]: ",i,j);
            scanf("%f",arr[i][j]);
        }
        
    }

    for (int k = 1; k < n-1; k++)
    {
        for (int i = k+1; i < n; i++)
        {
            u = (arr[i][k])/(arr[k][k]);
            for (int j = k; j < n+1; j++)
            {
                arr[i][j] = arr[i][j] - u*arr[k][j];
            }
        }
    }
    
    float x[n+1];
    x[n] = (arr[n][n+1])/(arr[n][n]);

    for (int i = n-1; i > 1; i--)
    {
        sum = 0;
        for (int j = i+1; j < n; j++)
        {
            sum = sum + arr[i][j]*x[i];
        }
        x[i] = (arr[i][n+1] - sum)/arr[i][i];
    }

    for (int i = 1; i < n+1; i++)
    {
        printf("%f",x[i]);
    }
    
    return 0 ;
}