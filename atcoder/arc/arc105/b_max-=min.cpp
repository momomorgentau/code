//diff 275
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;

    rep(i, n) {
        int b;
        cin >> b;
        st.insert(b);
    }

    while (1)
    {
        int mx, mn;
        auto it = st.begin();
        mn = *it;
        it = st.end();
        mx = *--it;
        if (mn == mx) break;
        int def = mx - mn;
        st.insert(def);
        st.erase(mx);

    }
    int ans = *st.begin();
    cout << ans << endl;

    return 0;
}

