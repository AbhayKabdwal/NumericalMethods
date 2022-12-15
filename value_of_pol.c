#include<stdio.h>
int main()
{
	int n,i,j;
    float y,x;
	printf("Enter the order of polynomial:");
	scanf("%d",&n);
	if (n<0)
    {
        printf("You can't enter negative value of n !!");
        return 0;
    }
	float arr[n+1];
	for(i=n;i>=0;i--)
	{
		printf("Enter the cofficient of a[%d]: ",i);
		scanf("%f",&arr[i]);
	}
    printf("Enter value of x: ");
    scanf("%f",&x);
    y=arr[n];
    for(i=n;i>0;i--)
	{
		y=arr[i-1]+x*y;
	}

    printf("Value of Polynomial : %f\n",y);
    return 0;
}
