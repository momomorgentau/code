//ABC_213_B
//Booby Prize
//26
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> A(n);
    rep(i, n) cin >> A[i].first;
    rep(i, n)A[i].second = i + 1;
    sort(A.rbegin(), A.rend());
    cout << A[1].second << endl;
    return 0;
}