//120
//arc109_a_redundant_redundancy

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int pn[] = { 2,2,2,2,3,3,3,5,5,7,11,13,17,19,23,29 };
int main()
{
    int n;
    cin >> n;
    ll q = 1;
    for (auto qi : pn) q *= qi;
    cout << q + 1 << endl;
    return 0;
}