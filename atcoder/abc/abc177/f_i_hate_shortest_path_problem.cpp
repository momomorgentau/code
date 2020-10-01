#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;

    map<int, int> ns; //�i���ݒn�A�X�^�[�g�n�_�̍ő�l�j
    multiset<int> dist; //���ݒn�[�X�^�[�g�n�_�̍ő�l

    rep(i, w) ns[i] = i; //�L�[i��i����
    rep(i, w) dist.insert(0); //�͂��߂͋���0

    rep(i, h) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        auto it = ns.lower_bound(a);
        int ms = -1; //�ł��E�ɂ���J�n�_��ێ�
        while (1) {
            //�ǂ�1����������_�̃X�^�[�g�n�_���擾�ib+1�j
            if (it == ns.end() || it->first > b + 1) break;
            ms = max(ms, it->second);
            dist.erase(dist.find(it->first - it->second));
            ns.erase(it++);
        }
        //�v�f��������Ȃ��Aw�𒴂��Ă��܂����������B
        if (ms != -1 && b + 1 != w) {
            dist.insert(b + 1 - ms);
            ns[b + 1] = ms;
        }

        int ans = -1;
        if (dist.size() > 0) {
            ans = *dist.begin();
            ans += i + 1;
        }
        cout << ans << endl;
    }

    return 0;
}