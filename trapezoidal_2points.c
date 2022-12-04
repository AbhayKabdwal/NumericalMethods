#include <stdio.h>
#include <math.h>

float eval(float *arr,int n,float x);


int main(){

    float x,x1,x2,e,h,s1,s2,s4,I0,I1;
    printf("Enter the value of x1,x2,e: ");
    scanf("%f %f %f",&x1,&x2,&e);

    int n,i;
    printf("Enter order of polynomial: ");
    scanf("%d",&n);
    if (n<0)
    {
        printf("You can't enter negative value of n !!");
        return 0;
    }
	float arr[n+1];
	for(int i=n;i>=0;i--)
	{
		printf("enter the cofficient of a[%d]: ",i);
		scanf("%f",&arr[i]);
	}

    h = (x2-x1)/2;
    i = 2;

    s1 = (eval(arr,n,x1) + eval(arr,n,x2))/2;
    I1 = h * s1;

    while (fabs((I1 - I0)/I1) > e)
    {
        x = x1 + h/2;
        for (int j = 0; j < i; j++)
        {
            s1 = s1 + eval(arr,n,x);
            x += h;
        }
        i *= 2;
        h /= 2;

        I0 = I1;
        I1 = h*s1;
    }
    

    printf("Integrated value using trapeziodal 2 point form rule is %f , h = %f , i = %d\n",I1,h,i);
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