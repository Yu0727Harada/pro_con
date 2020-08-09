//
// Created on 2020/04/09.
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
#include <stdio.h>

using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
const int MAX = 1000000;

vector<int>List(MAX);
int top = 0;
int last = 0;

void insert_x(int x){
    top --;
    if(top != last && top >= 0){
        List[top] = x;
    }else if(top != last && top <0){
        List[top + MAX] = x;
    }else{
        //overflow
    }
}

void delete_first(){
    if(top == last){
        //list is empty
    }else{
        top ++;
    }
}

void delete_last(){
    if(top == last){
        //list is empty
    }else{
        last --;
    }
}

void delete_x(int x){
    if(top == last){
        //list is empty
    }else{
        bool find = false;
        for (int i = 0; i < last - top; ++i) {
            int j = top+i;
            if(j<0){
                j += MAX;
            }
            if(List[j] == x && !find){
                find = true;
            }
            if(find){
                if(j+1 == MAX){
                    List[j] = List[0];
                }else{
                    List[j] = List[j+1];
                }
            }
        }
        if(find) delete_last();
    }
}

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        char command[20];
        scanf("%s",command);
        string command_s = command;
        if(command_s == "deleteFirst"){
            delete_first();
        }else if(command_s == "deleteLast"){
            delete_last();
        }else{
            int a;
            scanf("%d",&a);
            if(command_s == "insert"){
                insert_x(a);
            }else if(command_s == "delete"){
                delete_x(a);
            }
        }
    }

    int j = top;
    if(j<0){
        j += MAX;
    }
    cout<<List[j];
    for (int i = 1; i < last - top; ++i) {
        j = top+i;
        if(j<0){
            j += MAX;
        }
        cout<<" "<<List[j];
    }
    cout<<endl;

}

