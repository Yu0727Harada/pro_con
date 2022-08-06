//
// Created by 原田 on 2021/12/16.
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
    int n,k;
    cin>>n>>k;
    vector<char> d(k);
    for (int i = 0; i < k; ++i) {
        cin>>d[i];
    }
    sort(all(d));

    for (int i = n; i <= 1000000; ++i) {
        string s = to_string(i);
        bool find = false;
        for (int j = 0; j < d.size() && !find; ++j) {
            for (int l = 0; l < s.size() && !find; ++l) {
                if(s[l] == d[j]){
                    find = true;
                }
            }
        }
        if(!find){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}

