// find sum of fibonacci series
#include<stdio.h>
int main(){
    int n,i;
    double a,b,c,sum;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    if (n<0)
    {
        printf("You can't enter negative value of n");
    }
    
    a=0;
    b=1;
    sum = 0;
    for(i=1;i<=n;i++){
        printf("%.0lf, ",a);
        c = a+b;
        a=b;
        b=c;
        
    }
    a=0;
    b=1;
    c=0;
    for(i=1;i<n;i++){
    	c= a+b;
    	a=b;
    	b=c;
    	sum += a;
	}
    printf("\nThe sum of fibonacci series is = %.0lf\n",sum);
    return 0;
}