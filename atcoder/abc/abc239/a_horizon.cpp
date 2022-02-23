//----------------------------
//ABC_239_A
//Horizon
//21
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	double h; cin >> h;
	double ans = sqrt(h * (12800000 + h));
	printf("%.7f\n", ans);
}