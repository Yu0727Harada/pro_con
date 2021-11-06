//
// Created on 2021/10/17.
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

    vector<pair<double,double>>line;
    vector<ll>sum_line(n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        line.push_back({a,b});
    }
    sum_line[0] = line[0].first;
    for (int i = 1; i < n; ++i) {
        sum_line[i] = sum_line[i-1] + line[i].first;
    }

    vector<double>time_a(n);
    time_a[0] = line[0].first / line[0].second;
    for (int i = 1; i < n; ++i) {
        time_a[i] = time_a[i-1] + line[i].first / line[i].second;
    }
    vector<double>time_b(n);
    time_b[n-1] = line[n-1].first / line[n-1].second;
    for (int i = n-2; i >= 0; --i) {
        time_b[i] = time_b[i + 1] + line[i].first / line[i].second;
    }

    int l = 0;
    int r = n-1;
    while(l < r){
        if(time_a[l] < time_b[r]){
            l++;
        }else{
            r--;
        }
    }

    double ans;
    if(time_a[l] < time_b[r]){
        ans = line[l].first - ((time_b[r] - time_a[l]) * line[l].second);
        ans += sum_line[l];
    }else{
        ans = line[l].first - ((time_a[l] - time_b[r]) * line[l].second);
        ans += sum_line[l];
    }
        printf("%.10f\n", ans);

    return 0;
}
