//
// Created on 2020/05/10.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    ll ans;
    ll n;
    ll k;
    cin>>n>>k;
    vector<bool>seen(n,false);
    vector<ll>tel(n);
    for (ll i = 0; i < n; ++i) {
        ll temp;
        cin>>temp;
        temp --;
        tel[i] = temp;
    }
    queue<ll>q;
    vector<ll>log;
    q.push(0);
    ll loop_start;
    while(!q.empty()){
        ll now_v = q.front();
        q.pop();

        if(seen[now_v] == true){
            //訪問済み
            ll i = log.size()-1;
            while(log[i] != now_v){
                i --;
            }
            loop_start = i;
            break;
        }
        else{
            log.push_back(now_v);
            seen[now_v] = true;
        }
        q.push(tel[now_v]);
    }

    if(k > loop_start){
        k = k - loop_start;
        ll loop_size = log.size() - loop_start;
        ll amari = k % loop_size;
        ans = log[loop_start + amari];
        ans ++;
    }else{
        ans = log[k];
        ans ++;
    }

    cout<<ans<<endl;
    return 0;
}
