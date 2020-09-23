//
// Created on 2020/09/18.
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



int main() {
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<int>ans(110,0);
    ans[0] = s[0]-'0';
    for (int i = 1; i < 110; ++i) {
        if(ans[i-1] != 1) ans[i] = ans[i-1];
        else if(i < s.size()) ans[i] = s[i] -'0';
        else ans[i] = ans[i-1];
    }
    if(k <= 100){
        cout<<ans[k-1]<<endl;
    }else{
        cout<<ans[100]<<endl;
    }
    return 0;
}
