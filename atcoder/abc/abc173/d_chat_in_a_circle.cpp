//673
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end(),greater<int>());
  
  ll ans = a[0];
  int n2 = n / 2;
  
  for(int i = 1; i<n2; ++i) ans += a[i]*2;
  if(n&1) ans +=a[n2];
  cout << ans << endl;
  return 0;
}