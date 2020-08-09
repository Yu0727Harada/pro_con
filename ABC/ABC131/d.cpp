//
// Created on 2020/05/28.
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
    vector<pair<int,int>>work(n);

    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        work[i] = {b,a};
        //first=>deadline second=>work time
    }
    sort(rall(work));
    int time = INF;

    for (int j = 0; j < n; ++j) {
        if(time < 0){
            cout<<"No"<<endl;
            return 0;
        }
        if(time > work[j].first){
            time = work[j].first;
        }
        time -= work[j].second;
    }
    if(time < 0){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}


/*

AtCoder王国の王立問題工房でABC管理官の座に就いたキザハシ君は、浮かれるあまり仕事を引き受けすぎてしまいました。

現在の時刻は0です。キザハシ君は1からNまでの番号が振られたN件の仕事を持っています。
キザハシ君が仕事iを終えるにはAi単位時間かかります。また、仕事iの〆切は時刻Biであり、これまでに仕事を終わらせる必要があります。時刻Biちょうどに仕事i を終わらせてもかまいません。

キザハシ君は2件以上の仕事を同時にすることはできませんが、ある仕事を終わらせた直後に別の仕事を始めることはできます。

キザハシ君はすべての仕事を〆切までに終わらせることができるでしょうか。可能ならば Yes、不可能ならば No を出力してください。
 */
