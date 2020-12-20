//
// Created on 2020/12/19.
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

#include <algorithm>
#include <limits>

/**
* 10進数 v を base進数の文字列へ変換する。
* @param [in] v    10進数の整数
* @param [in] base 変換した 2~36 のN進数の値
* @return base進数へ変換した文字列
*/
template<typename TypeInt>
string Itoa(const TypeInt v, int base)
{
    static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret;
    static numeric_limits<TypeInt> t;
    TypeInt n = v;
    if (t.is_signed) {
        if (v < 0) n *= -1;
    }

    while (n >= base) {
        ret += table[n%base];
        n /= base;
    }
    ret += table[n];
    if (t.is_signed) {
        if (v < 0 && base == 10) ret += '-';
    }
    // 文字列の順番を逆にする
    reverse(ret.begin(), ret.end());

    return ret;
}


//Nは桁数が大きい場合があるので文字列として受け取る
vector<int> n;  //Nの各桁の数字を格納するベクター
int dp[100][2][2];

int main(){
    int N;
    cin>>N;
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        string ten = Itoa(i,10);
        string eight = Itoa(i,8);
        bool ok = true;
        for (int j = 0; j < ten.size(); ++j) {
            if(ten[j] == '7'){
                ok = false;
            }
        }
        for (int j = 0; j < eight.size(); ++j) {
            if(eight[j] == '7'){
                ok = false;
            }
        }
        if(ok)ans ++;
    }
    cout<<ans<<endl;

    return 0;
}