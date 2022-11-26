#include<stdio.h>
int main()
{
	int i,j,n;
	float h,sum,integral;
	printf("Enter the value of h :");
	scanf("%f",&h);
	
	if(h>1){
		printf("Value is not suitable");
		return 0;
	}
	
	printf("Enter no. of terms: ");
	scanf("%d",&n);
	float f[n+1];

	for(i=1;i<n+1;i++){
	 printf("Enter the value of f[%d]",i);
	 scanf("%f",&f[i]);
	 sum =(f[1]+f[n])/2;
    } 

    for(j=2;j<n;j++){
    	sum += f[j];
	}

	integral = h * sum;
	printf("Value of integral = %f \n",integral);
	
	return 0;
}