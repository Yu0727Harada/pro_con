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
    int n,m;
    cin>>n>>m;
    if(n==1){
        int max = 0;
        for (int i = 0; i < m; ++i) {
            int a;
            cin>>a;
            if(a > max){
                cout<<1<<endl;
                max=a;
            }else{
                cout<<-1<<endl;
            }
        }
        return 0;
    }
    vector<int>child(n,0);
    int a;
    cin>>a;
    child[0] = a;
    cout<<0+1<<endl;
    for (int i = 1; i < m; ++i) {
        int n_sushi;
        cin>>n_sushi;
        int r = n - 1 ;
        int l = 0;
        int u = (r + l)/2;
        if(r-l > 1){
            while(!(child[u + 1] < n_sushi && n_sushi <= child[u])){
                if(child[u] > n_sushi){
                    l = u;
                    u = (r + l)/2;
                    if(r-l <= 1) break;
                }else{
                    r = u;
                    u = (r + l)/2;
                    if(r-l <= 1) break;
                }
            }
        }
        if(child[u] < n_sushi){
            child[u] = n_sushi;
            cout<<u+1<<endl;
        }else if(child[u + 1] < n_sushi){
            child[u + 1] = n_sushi;
            cout<<u + 2 <<endl;
        }else{
        cout<<-1<<endl;

        }

    }



    return 0;
}
