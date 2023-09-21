//----------------------------
// ABC 319 A
// Legendary Players
// 10
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    map<string, int> mp{
	{"tourist", 3858},
	{"ksun48", 3679},
	{"Benq", 3658},
	{"Um_nik", 3648},
	{"apiad", 3638},
	{"Stonefeang", 3630},
	{"ecnerwala", 3613},
	{"mnbvmar", 3555},
	{"newbiedmy", 3516},
	{"semiexp", 3481}
	};
	string s;
	cin >> s;
	cout << mp[s] << endl;
    return 0;
}

