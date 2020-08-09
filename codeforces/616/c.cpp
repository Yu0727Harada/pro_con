//
// Created on 2020/02/03.
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
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    if(m==1){
        int max_v =max(a[0],a[n-1]);
        cout<<max_v<<endl;
        return;
    }
    if(k >= m -1) {
        k = m - 1;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < k; ++i) {
        if (a[start]<a[n-1-end]) start ++;
        else end ++;
    }
    int min_value = *min_element(a.begin()+start,a.begin()+start+(m-k-1));
    if (a.end()-end != a.end()-end-(m-k-1)){
        min_value = min(min_value, *min_element(a.end()-end-(m-k-1),a.end()-end));
    }
    cout<<min_value<<endl;
    return;



}

int main() {
    int n;
    cin>>n;
    while(n){
        n--;
        solve();
    }


}
