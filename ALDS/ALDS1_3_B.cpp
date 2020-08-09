//
// Created on 2020/04/08.
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


using namespace std;
const long long LINF =1e18;
const int INF = 1e9;

struct process{
    string name;
    int quantum;
    int now_time = 0;

};

int main() {
    int n,Q;
    cin>>n>>Q;
    queue<process>q;

    vector<process>l(n);
    for (int i = 0; i < n; ++i) {
        string _name ;
        int _quantum;
        cin>>_name>>_quantum;
        l[i] ={_name,_quantum};
        q.push(l[i]);
    }
    int all_time = 0;
    while(!(q.empty())){
        process target;
        target = q.front();
        q.pop();
        int add = min(Q,target.quantum-target.now_time);
        target.now_time += add;
        all_time += add;
        if(target.now_time == target.quantum){
            cout<<target.name<<" "<<all_time<<endl;
        }else{
            q.push(target);
        }
    }


}
