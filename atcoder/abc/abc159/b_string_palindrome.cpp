//92
//abc160_b_string_palindrome

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
    string s;
    cin >> s;
    int n = s.size();


    string s2 = s.substr(0, (n - 1) / 2);
    string s3 = s.substr((n + 3) / 2 - 1);

    string rs1 = s;
    string rs2 = s2;
    string rs3 = s3;

    reverse(rs1.begin(), rs1.end());
    reverse(rs2.begin(), rs2.end());
    reverse(rs3.begin(), rs3.end());

    if (s == rs1 && s2 == rs2 && s3 == rs3) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}