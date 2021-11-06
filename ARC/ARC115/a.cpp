//
// Created on 2021/09/22.
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
    int n;
    int m;
    cin>>n>>m;

    ll odd = 0;
    ll even = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        int zero = 0;
        int one = 0;
        for (int j = 0; j < m; ++j) {
            if(s[j] == '0')zero++;
            else one++;
        }
        if(one % 2 == 0)even ++;
        else odd ++;
    }


    cout<<odd * even<<endl;
    return 0;
}


//0 か 1 で答える問題 M 問からなるテストがあり、これに N 人の生徒が取り組みました。 N 個の長さ M の文字列 S1​,S2​,…,SN​ が与えられます。 Si​ の k 文字目は 0 と 1 のいずれかであり、 i 番目の生徒の k 問目に対する解答を示しています。各生徒の各問題に対する解答は判明していますが、各問題の正解が 0 と 1 のどちらであるかはまだ判明していません。 1≤i<j≤N を満たす組 (i,j) であって、生徒 i と生徒 j の正解した問題の数が等しい可能性がないようなものはいくつあるか求めてください
//ある二人の生徒の正解数が等しい可能性があるか考えます。（ N=2 の場合を考えているとも言えます。）
//
//二人の解答が等しい問題については、正解数の差に影響を与えないため考えなくて良いです。二人の解答が異なる問題が D 個あったとします。この D 問では必ずどちらか一人が正解することに注意してください。D が偶数のときは、片方が D/2 問、もう片方が残りの D/2 問を正解すれば、正解数が等しくなります。一方 D が奇数の時は、正解数が等しくなることはありません。
//
//よって、「二人の正解数が等しい可能性がない」ことは、「二人の解答が異なる問題が奇数個ある」ことと同値です。
//
//ある問題の二人の解答が異なるとき、二人の 1 と解答した問題数の差の偶奇は、その問題が無かった場合から反転します。一方、二人の解答が同じ時は、変化しません。
//
//よって、「二人の解答が異なる問題が奇数個ある」ことは、「二人の 1 と解答した問題数の偶奇が異なる」ことと同値です。
//
//したがって、「二人の正解数が等しい可能性がない」ことが、「二人の 1 と解答した問題数の偶奇が異なる」ことと同値です。
//
//1 と解答した問題数が奇数の生徒の人数と偶数の生徒の人数の積が答えです。