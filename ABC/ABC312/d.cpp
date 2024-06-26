//
// Created on 2023/07/29.
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

const int mod = 998244353;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main() {
    string s;
    cin>>s;

    vector<vector<mint>>dp(s.size()+1,vector<mint>(s.size()/2 + 20));

    if(s[0] == '('){
        dp[0][1] = 1;
    }else if(s[0] == ')'){
        cout<<0<<endl;
        return 0;
    }else{
        dp[0][1] = 1;
    }
    for (int i = 1; i < s.size(); ++i) {
        if(s[i] == '('){
            for (int j = 0; j < s.size()/2 +10; ++j) {
                if(dp[i - 1][j].x != 0)dp[i][j+1] += dp[i - 1][j];
            }
        }else if(s[i] == ')'){
            for (int j = 0; j < s.size()/2 + 10; ++j) {
                if(dp[i - 1][j].x != 0 && j > 0)dp[i][j - 1] += dp[i - 1][j];
            }
        }else{
            for (int j = 0; j < s.size()/2 + 10; ++j) {
                if(dp[i - 1][j].x != 0)dp[i][j + 1] += dp[i - 1][j];
                if(dp[i - 1][j].x != 0 && j > 0)dp[i][j - 1] += dp[i - 1][j];
            }
        }
    }
    cout<<dp[s.size() - 1][0].x<<endl;


    return 0;
}

