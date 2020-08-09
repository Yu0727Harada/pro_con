//
// Created on 2019/12/09.
// bit全探索

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
using gragh = vector<vector<int>>;

int main() {
    int N,M;
    cin>>N>>M;

    int ans = 0;

    vector<vector <int > > condition (M,vector<int >(0));

    for (int i = 0; i < M; ++i) {
        int k;
        cin>>k;
        for (int j = 0; j < k; ++j) {
            int s;
            cin>>s;
            s--;
            condition[i].push_back(s);
        }
    }
    vector<int>p(M);
    for (int l = 0; l < M; ++l) {
        cin>>p[l];
    }

    for (int bit = 0; bit < (1 << N); ++bit) {
        bool ok = true;
        for (int i = 0; i < M; ++i) {
            int on =0;
            for (int j = 0; j < condition[i].size(); ++j) {
                if (bit & (1<<condition[i][j])) on++;
            }
            if (on % 2 != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout<<ans<<endl;
}
