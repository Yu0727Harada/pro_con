//
// Created on 2022/04/24.
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
//#include <atcoder/all>


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
    int n,k;
    cin>>n>>k;
    vector<vector<int>> cnt(n,vi(26,0));

    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < s.size(); ++j) {
            cnt[i][s[j] - 'a'] = 1;
        }
    }

    //n個の要素のbit全探索する
    int ans = 0;
    for (int bit = 0; bit < (1<<n); ++bit) {
            vi tmp_cnt(26,0);
            for (int i = 0; i < n; ++i) {
                if(bit & (1<<i)){
                    //i個目の要素にフラグが立っていた時の処理
                    for (int j = 0; j < 26; ++j) {
                        tmp_cnt[j] += cnt[i][j];
                    }
                }
            }
            int tmp_ans = 0;
        for (int i = 0; i < 26; ++i) {
            if(tmp_cnt[i] == k) tmp_ans ++;
        }
        chmax(ans,tmp_ans);
    }
    cout<<ans<<endl;

    return 0;
}
