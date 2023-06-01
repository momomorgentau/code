//----------------------------
// ABC 255 A 
// Distinct Strings
// 12
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string s;
	cin >> s;
	set<char> st;
	for(const auto&c:s)
	{
	    st.insert(c);
	}
	if(st.size() == 1) cout << 1 << endl;
	if(st.size() == 2) cout << 3 << endl;
	if(st.size() == 3) cout << 6 << endl;
    return 0;
}

