#include<stdio.h>

int main(){
    int i, n;
    double r;

    printf("Enter the value of r : ");
    scanf("%lf",&r);
    printf("Enter the order of polynomial : ");
    scanf("%d",&n);
    if (n<0){
        printf("You can't enter negative value of n !!");
        return 0;
    }
    
    float a[n+1];
    float b[n];
	for(i=n;i>=0;i--){
		printf("Enter the cofficient of a[%d]: ",i);
		scanf("%f",&a[i]);
	}

    b[n-1] = a[n];
    for (i=1; i<=n-1;i++){
        b[n-i-1] = a[n-i] + r*b[n-i];
    }
    printf("The given polynomial is: ");
    for(i=n;i>=1;i--){
        printf("(%.0lf*x^%d) + ",a[i],i);
    }
    printf("%.0lf\n",a[0]);
    printf("The quotient after division is: ");
    for(i=n-1;i>=1;i--){
        printf("(%.0lf*x^%d) + ",b[i],i);
    }
 
    
    return 0;
}
