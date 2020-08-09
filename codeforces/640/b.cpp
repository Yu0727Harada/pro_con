//
// Created on 2020/05/09.
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

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>ans;
    if(n%k==0){
        cout<<"YES"<<endl;
        for (int i = 0; i < k; ++i) {
            ans.push_back(n/k);
        }
    }else if(n/k <1){
        cout<<"NO"<<endl;
        return;
    }
    else{
        if(((n%k)+(n/k))%2 == (n/k)%2){
            cout<<"YES"<<endl;
            for (int i = 0; i < k-1; ++i) {
                ans.push_back(n/k);
            }
            ans.push_back(n%k+n/k);
        }else if(k%2 == 1 &&n%k+n/k-(k-1) >= 1){
            cout<<"YES"<<endl;
            for (int i = 0; i < k-1; ++i) {
                ans.push_back(n/k+1);
            }
            ans.push_back(n%k+n/k-(k-1));
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<ans[0];
    for (int j = 1; j < ans.size(); ++j) {
        cout<<" "<<ans[j];
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t){
        t--;
        solve();
    }


    return 0;
}
