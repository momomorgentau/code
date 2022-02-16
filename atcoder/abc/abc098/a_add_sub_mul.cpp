//----------------------------
//ABC_098_A
//Add Sub Mui
//32
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
	int a, b;
	cin >> a >> b;
	cout << max({ a + b,a - b,a * b }) << endl;
	return 0;
}