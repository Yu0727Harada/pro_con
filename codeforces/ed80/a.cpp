//
//
// Created on 2020/01/14.
//

//#include <bits/stdc++.h>
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int solve(){
    ll n;
    ll d;
    cin>>n>>d;
    if (d<=n) {cout<<"YES"<<endl; return 0;}
    ll t = n;
    ll b = 1;
    ll x;

    for (int i = 0; i < 100; ++i || t != b) {

        x = (t+b)/2;
        if ((x+(d+x)/(x+1))<n) {cout<<"YES"<<endl;return 0;}
        if ((x+(d+x)/(x+1))>n){b = x;}
        else if ((x+(d+x)/(x+1))<n){t = x;}
    }
    if ((t+(d+t)/(t+1))==n) {cout<<"YES"<<endl;return 0;}
    if ((b+(d+b)/(b+1))==n) {cout<<"YES"<<endl;return 0;}
    cout<<"NO"<<endl;
    return 0;

}

int main() {
    int num;
    cin>>num;
    for (int i = 0; i < num; ++i) {
        solve();
    }

}
