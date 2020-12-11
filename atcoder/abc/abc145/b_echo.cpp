//49
//abc145_b_echo
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string t = s.substr(0,n/2);
    if(s.substr(n/2) == t)cout<< "Yes"<<endl;
    else cout << "No" << endl;
}