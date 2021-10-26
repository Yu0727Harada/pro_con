//
// Created by 原田 on 2021/10/19.
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
    string s;
    cin>>s;

    vector<char>v;
    for (int i = 0; i < s.size(); ++i) {
        v.push_back(s[i]);
    }
    sort(all(v));
    ll ans = 0;
    if(v.size() == 2){
        ans = (v[0] - '0') * (v[1] - '0');
    }else {

        do {
            for (int i = 1; i < v.size() - 1; ++i) {
                ll left = 0;
                if (v[0] == '0')continue;
                else left += v[0] - '0';
                for (int j = 1; j < i; ++j) {
                    left *= 10;
                    left += v[j] - '0';
                }
                ll right = 0;
                if (v[i] == '0')continue;
                else right += v[i] - '0';
                for (int j = i + 1; j < v.size(); ++j) {
                    right *= 10;
                    right += v[j] - '0';
                }
                ll temp_ans = left * right;
                chmax(ans, temp_ans);
            }

        } while (next_permutation(v.begin(), v.end()));     // 次の順列を生成
    }
    cout<<ans<<endl;
    return 0;
}
