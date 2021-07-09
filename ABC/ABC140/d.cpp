//
// Created by 原田 on 2021/07/07.
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
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    int m = 0;
    int e = 0;
    int ans = 0;
    for (int i = 1; i < s.size(); ++i) {
        if(s[i - 1] == 'R' && s[i] == 'L' ){
            m++;
        }else if(s[i - 1] == 'R' && s[i] == 'R'){
            ans ++;
        }else if(s[i - 1] == 'L' && s[i] == 'L'){
            ans ++;
        }
    }
    if(s[0] == 'L')e++;
    if(s[s.size() -1 ] == 'R')e++;

    while(k && ((m > 0 && e > 0) || (m > 1))) {
        k--;
        m--;
        ans += 2;
    }
    if(k && (e >  1 || m > 0)){
        ans += 1;
        e--;
        k--;
    }

    cout<<ans<<endl;


    return 0;
}
