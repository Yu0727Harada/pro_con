//
// Created on 2022/06/25.
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
    string s;
    cin>>s;
    vector<ll> child;
    vector<ll> adult;

    for (int i = 0; i < n; ++i) {
        int w;
        cin>>w;
        if(s[i] == '0')child.push_back(w);
        else adult.push_back(w);
    }



    vector<pair<int,int>> event;
    for (int i = 0; i < child.size(); ++i) {
        event.push_back({child[i] + 1,+1});
    }
    for (int i = 0; i < adult.size(); ++i) {
        event.push_back({adult[i] + 1,-1});
    }
    sort(all(event));

    int now = adult.size();
    int x = 0;
    int ans = adult.size();
    for (int i = 0; i < event.size(); ++i) {
        x = event[i].first;
        now += event[i].second;
        chmax(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}
