#include <stdio.h>
#include <math.h>

float eval(float *arr,int n,float x);

int main(){
    int m,k;
    float x,x1,h,e,s1,I0,I1;
    printf("Enter the values of x1,h,k,e: ");
    scanf("%f %f %d %f",&x1,&h,&k,&e);
    printf("Enter order of polynomial : ");
    scanf("%d",&m);

    float arr[m+1];
    for (int j = m; j >= 0; j--){
        printf("Enter coefficient of a[%d] : ",j);
        scanf("%f",&arr[j]);
    }
    x = x1;
    float arr1[k+1];
    for (int i = 1; i <= k; i++){
        arr1[i] = eval(arr,m,x);
        x += h;
    }
    s1 = (arr1[1] + arr1[k]) / 2;
    for (int j = 2; j <= k-1; j++){
        s1 += arr1[j];
    }
    I1 = h * s1;
    int i = k-1;

    while (fabs((I1 - I0)/I1) > e){
        I0 = I1;
        x = x1 + h/2;
        for (int j = 1; j <= i; j++){
            s1 = s1 + eval(arr,m,x);
            x += h;
        }
        i *= 2;
        h /= 2;
    }
    I1 = s1 * h;
    printf("Integration is %f",I1);
    return 0;
}

float eval(float *arr,int n,float x){
    float y;
    y=arr[n];
    for(int i=n;i>0;i--){
		y=arr[i-1]+x*y;
	}
    return y;
}
