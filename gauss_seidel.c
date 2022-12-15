#include<stdio.h>

float relErr(float num1, float num2){
    float diff = num1-num2>=0 ? num1-num2 : num2-num1;
    return (diff/num2);
}

int main(){
    int n,maxItr;
    float err;
    printf("Enter the order of equations : ");
    scanf("%d",&n);

    /*
    The coefficients are stored in a 2-dimensional array from a11 to a1(n+1) 
    and so on
    */
    float coeff[n][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            printf("Enter the coefficient of arr[%d][%d] : ",i,j);
            scanf("%f",&coeff[i][j]);
        }
    }

    printf("Enter the value of err and max iterations: ");
    scanf("%f %d",&err, &maxItr);
    //Declare an array to store the values of Xi's and setting all of them to zero
    float x[n];
    for(int i=0;i<n;i++) x[i]=0;

    for(int k=1;k<=maxItr;k++){
        float big = 0;
        for(int i=1;i<=n;i++){
            float sum=0;
            for(int j=1;j<=n;j++){
                if(i!=j){
                    sum = sum + (coeff[i-1][j-1]*x[j-1]);
                }
            }
            float temp = (coeff[i-1][n+1-1]-sum)/coeff[i-1][i-1];
            //printf("The relative err is: %f", relErr(x[i-1], temp));
            if(relErr(x[i-1], temp)>big){
                big = relErr(x[i-1], temp);
            }
            x[i-1] = temp;
        }
        if(big<=err){
            printf("\nConverges to solution: ");
            for(int i=1;i<=n;i++){
                printf("x(%d)=%f ",i,x[i-1]);
            }
            int dump = 0;
            scanf("%d", dump); //To hold the output on the screen
            return 0; //Equivalent to stopping the program
        }
    }
    printf("Does not converge in given iterations");
    printf("Following are the corresponding values of X's obtained: ");
    for(int i=1;i<=n;i++){
        printf("x(%d)=%f ",i,x[i-1]);
    }
    return 0;
}