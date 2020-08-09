//
// Created on 2020/01/19.
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


pair<int,int> get_p(int n){
    int a = n;
    while (a/10){
        a /= 10;
    }
    return {a,n%10};
}

int main() {
    int n;
    ll ans = 0;
    cin>>n;
    map<pair<int,int>,int>mp;

    for (int k = 1; k <= n; ++k) {
        mp[get_p(k)] ++;
    }
    for (int i = 1; i <= n; ++i) {
        pair<int,int> temp = get_p(i);
        pair<int,int> temp2 = {temp.second,temp.first};
        ans += mp[temp2];
    }

    cout<<ans<<endl;
}
