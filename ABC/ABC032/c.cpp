//
// Created by 原田 on 2021/08/25.
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

    ll n,k;
    cin>>n>>k;

    vl s(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
        if(s[i] == 0){
            cout<<n<<endl;
            return 0;
        }
    }

    int ans = 0;
    ll now = s[0];
    int i,j;
    i = 0;
    j = 0;
    while(true){
        if(now > k && j >= i){
            if(i >= n - 1) break;
            now /= s[i];
            i ++;
        }else{
            chmax(ans,j - i + 1);
            if(j >= n - 1){
                if(i >= n - 1) break;
                now /= s[i];
                i ++;
            }else{
                j ++;
                now *= s[j];
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}

//
//長さN の非負整数列
//S=s1,s2,..,sN
//
//N
//​
//と整数
//        K
//K があります。 あなたの仕事は、以下の条件を満たす
//        S
//S の 連続する 部分列のうち、最も長いものの長さを求めることです。部分列の長さは
//1
//1 以上の列でないといけません。
//
//その部分列に含まれる全ての要素の値の積は、
//K
//        K 以下である。
//もし条件を満たす部分列が一つも存在しないときは、
//0
//0 を出力してください。
//
