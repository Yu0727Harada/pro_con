//
// Created on 2022/08/17.
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
    int h1,w1;
    cin>>h1>>w1;
    vvi a(h1,vi(w1,0));
    for (int i = 0; i < h1; ++i) {
        for (int j = 0; j < w1; ++j) {
            cin>>a[i][j];
        }
    }
    int h2,w2;
    cin>>h2>>w2;
    vvi b(h2,vi(w2,0));
    for (int i = 0; i < h2; ++i) {
        for (int j = 0; j < w2; ++j) {
            cin>>b[i][j];
        }
    }

    //n個の要素のbit全探索する
    for (int bit = 0; bit < (1<<h1); ++bit) {
        for (int bit_w = 0; bit_w < (1<<w1); ++bit_w) {
            vvi tmp;
            for (int i = 0; i < h1; ++i) {
                vi tmp2;
                for (int j = 0; j < w1; ++j) {
                    if (bit & (1 << i) || bit_w & (1<<j)) {
                        continue;
                    }else{
                        tmp2.push_back(a[i][j]);
                    }
                }
                if(tmp2.size() != 0)tmp.push_back(tmp2);
            }

            if(tmp == b){
                cout<<"Yes"<<endl;
                return 0;
            }

        }
    }

    cout<<"No"<<endl;

    return 0;
}
