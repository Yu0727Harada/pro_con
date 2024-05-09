//
// Created by yu on 2024/05/08.
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
    int w,b;
    cin>>w>>b;
    string s = "wbwbwwbwbwbw";

    vi w_l(500,0);
    vi b_l(500,0);

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if(s[j] == 'w'){
                w_l[i * 12 + j + 1] = w_l[i * 12 + j] + 1;
                b_l[i * 12 + j + 1] = b_l[i * 12 + j];
            }else{
                w_l[i * 12 + j + 1] = w_l[i * 12 + j];
                b_l[i * 12 + j + 1] = b_l[i * 12 + j]+1;
            }
        }
    }
    for (int i = 0; i < 29 * 12; ++i) {
        for (int j = 0; j < 29 * 12; ++j) {
            if(w == w_l[j] - w_l[i] && b == b_l[j] - b_l[i]){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
cout<<"No"<<endl;
    return 0;
}
