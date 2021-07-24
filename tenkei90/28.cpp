//
// Created by 原田 on 2021/07/22.
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
    int n;
    cin>>n;
    vvi imos(1010,vi(1010,0));

    map<int,int> mp;

    for (int i = 0; i < n; ++i) {
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;

        imos[lx][ly]++;
        imos[rx][ly] --;
        imos[rx][ry] ++;
        imos[lx][ry]--;

    }


    for (int j = 0; j < 1001; ++j) {
        for (int i = 1; i < 1001; ++i) {
            imos[i][j] += imos[i-1][j];
        }
    }

    for (int j = 0; j < 1001; ++j) {
        for (int i = 1; i < 1001; ++i) {
            imos[j][i] += imos[j][i - 1];
        }
    }

    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            mp[imos[i][j]]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout<<mp[i]<<endl;
    }



    return 0;
}
