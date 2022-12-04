#include<stdio.h>
int main()
{
  int i,n,j,k;
  float h,sum,integral;
  printf("enter the value of h");
  scanf("%f",&h);
  if(h>1){
  	printf("h is not suitable");
  	return 0;
  }
  
  printf("enter the no. of terms:");
	scanf("%d",&n);
  float f[n+1];
	for(i=1;i<n+1;i++){
  	printf("enter the value of a[%d]",i);
  	scanf("%f",&f[i]);
  }
  sum = (f[1]+f[n]);
  for(j=2;j<n;j+=2){
    sum=sum+4*f[j];
  }
  for(k=3;k<n-1;k+=2){
	  sum=sum+2*f[k];
  }
  integral = (h*sum)/3;
  printf("Value of integral = %f",integral);
    
  return 0;
}
