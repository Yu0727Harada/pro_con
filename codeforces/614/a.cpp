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



int solve(){
    ll n;
    ll s;
    ll k;
    cin>>n>>s>>k;
    vector<ll>closed(k);
    for (int l = 0; l < k; ++l) {
        cin>>closed[l];
    }
    sort(all(closed));
    if(k==1){
        if(s!=closed[0])return 0;
        else return 1;
    }
    for (int i = 1; i < k; ++i) {
        if ( closed[i-1] <= s && s <= closed[i]){
            if(closed[i-1] != s && closed[i] != s) return 0;
            int st;
            if (closed[i-1] == s) st = i-1;
            else st = i;
            int ans = 1;
            while(true) {
                if ((st+ans >= k ) && (s+ans <=n )) return ans;
                if(st-ans <0 && s-ans >=1) return ans;
                if(st + ans < k){
                    if (s+ans != closed[st+ans] && (s+ans <=n )) return ans;
                }
                if(st -ans >= 0){
                    if(s-ans != closed[st-ans]&& ( s-ans >=1)) return ans;
                }
                ans ++;
            }
        }
    }

}

int main() {
    int ans;
    cin>>ans;
    for (int i = 0; i < ans; ++i) {
        cout<<solve()<<endl;
    }


}
