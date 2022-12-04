#include<stdio.h>
#include<math.h>

float eval(float *arr,int n,float x);

int main(){
    int n;
    float x,x1,x2,e,h;
    printf("Enter x1, x2, e: ");
    scanf("%f %f %f",&x1,&x2,&e);
    h=(x2-x1)/2;
    
    
    printf("Enter order of polynomial:  ");
  	scanf("%d",&n);
  	float f[n+1];
  	for(int i=n;i>=0;i--){
  		printf("enter the value of a[%d]: ",i);
  		scanf("%f",&f[i]);
    }

    int i = 2;
    float s1 = eval(f,n,x1) + eval(f,n,x2);
    float s2 = 0;
    float s4 = eval(f,n,x1+h);
    float I0 = 0;
    float In = (s1 + 4*s2) * (h/3);

    while(fabs((In - I0)/In)>=e){
        s2 = s2+s4;
        s4 = 0;
        x = x1 + h/2;
        for (int j = 1; j < i; j++)
        {
            s4 = s4 + eval(f,n,x);
            x = x + h;
        }
        h = h/2;
        i = 2*i;
        I0 = In;
        In = (s1 + 2*s2 + 4*s4) * (h/3);

    }

    printf("Integration using simpson two point form is %f \n",In);
    printf("Values of h and i are : %f %d\n",h,i);
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