#include <stdio.h>
int main(){
 int n,i;
 printf("enter the order of polynomial: ");
 scanf("%d",&n);
 int arr[n+1];
 for(i=n;i>=0;i--);
 {
  printf("enter the cofficient of a[%d] ",i);
  scanf("%d",&arr[i]);
 }
 for(i=0;i<n;i++);
 {
  printf("cofficient of a[%d] is %f",i,arr[i]);
 }
}
