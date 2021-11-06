//
// Created on 2021/08/20.
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
    int k;
    cin>>k;

    vl eight(21,0);
    eight[0] = 1;
    for (int i = 1; i < 22; ++i) {
        eight[i] = eight[i -1] * 8;
    }

    while(k){
        k--;

        ll ten = 0;

        for (int i = 0; i < s.size(); ++i) {
            ll m = s[s.size() - 1 - i] -'0';
            ten += m * eight[i];
        }

        string nine = "";
        while(true){
            ll mod = ten % 9;
            nine += to_string(mod);
            ten /= 9;
            if(ten == 0)break;
        }

        s = "";
        for (int i = 0; i < nine.size(); ++i) {
            if(nine[nine.size() - 1 - i] == '8'){
                s += '5';
            }else{
                s += nine[nine.size() - 1 - i];
            }
        }

    }

    cout<<s<<endl;
    return 0;
}

/*

黒板に 8 進法の整数 N が書かれています。
あなたは以下の操作を K 回行います。
・黒板の整数を 9 進法に直し、ここに現れる数字「8」を「5」に書き直す（書き直した後の数は 8 進数とみなされる）
操作を K 回行った後にできる数を 8 進法で出力してください。

【制約】
・0 ≦ N < 8^20
・1 ≦ K ≦ 100
・N は 8 進法で表される整数
・入力は全て整数

 */