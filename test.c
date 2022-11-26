#include<stdio.h>

float eval(float *arr,int n,float x);

int main(){
    int n;
    float x;
    printf("enter the order of polynomial:");
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
    for (int i = 0; i < 5; i++)
    {
        printf("Enter value of x: ");
        scanf("%f",&x);
        printf("%f\n",eval(arr,n,x));
    }
    
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