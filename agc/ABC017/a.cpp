//
// Created on 2020/12/02.
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

const int MAX = 10000;//nCkのn,kの取りうるMAX
const int MOD = 1000000007;

long long fac[MAX],finv[MAX],inv[MAX];

//階乗のテーブルを作る
void COM_initialize(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2 ; i < MAX ; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD -inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

//二項係数計算,nCkのn,kを引数として渡す
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD)% MOD;
}

int main() {
    int n,p;
    cin>>n>>p;
    int ki_num = 0;
    int gu_num = 0;


    COM_initialize();
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        if(t % 2 == 0){
            gu_num++;
        }else{
            ki_num++;
        }
    }

    ll gu_all = 0;
    //for (int i = 0; i <= gu_num; ++i) {
        gu_all += pow(2,gu_num);
    //}

    ll ans = 0;
    if(p == 0){
        for (int i = 0; i <= ki_num; i += 2) {
            ans += COM(ki_num,i) * gu_all;
        }
    }else{
        for (int i = 1; i <= ki_num; i += 2) {
            ans += COM(ki_num,i) * gu_all;
        }

    }
    cout<<ans<<endl;



    return 0;
}
//よく分からない天才解法