//
// Created on 2022/09/03.
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
    string s;
    cin>>s;

    vi col(7,0);
    col[0] += s[6] - '0';
    col[1] += (s[3] - '0');
    col[2] += (s[7] - '0') + (s[1] - '0');
    col[3] += (s[4] - '0') + (s[0] - '0');
    col[4] += (s[8] - '0') + (s[2] - '0');
    col[5] += (s[5] - '0');
    col[6] += (s[9] - '0');

    if(s[0] == '0'){
        for (int i = 1; i < 6; ++i) {
            bool find_l = false;
            bool find_r = false;
            if(col[i] == 0){
                for (int j = 0; j < i; ++j) {
                    if(col[j] >= 1)find_l = true;
                }
                for (int j = i + 1; j < 7; ++j) {
                    if(col[j] >= 1)find_r = true;
                }
                if(find_l && find_r){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }

    }
    cout<<"No"<<endl;


    return 0;
}
