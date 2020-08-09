//
// Created on 2020/01/18.
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

int main() {
    int w;
    int h;
    int n;
    cin>>h>>w>>n;

    int ans = 0;
    int now = 0;

    if (w>=h){
        for (int i = 1; i <= h; ++i) {
            ans ++;
            now +=  w;
            if (n <= now) {
                cout<<ans<<endl;
                return 0;
            }
        }
        for (int j = 1; j <= w; ++j){
            ans ++;
            now += (h -1);
            if(n <= now){
                cout<<ans<<endl;
                return 0;
            }
        }


    }
    else{
        for (int i = 1; i <= w; ++i) {
            ans ++;
            now +=  h;
            if (n <= now) {
                cout<<ans<<endl;
                return 0;
            }
        }
        for (int j = 1; j <= h; ++j){
            ans ++;
            now += (w -1);
            if(n<= now){
                cout<<ans<<endl;
                return 0;
            }
        }


    }

    cout<<ans<<endl;
}
