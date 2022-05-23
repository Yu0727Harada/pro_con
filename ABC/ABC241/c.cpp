//
// Created by 原田 on 2022/03/02.
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
    cin>>n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    vvi test(n,vi(n,0));

    bool ok = false;

    for (int i = 0; i < n; ++i) {
        int now_cnt = 0;
        for (int j = 0; j < 6; ++j) {
            if(v[i][j] == '#')now_cnt++;
            test[i][j]++;
        }
        if(now_cnt == 4)ok = true;
        for (int j = 6; j < n; ++j) {
            if(v[i][j - 6] == '#')now_cnt--;
            if(v[i][j] == '#')now_cnt++;
            test[i][j]++;
            if(now_cnt >= 4)ok = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        int now_cnt = 0;
        for (int j = 0; j < 6; ++j) {
            if(v[j][i] == '#')now_cnt++;
            test[i][j]++;
        }
        if(now_cnt >= 4)ok = true;
        for (int j = 6; j < n; ++j) {
            if(v[j - 6][i] == '#')now_cnt--;
            if(v[j][i] == '#')now_cnt++;
            test[i][j]++;
            if(now_cnt >= 4)ok = true;
        }
    }
    for (int i = 0; i < n - 5; ++i) {
        for (int j = 0; j < n - 5; ++j) {
            int now_cnt = 0;
            for (int k = 0; k < 6; ++k) {
                if(v[i + k][j + k] == '#')now_cnt++;
                test[i + k][j + k]++;
            }
            if(now_cnt >= 4)ok = true;
        }
    }for (int i = n - 1; i >= 5; --i) {
        for (int j = 0; j < n - 5; ++j) {
            int now_cnt = 0;
            for (int k = 0; k < 6; ++k) {
                if(v[i - k][j + k] == '#')now_cnt++;
                test[i - k][j + k]++;
            }
            if(now_cnt >= 4)ok = true;
        }
    }

    if(ok){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
//    for (int i = 0; i < n; ++i) {
//        for ( int j = 0; j < test[i].size(); j++ )
//        {
//        	cout << test[i][j] << ( j + 1 < test[i].size() ? ' ' : '\n' );
//        }
//        cout << flush;
//    }
    return 0;
}
