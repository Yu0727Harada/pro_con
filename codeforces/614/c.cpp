//
// Created on 2020/01/20.
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

int maze(){
    int H;
    int q;
    cin>>H;//迷路の縦横を受け取る
    cin>>q;

    vector<vector<string>> data(H,vector<string>(2,"."));
    for (int j = 0; j < H; ++j) {
        data[j][0] = ".";
        data[j][1] = ".";
    }


            //if (data[k].at(l) != '#'){//必要に応じて条件を変更

            int ok = 0;
            int d =0;
            for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(data[b][a] == "$"){
            data[b][a] = ".";
            d = -1;
        }
        else{
            data[b][a] = '$';
            d = 1;
        }

        bool frag = false;
        for (int j = -1; j <= 1; ++j) {
            if(0 <= b+j && b+j <H){

                if (data[b+j][1-a] == "$") ok += d;
            }


        }
                if (ok >0){
                    cout<<"No"<<endl;
                }else{
                    cout<<"Yes"<<endl;
                }
    }
    return 0;

}
int main() {
    maze();
}
