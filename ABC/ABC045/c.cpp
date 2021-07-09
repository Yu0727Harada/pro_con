//
// Created by 原田 on 2021/04/16.
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
    string s;
    cin>>s;

    //n個の要素のbit全探索する
    int n = s.size() - 1;
    ll ans = 0;
    for (int bit = 0; bit < (1<<n); ++bit) {
            ll sum_temp = 0;
            ll now = s[0] -'0';
            for (int i = 0; i < n; ++i) {
                if(bit & (1<<i)){
                    //i個目の要素にフラグが立っていた時の処理
                    sum_temp += now;
                    now = 0;
                    now += s[i + 1] -'0';
                }else{
                    now *= 10;
                    now += s[i + 1] - '0';
                }
            }
            sum_temp += now;
            ans += sum_temp;
    }

    cout<<ans<<endl;
    return 0;
}
