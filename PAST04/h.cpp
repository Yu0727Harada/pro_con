//
// Created on 2020/11/08.
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;



int main() {

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>mass(n,vector<int>(m));

    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < m; ++j) {
            mass[i][j] = s[j] - '0';
        }
    }


    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {//今見ているマス目

            for (int l = 0; l < 10; ++l) {//ここの数字にする
                int temp_k = k;
                auto mass_test = mass;
                int i1;
                for (i1 = 0; i1 < min(n,m) && temp_k >= 0 && i1 +i < n && i1 +j < m; ++i1) {//この数字分したとみぎに見ていく

                    for (int k1 = 0; k1 <= i1 && temp_k >= 0 && i + k1 < n; ++k1) {
                        for (int l1 = 0; l1 <= i1 && temp_k >= 0 && j + l1 < m; ++l1) {
                            if(mass_test[i + k1][j + l1] != l && temp_k > 0){
                                temp_k --;
                                mass_test[i + k1][j+l1] = l;
                            }else if(mass_test[i +k1][j + l1] != l && temp_k <= 0){
                                chmax(ans, i1);
                                temp_k --;
                            }
                        }

                    }

                }
                if(temp_k >= 0){
                    chmax(ans,i1);
                }

            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
