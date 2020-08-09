//
// Created on 2020/05/10.
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
typedef long long ll;
using namespace std;
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

const int MAX = 510000;//nCkのn,kの取りうるMAX

long long fac[MAX],finv[MAX],inv[MAX];

//階乗のテーブルを作る
void COM_initialize(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2 ; i < MAX ; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod -inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

//二項係数計算,nCkのn,kを引数として渡す
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod)% mod;
}

int main() {
    mint ans = 0;
    int n,m,k;
    cin>>n>>m>>k;
    COM_initialize();
    mint paint = m ;
    for (int i = n-1 ; i >= 0; --i) {
        if(i <= k ){
            mint group = COM(n-1,i);
            ans += group * paint;
        }
        paint *= (m-1);
    }

    cout<<ans.x<<endl;

    return 0;
}

//場合わけ、数学
/*

N個のブロックが横一列に並んでいます。このブロック列に色を塗ります。
2つのブロック列の塗り方が異なるとは、あるブロックが存在して、そのブロックが異なる色で塗られていることと定義します。
次の条件を満たすブロック列の塗り方が何通りあるか求めてください。
各ブロックを色1から色Mまでのいずれか一色で塗る。使わない色があってもよい。
隣り合うブロックの組であって同じ色で塗られている組は、K組以下である。
ただし、答えは非常に大きくなる場合があるので、998244353で割った余りを出力してください。

 https://atcoder.jp/contests/abc167/tasks/abc167_e

 k=0と考えると、色の塗り分け方はN*(N-1)^(N-1)。
 k=1と考えると、N*(N-1)^(N-1-1)。
 このように色の塗り分け方はk=xとすると、N*(N-1)^(N-x-1)とできる
 これはただの色の順番で、どこをくみとするかは考慮していない。
 どこを組とするかはN-1の区切りの中からx個を選ぶと言うことなのでn-1Cxでもとまる。
 よってx個の塗り分けの時の塗り分け方はN*(N-1)^*(N-x-1)*n-1Cx。
 kの範囲全ててforループを回すことですっきりとしたコードになる。グループすうがk以下なら答えをたす。


*/

