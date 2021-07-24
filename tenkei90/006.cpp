//
// Created by 原田 on 2021/07/15.
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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<vector<ll>> app(n+1,vl(26,LINF));
    app[n][s[n - 1] - 'a'] = n;
    for (ll i = n - 1; i > 0 ; --i) {
        for (ll j = 0; j < 26; ++j) {
            app[i][j] =app[i + 1][j];
        }
        app[i][s[i - 1] - 'a'] = i;
    }

    string t = "";
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if(n - app[i][j]  >= k - (cnt + 1)){
                t += char(j + 'a');
                cnt ++;
                i = app[i][j];
                if(cnt == k){
                    cout<<t<<endl;
                    return 0;
                }
                break;
            }
        }
    }

    cout<<t<<endl;
    return 0;
}
