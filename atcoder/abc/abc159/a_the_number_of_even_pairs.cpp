//32
//abc160_a_the_number_of_even_pairs
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    ans += n * (n - 1) / 2;
    ans += m * (m - 1) / 2;
    cout << ans << endl;
    return 0;
}
