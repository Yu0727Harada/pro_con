//
// Created on 2021/04/03.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    double k;
    cin>>k;

    string s,t;
    cin>>s>>t;


    vector<double> card(10,0);

    for (int i = 0; i < 4; ++i) {
        card[s[i] - '0'] ++;
    }
    for (int i = 0; i < 4; ++i) {
        card[t[i] - '0']++;
    }

    double ans = 0;

    for (int i = 1; i <= 9 ; ++i) {
        for (int j = 1; j <= 9; ++j) {
            int takahashi = 0;
            int aoki = 0;

            string s_temp = s;
            string t_temp = t;
            if(card[i] + 1 > k) continue;
            if(card[j] + 1 > k) continue;
            if(i == j && card[i] + 2 > k)continue;
            s_temp[4] = char('0' + i);
            t_temp[4] = char('0' + j);

            vi s_card(10,0);
            vi t_card(10,0);

            for (int l = 0; l < s_temp.size(); ++l) {
                s_card[s_temp[l] - '0']++;
                t_card[t_temp[l] - '0']++;
            }

            for (int l = 1; l <= 9; ++l) {
                takahashi += l * pow(10,s_card[l]);
                aoki += l * pow(10,t_card[l]);
            }
            if(takahashi > aoki){
                if(i == j){
                    double l = ((k - card[i]) / (9 * k - 8));
                    double r = ((k - (card[j] + 1)) / (9 * k - 9));
                    ans += l * r;

                }else{
                    double l = ((k - card[i]) / (9 * k - 8));
                    double r = ((k - card[j]) / (9 * k - 9));
                    ans += l * r;

                }
            }

        }
    }


    printf("%.20f\n", ans);

    return 0;
}
