#include<stdio.h>

float function(float x,float y);

int main(){
    float x1,y1,h,xFinal;
    printf("Enter the initial values of x and y: ");
    scanf("%f %f",&x1,&y1);
    printf("Enter the final value of x: ");
    scanf("%f", &xFinal);
    printf("Enter the value of h: ");
    scanf("%f", &h);

    while(x1<=xFinal){
      printf("At x=%6.5f  y=%6.5f\n",x1,y1);
      y1 = y1 + (h*function(x1+(h/2), y1 + (h/2)*function(x1,y1)));
      x1+=h; 
    }
    return 0;
}
float function(float x,float y){
    return -1*(x*y);
}
