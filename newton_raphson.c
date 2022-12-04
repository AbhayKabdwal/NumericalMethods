#include <stdio.h>
#include <math.h>

float eval(float *arr,int n,float x);

int main(){
    int n,i,m;
    float x0,x1,e,d,y0,y1,y_0;
    printf("Enter order of polynomial : ");
    scanf("%d",&m);

    float arr[m+1];
    for (int j = m; j >= 0; j--)
    {
        printf("Enter coefficient of a[%d] : ",j);
        scanf("%f",&arr[j]);
    }
    
    float arr1[m];
    for (int j = m-1; j >= 0; j--)
    {
        printf("Enter coefficient of a'[%d] : ",j);
        scanf("%f",&arr1[j]);
    }

    printf("Enter x0, e, i, d :");
    scanf("%f %f %d %f",&x0,&e,&n,&d);
    
    for(int i = 1; i<n; i++)
    {   
        y0 = eval(arr, m, x0);
        y_0 = eval(arr1, m-1, x0);
        
        if (fabs(y_0) == d)
        {
            printf("Slope too small \n x0 = %f , f0 = %f , f'0 = %f , iteration = %d",x0,y0,y_0,i);
            return 0;
        }
        
        x1 = x0 - (y0)/(y_0);
        y1 = eval(arr, m, x1);
        if (fabs((x1-x0)/x1)<=e)
        {
            printf("Converges to root x = %f , f(x) = %f , num of iteration = %d",x1,y1,i);
            return 0;
        }
        x0 = x1;
    }
    printf("Does not converge in %d iterations\n x0 = %f , x1 = %f , f0 = %f , f'0 = %f",n,x0,x1,y0,y_0);
    return 0;
}

float eval(float *arr,int n,float x){
    float y;
    y=arr[n];
    for(int i=n;i>0;i--)
	{
		y=arr[i-1]+x*y;
	}
    return y;
}
