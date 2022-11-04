#include<stdio.h>
#include<math.h>

int sign(float x,float y);

int main() {
  int n,i;
  printf("Enter order of polynomial: ");
  scanf("%d",&n);
  float arr[n+1];
  for (i = n; i >=0 ; i--) {
    printf("Enter coefficient of a[%d]: ",i);
    scanf("%f",&arr[i]);
  }

  float x0,x1,e,x2;
  printf("Enter x0 , x1 , e : ");
  scanf("%f %f %f ",&x0,&x1,&e);

  float y0,y1,y2;
  y0=arr[n];
  y1=arr[n];
	for(i=n-1;i>=0;i--){
	  y0=arr[i]+x0*y0;
    y1=arr[i]+x1*y1;
	}
  i = 0;
  if (sign(y0,y1) == -1) {
    printf("Starting values unsuitable! ");
    printf("Values of x0,x1,y0,y1,e are: %f %f %f %f %f ",x0,x1,y0,y1,e);
  }

  while (fabs((x1-x0)/x1) > e) {
    x2=(x1+x0)/2;
    y2=arr[n];
    for(int j=n-1;j>=0;j--){
  	  y2=arr[j]+x2*y2;
  	}
    i=i+1;
    if(sign(y0,y2)==1)
      x0=x2;
    else
      x1=x2;
  }
  printf("No. of iteration are %d \n",i );
  printf("Values of x and y are %f %f ",x2,y2);
  return 0;
}

int sign(float x,float y){
  if (x*y>0)
    return 1;
  else if (x*y<0)
    return 0;
  else
    return -1;
}
