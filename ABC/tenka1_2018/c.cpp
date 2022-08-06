//
// Created by 原田 on 2022/05/27.
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
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(all(a));
    deque<ll>d;
    d.push_back(a[0]);
    ll ans = 0;
    int l = 1;
    int r = a.size() - 1;
    bool small = false;
    while(l <= r){
        if(small){

            if(l + 1 <= r){
                ans += abs(d.front() - a[l]);
                d.push_front(a[l]);
                ans += abs(d.back() - a[l + 1]);
                d.push_back(a[l + 1]);
            }else{
                ans += max(abs(d.front() - a[l]),abs(d.back() - a[l]));

            }
            l += 2;
        }else{
            if(l <= r - 1){
                ans += abs(d.front() - a[r]);
                d.push_front(a[r]);
                ans += abs(d.back() - a[r - 1]);
                d.push_back(a[r - 1]);
            }else{
                ans += max(abs(d.front() - a[r]),abs(d.back() - a[r]));
            }
            r -= 2;
        }
        small = !small;
    }

    sort(rall(a));
    d.clear();
    d.push_back(a[0]);
    ll ans2 = 0;
    l = 1;
    r = a.size() - 1;
    small = true;
    while(l <= r){
        if(!small){

            if(l + 1 <= r){
                ans2 += abs(d.front() - a[l]);
                d.push_front(a[l]);
                ans2 += abs(d.back() - a[l + 1]);
                d.push_back(a[l + 1]);
            }else{
                ans2 += max(abs(d.front() - a[l]),abs(d.back() - a[l]));

            }
            l += 2;
        }else{
            if(l <= r - 1){
                ans2 += abs(d.front() - a[r]);
                d.push_front(a[r]);
                ans2 += abs(d.back() - a[r - 1]);
                d.push_back(a[r - 1]);
            }else{
                ans2 += max(abs(d.front() - a[r]),abs(d.back() - a[r]));
            }
            r -= 2;
        }
        small = !small;
    }

    cout<<max(ans,ans2)<<endl;
    return 0;
}
