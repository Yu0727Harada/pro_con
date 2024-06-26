//
// Created by yu on 2024/05/14.
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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin>>p[i].first;
        p[i].second = i + 1;
    }
    sort(all(p));
    if(k == 1){
        cout<<0<<endl;
        return 0;
    }
    set<int>st;

    int min_itr = INF;
    int max_itr = 0;
    for (int i = 0; i < k; ++i) {
        st.insert(p[i].second);
        chmin(min_itr,p[i].second);
        chmax(max_itr,p[i].second);
    }
    int ans = INF;
    chmin(ans,max_itr - min_itr);
    for (int i = k; i < n; ++i) {
        int del_itr = p[i - k].second;

        st.insert(p[i].second);
        if(del_itr == min_itr){
            min_itr = *st.upper_bound(del_itr);
        }
        if(del_itr == max_itr){
            max_itr = *(st.lower_bound(del_itr).operator--());
        }
        chmax(max_itr,p[i].second);
        chmin(min_itr,p[i].second);
        st.erase(p[i - k].second);
        chmin(ans,max_itr - min_itr);
    }
    cout<<ans<<endl;

    return 0;
}
