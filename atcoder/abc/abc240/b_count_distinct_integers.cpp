//----------------------------
//ABC_240_B
//Count Distinct Integers
//19
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
	int n;
	cin >> n;
	set<int> s;
	rep(i, n)
	{
		int a; cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;
	return 0;
}