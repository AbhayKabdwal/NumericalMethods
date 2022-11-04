#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main(){
    int i = 0;
    long long whole=0,fraction=0; 
    cout<<"Enter the binary string : "<<"\n";
    char bin[32];
    cin.getline(bin,32);
    while (bin[i] != '.')
    {
        i++;
    }
    int j;
    for (j=i-1; j >=0 ; j--)
    {
    
        whole+=(pow(2,j-i+1)*bin[j]);
    }
    cout<<i<<"\n";
    cout<<whole<<"\n";
}
