#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


int main(){
  int n, x;
  n = 5;
  x = 9;

  int cnt =0;
  rep(i,n)rep(j,n)rep(k,n){
    if(i>=j) continue;
    if(j>=k) continue;
    if(i + j + k == x-3) ++cnt;

  } 
  cout <<  cnt <<endl;
}