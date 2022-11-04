#include<iostream>

int main() {
  int a[]={1,2,5,2,6,1,3,7};

  for(auto x:a){
    std::cout<<x<<" ";
  }
  return 0;
}
