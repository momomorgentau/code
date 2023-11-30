//----------------------------
// ABC 329 C
// Count xxx
// 205
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
	cin >> n;
	string s;
	cin >> s;
	set<pair<char, int>> st;
	char p = 'X';
	int q = 0;
	for(const auto&c: s)
	{
	    if(p == c)
		{
		    q++;
		}
		else
		{
		   p = c;
		   q = 1;
		}
		st.insert(make_pair(p, q));
	}
	cout << st.size() << endl;
    return 0;
}

