//ABC_201_A
//Tiny_Arithmetic_Sequence
//12
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	vector<int> a(3);
	rep(i, 3) cin >> a[i];
	sort(a.begin(), a.end());
	if (a[2] - a[1] == a[1] - a[0]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}