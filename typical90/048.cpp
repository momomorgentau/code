//048
//I will not drop out
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
  int n,k;
  cin>> n>>k;
  vector<int>A;
  rep(i,n)
  {
int a,b;
    cin>>a>>b;
    A.emplace_back(b);
    A.emplace_back(a-b);
  }
  sort(A.rbegin(),A.rend());
  ll ans=0;
  rep(i,k)ans+=A[i];
  cout<<ans<<endl;
	return 0;
}