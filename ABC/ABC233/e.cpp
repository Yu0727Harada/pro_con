//
// Created on 2021/12/25.
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

int add_r;

void ageri(vi &target,int i,int d){
    if(add_r < i)add_r = i;
    if(target[i] + d >= 10){
        target[i] += d % 10;
        ageri(target,i+1,1);
    }else{
        target[i] += d;
    }
    return;
}


int main() {
    string s;
    cin>>s;
    ll all = 0;
    for (int i = 0; i < s.size(); ++i) {
        all += s[i] - '0';
    }
    reverse(all(s));
    vi add(600000,0);
    vi ans;
    add_r = 0;
    string t = to_string(all);
    reverse(all(t));
    ans.push_back(t[0] - '0');
    for (int i = 1; i < t.size(); ++i) {
        ageri(add,i,t[i] - '0');
    }
    all -= int(s[0] - '0');

    for (int i = 1; i < s.size(); ++i) {
        t = to_string(all + add[i]);
        reverse(all(t));
        ans.push_back(t[0] - '0');
        for (int j = 1; j < t.size(); ++j) {
            ageri(add,i + j,t[j] - '0');
        }
        all -= s[i] - '0';
    }
    for (int i = s.size(); i < add_r; ++i) {
        ans.push_back(add[i]);
    }
    for (int i = ans.size()-1; i >= 0; --i) {
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}
