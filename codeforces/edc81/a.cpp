//
// Created on 2020/01/29.
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

void solve(){
    ll t;
    ll ans = 0;
    cin>>t;
    if(t%2==1){
        t-=3;
        //ans += 7 *pow(10,t/2);
        cout<<7;
        for (int i = 0; i < t / 2; ++i) {
            ans += pow(10,i);
            cout<<1;
        }
        cout<<endl;
    }else{
        for (int i = 0; i < t / 2; ++i) {
            ans += pow(10,i);
            cout<<1;
        }
        cout<<endl;
    }



}

int main() {

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        solve();

    }


}
