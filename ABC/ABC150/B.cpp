//
// Created on 2020/01/10.
//

#include <bits/stdc++.h>
#include <numeric>

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int main() {
    int N;
    cin>>N;
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
    int a;
    int b;
    vector<int>p(N,0);
    vector<int>q(N,0);
    for (int i = 0; i < N; ++i) {
        cin>>p[i];
    }
    for (int j = 0; j < N; ++j) {
        cin>>q[j];
    }
    int count = 1;
    do {
            if(v == p){
                a = count;
            }
            if(v == q) {
                b = count;
            }
        count ++;
         //cout << x << " "; cout << "\n";    // v の要素を表示
    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成

    cout<<abs(a-b)<<endl;
}

