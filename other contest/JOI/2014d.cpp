//
// Created on 2020/08/01.
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
const long long LINF =1e18;
const int INF = 1e9;
const ll mod = 10007;

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

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>l(n);
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'J'){
            l[i] = 0;
        }else if(s[i] == 'O'){
            l[i] = 1;
        }else{
            l[i] = 2;
        }
    }
    vector<vector<mint>>dp(n,vector<mint>(1<<3,0));
    for (int j = 1; j < (1<<3); ++j) {
        if(j & (1<<l[0]) && j & (1<<0)){
            dp[0][j] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < (1<<3); ++j) {
            for (int k = 1; k < (1<<3); ++k) {
                //1人以上同じ人が部活に出ている　＆＆　責任者が出ている
                for (int m = 0; m < 3; ++m) {
                    if((j & (1<<m)) && (k & (1<<m)) && (j & (1<<l[i]))){
                        dp[i][j] += dp[i - 1][k];
                        break;
                    }
                }
            }
        }
    }
    mint ans = 0;
    for (int i = 0; i < (1<<3); ++i) {
        ans += dp[n-1][i];
    }
    cout<<ans.x<<endl;
    return 0;
}

/*

参加しているかどうかをビットで管理する

        https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d
IOI 高校のプログラミング部には，J 君と O 君と I 君の
3
人の部員がいる． プログラミング部では，部活のスケジュールを組もうとしている．

今，
N
        日間の活動のスケジュールを決めようとしている． 各活動日 のスケジュールとして考えられるものは，各部員については活動に参加するかどうか の
2
通りがあり，部としては全部で
8
通りある． 部室の鍵はただ
1
つだけであり，最初は J 君が持っている． 各活動日には，そ の日の活動に参加する部員のうちのいずれか
1
人が鍵を持っている必要 があり，活動後に参加した部員のいずれかが鍵を持って帰る．

プログラミング部では，活動日には毎回必ず活動が行われるように，あらかじめ各活動日の責任者を定めた． 責任者は，必ずその日の活動に出席しなければならない．

スケジュールを決めようとしている日数と，各活動日の責任者が誰であるかの情報が与えられた時，すべての活動日に部活動を行うことができるようなスケジュール表 として考えられるものの数を
10007
で割った余りを求めるプログラムを 作成せよ． ただし，部活の終了時に鍵を持って帰る部員は，その日の活動に参加している部員の誰でもよく，最終日は誰が鍵を持って帰ってもよいものとする．*/
