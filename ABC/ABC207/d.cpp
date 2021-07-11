//
// Created on 2021/06/26.
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
    int n;
    cin>>n;
    vector<pair<int,int>>s(n);
    vector<pair<int,int>>t(n);

    vector<vector<int>>s_dis(n,vector<int>());
    vector<vector<int>>t_dis(n,vector<int>());
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        s[i] = {a,b};
    }
    for (int i = 0; i < n; ++i) {
        int c,d;
        cin>>c>>d;
        t[i] ={c,d};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s_dis[i].push_back(pow(abs(s[i].first - s[j].first),2) + pow(abs(s[i].second - s[j].second),2));
        }
        sort(all(s_dis[i]));
    }
    sort(all(s_dis));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            t_dis[i].push_back(pow(abs(t[i].first - t[j].first),2) + pow(abs(t[i].second - t[j].second),2));
        }
        sort(all(t_dis[i]));
    }
    sort(all(t_dis));
    if(s_dis == t_dis){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


    return 0;
}
