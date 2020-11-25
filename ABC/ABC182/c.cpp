//
// Created on 2020/11/08.
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

int bit_count(int i){
    //数字iを二進数表記にした際の1の数を調べる
    if (i==0) return 0;
    return bit_count(i>>1) + (i & 1);
}

int main() {
    string s;
    cin>>s;
    vector<int>a(s.size());
    for (int i = 0; i < s.size(); ++i) {
        a[i] = s[i]-'0';
    }
    //n個の要素のbit全探索する

    int n = s.size();

    int ans = INF;
    for (int bit = 1; bit < (1<<n); ++bit) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if(bit & (1<<i)){
                    //i個目の要素にフラグが立っていた時の処理
                    sum += a[i];

                }
            }
            if(sum % 3 == 0){
                if(ans > s.size() - bit_count(bit)){
                    ans = s.size() - bit_count(bit);
                }
            }
    }

    if(ans == INF){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0;
}
