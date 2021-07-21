//
// Created on 2021/05/26.
//


#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int N;
    cin>>N;
    int k;
    cin>>k;
    vector<int> v(N - 1);
    iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定

    vvi e(N,vi(N,-1));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>e[i][j];
        }
    }

    int ans = 0;
    do {
        int l = 0;
        int now = 0;
        int next;
        for (int i = 0; i < N-1; ++i) {
            next = v[i];
            l += e[now][next];
            now = next;
        }
        l += e[now][0];

        if(l == k)ans ++;


    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成

    cout<<ans<<endl;
    return 0;
}
