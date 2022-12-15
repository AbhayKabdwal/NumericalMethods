// #include<stdio.h>

// int main(){
//     int n;
//     printf("Enter value of n: ");
//     scanf("%d",&n);
//     float x,xarr[n],farr[n],prodfun;
//     printf("Enter value of x at which point is to be interpolated: ");
//     scanf("%f",&x);

//     for (int i = 1; i <= n; i++)
//     {
//         printf("Enter value of x[%d] and f[%d]: ",i,i);
//         scanf("%f %f",&xarr[i],&farr[i]);
//     }
    
//     double sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         prodfun = 1;
//         for (int j = 1; j <= n; j++)
//         {
//             if (j != i)
//             {
//                 prodfun *= (x - xarr[i]) / (xarr[i] - xarr[j]);
//             }
//         }
//         sum += farr[i] * prodfun;
//     }
//     printf("At x = %f , functional value = %lf",x,sum);
//     return 0;
// }

#include <stdio.h>

int main() {
    int n;
    float x;
    printf("Please enter the value of x(at which value is to be interpolated) and n: ");
    scanf("%f %d",&x, &n);
    float xVal[n];
    float funcVal[n];
    
    //Reading the tabulated values

    for(int i=0;i<n;i++){
        printf("Enter value of x[%d] and f[%d]\t",i+1,i+1);
        scanf("%f %f", &xVal[i], &funcVal[i]);
    }
    
    float sum = 0;
    for(int i=0;i<n;i++){
        float prodFunc = 1;
        for(int j=0;j<n;j++){
            if(i!=j){
                prodFunc = prodFunc*((x-xVal[j])/(xVal[i]-xVal[j]));
            }
        }
        sum = sum + (funcVal[i]*prodFunc);
    }
    printf("\nThe value of the function is :%f at x=%f",sum, x);
    return 0;
}