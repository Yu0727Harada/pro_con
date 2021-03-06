//
// Created on 2020/06/06.
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
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    cin>>n;
    vector<string>a(n);
    vector<char>ans(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int r = n;
    for (int j = 0; j < n/2; ++j) {
        r --;
        bool find = false;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if(a[j][i] == a[r][k]){
                    ans[j] = a[j][i];
                    ans[r] = a[j][i];
                    find = true;
                    break;
                }
            }
            if(find)break;
        }
        if(!(find)){
            cout<<-1<<endl;
            return 0;
        }
    }
    if(n % 2 ==1){
        ans[n/2] = a[n/2][0];
    }
    for (int l = 0; l < ans.size(); ++l) {
        cout<<ans[l];
    }
    cout<<endl;
    return 0;
}
