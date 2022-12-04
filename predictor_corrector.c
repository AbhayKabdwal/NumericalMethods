#include<stdio.h>

float eval(float *arr,int mx,int my,float x,float y);

int main(){
    int mx,my;
    float x1,x2,x3,xf,y1,y2,h,s1,s2,s3,y3p,y3c;
    printf("enter the order of x in the polynomial: ");
	scanf("%d",&mx);
    printf("enter the order of y in the polynomial: ");
	scanf("%d",&my);
	if ((mx<0)||(my<0)){
        printf("You can't enter negative value of order !!");
        return 0;
    }
	float arr[mx+1][my+1];
	for(int i=mx;i>=0;i--){
        for (int j = my; j >= 0; j--)
        {
            printf("enter the cofficient of x^%d * y^%d: ",i,j);
		    scanf("%f",&arr[i][j]);
        }
	}
    
    printf("Enter the valeus of x1, y1, xf, h: ");
    scanf("%f %f %f %f",&x1,&y1,&xf,&h);

    printf("%f %f",x1,y1);
    // s1 = eval(arr,m,)
}

// float eval(float *arr,int mx,int my,float x,float y){
//     float y;
//     y=arr[n];
//     for(int i=n;i>0;i--)
// 	{
// 		y=arr[i-1]+x*y;
// 	}
//     return y;
// }