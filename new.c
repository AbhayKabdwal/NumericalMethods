#include<stdio.h>
#include<math.h>

int main(){
  float x0,x1,e,del;
  int n,m;

  printf("Enter x0 , e , del , n , m\n" );
  scanf("%f %f %f %d %d\n",&x0,&e,&del,&n,&m);
  float arr[n+1],arr1[n];

  printf("Enter coefficients of polynomial!");
  for (int i = n; i >=0 ; i--) {
    printf("Enter the coefficient of a[%d]:\n",i );
    scanf("%f",&arr[i]);
  }

  printf("Enter coefficients of differential of polynomial!");
  for (int i = n-1; i >=0 ; i--) {
    printf("Enter the coefficient of a[%d]: ",i );
    scanf("%f",&arr1[i]);
  }

  for (int i = 0; i < m; i++) {
    float y0,y1;
    y0=arr[n];
    for (int j = n-1; j >= 0; j--) {
      y0 = arr[j] + y0*x0;
    }
    y1=arr1[n];
    for (int j = n-2; j >= 0; j--) {
      y1 = arr1[j] + y1*x0;
    }
    if (fabs(y1)<=del) {
      printf("Slope is too small x0 = %f f0 = %f f'0 = %f iteration = %d",x0,y0,y1,i );
      return 0;
    }
    x1 = x0 - (y0/y1);
    if (fabs((x1-x0)/x1) <= e) {
      printf("Converges to root x1 = %f f0 = %f iterations = %d",x1,y0,i );
      return 0;
    }
  }
  return 0;
}
