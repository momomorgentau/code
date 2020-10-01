#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {

	string s;
	cin >> s;

	int l = s.length();
	if (s[l - 1] != 's') s += "s";
	else s += "es";
	cout << s << endl;
	return 0;
}