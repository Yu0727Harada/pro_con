//
// Created on 2020/04/23.
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
    int ans = 0;
    int n,d;
    cin>>n>>d;
    vector<vector <int> > x (n,vector<int>(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin>>x[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int j = k + 1; j < n ; ++j) {

            int distance = 0;
            for (int i = 0; i < d; ++i) {
                distance += pow(x[k][i]-x[j][i],2);
            }
            double distance_2 = sqrt(distance);
            if(int(distance_2) == distance_2){
                ans ++;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
