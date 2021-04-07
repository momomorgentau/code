//007
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;


int main()
{
    int n,q;
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    A.emplace_back(2e9);
    A.emplace_back(-2e9);

    
    cin >> q;
    vector<int> B(q);
    rep(i,q) cin >> B[i];


    sort(A.begin(),A.end());

    for(auto b:B)
    {
        auto it = lower_bound(A.begin(),A.end(),b);
        int a1 = *it--;
        int a2 = *it;
        cout << min(abs(b-a1),abs(b-a2))<< endl;
    }
    return 0;
}