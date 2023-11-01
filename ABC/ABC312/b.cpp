//
// Created on 2023/07/29.
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

    int h,w;
    cin>>h>>w;

    vector<string>s(h);
    for (int i = 0; i < h; ++i) {
        cin>>s[i];
    }

    for (int i = 0; i + 9 <= h; ++i) {
        for (int j = 0; j + 9 <= w; ++j) {

            bool ok = true;
            for (int k = i; k < i + 3; ++k) {
                for (int l = j; l < j + 3; ++l) {
                    if(s[k][l] == '.')ok = false;
                }
            }
            for (int k = i + 6; k < i + 9; ++k) {
                for (int l = j + 6; l < j + 9; ++l) {
                    if(s[k][l] == '.')ok = false;
                }
            }

            for (int k = i; k < i + 4; ++k) {
                if(s[k][j + 3] == '#')false;
            }
            for (int k = j; k < j + 4; ++k) {
                if(s[i + 3][k] == '#')false;
            }
            for (int k = i + 5; k < i + 9; ++k) {
                if(s[k][j + 5] == '#')ok = false;
            }
            for (int k = j + 5; k < j + 9; ++k) {
                if(s[i + 5][k] == '#')ok = false;
            }
            if(ok){
                cout<<i + 1<<" "<<j+1<<endl;
            }

        }

    }

    return 0;
}
