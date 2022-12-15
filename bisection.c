#include<stdio.h>
#include<math.h>

int sign(float x,float y);
float eval(float *arr,int n,float x);

int main()
{
	int n,i=0,j;
	float x,lower_bound,upper_bound;
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
	printf("Enter lower bound : ");
	scanf("%f",&lower_bound);
	printf("Enter upper bound : ");
	scanf("%f",&upper_bound);
	for(x=lower_bound;x<=upper_bound;x=x+1){
	printf("value of y(%.2f) : %.2f\n",x,eval(arr,n,x));}

	//Taking values of x0, x1, e
	float x0,x1,e,x2;
	printf("Enter the value of x0 ,x1 ,e: ");
	scanf("%f %f %f",&x0,&x1,&e);
	
	//Calculating y0,y1 for condition inside loop
	float y0,y1,y2;
	y0=arr[n];
	y1=arr[n];
	for(i=n-1;i>=0;i--)
	{
		y0=arr[i]+x0*y0;
		y1=arr[i]+x1*y1;
	}
	//if y0 == 0 then x0 is a root
	if (y0==0)
	{
		printf("x0 = %f is a root of polynomial!!",x0);
		return 0;
	}
	//if y1 == 0 then x1 is a root
	else if (y1==0)
	{
		("x1 = %f is a root of polynomial!!",x1);
		return 0;
	}
	//if signs of y0 and y1 are same then root cannot be calculated by this method
	else if (sign(y0,y1))
	{
		printf("Starting values are unsuitable\n");
		printf("Values of x0,x1,y0,y1,e: %f %f %f %f %f\n",x0,x1,y0,y1,e);
		return 0;
	}

	//iterating when magnitude of (x1-x0)/x0 or relative error of x1 is greater than e
    while(fabs((x1-x0)/x1)>e){

        x2=(x1+x0)/2;
        y2=arr[n];
		for(j=n-1;j>=0;j--)
		{
			y2=arr[j]+x2*y2;
		}
		i=i+1;
		//replacing values of x0 or x1 to x2 based on sign of y0 and y1
		if (sign(y0,y2)){
			x0=x2;
			y0=y2;
		}
		else{
			x1=x2;
			y1=y2;
		}
	}
	
	printf("No. of iterations : %d\n",i);
	printf("Value of root : %f\n",x2);
	
	return 0;
}

//function which returns 1 if sign of two arguments is same else returns 0
int sign (float x,float y)
	{
	 if (x*y>0)
	 return 1;
	 else if(x*y<0)
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
