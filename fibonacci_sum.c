#include<stdio.h>
int main(){
int a = 0, b = 1, sum = 0, c = 0, n;
printf("Enter the sum upto which Fibonacci series is to be printed: ");
scanf("%d",&n);
while(b<=n){
	printf("%d\t",a);
    sum = a+b;
    a = b;
    b = sum;
	c += a;
    }
}
