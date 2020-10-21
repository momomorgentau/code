//diff 0
//abc173_a_payment

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int ans = 1000 - n % 1000;
  if(ans == 1000) ans = 0;
  cout << ans << endl;
  return 0;
}