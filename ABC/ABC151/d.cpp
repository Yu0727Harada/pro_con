//
// Created on 2020/01/12.
//

#include <istream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<ctime>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;//(n,vector<int>(m,initialize))

//BFSで迷路をとく
int maze(){
    int H,W;
    cin>>H>>W;//迷路の縦横を受け取る
    vector<string> data(H);
    for (int i=0;i<H;i++){
        cin>>data[i];//文字列として格納
    }
    queue <vector<int>> d_queue;
    int count =0;//移動回数をカウントする
    int ans =0;
    vector<pair<int,int>> move = {
            {0,  1},
            {1,  0},
            {-1, 0},
            {0,  -1},
    };

    for (int k=0;k<H;k++){
        for (int l=0;l<W;l++){
            if (data[k].at(l) != '#'){//必要に応じて条件を変更
                d_queue.push({k,l,count});//スタート位置をキューにセット

                vector<string> temp_data = data;//データをディープコピー。元のデータを残しておきたい時に使う
                while (!d_queue.empty()){
                    vector<int> now_queue = d_queue.front();
                    d_queue.pop();
                    temp_data[now_queue[0]][now_queue[1]]= '#';//現在地の状態を変更。場合によっては別の配列に入れる。移動済みをマークする。場合によってはゴールか判定する
                    for (pair<int,int>move_array:move){
                        if (0 <= now_queue[0]+move_array.first && now_queue[0]+move_array.first < H && 0 <= now_queue[1]+move_array.second && now_queue[1]+move_array.second < W){//範囲外に出ないかどうかチェック
                            if (temp_data[now_queue[0]+move_array.first][now_queue[1]+move_array.second]== '.'){//次に移動できるかチェック
                                d_queue.push({now_queue[0]+move_array.first,now_queue[1]+move_array.second,now_queue[2]+1});//移動できたら移動先をキューに入れる
                                ans = max(ans,now_queue[2]+1);//答えを更新する（移動の最大値など）
                                temp_data[now_queue[0]+move_array.first][now_queue[1]+move_array.second] = '#';//移動先を訪問済みにする
                            }
                        }
                    }
                }
            }
        }

    }
    cout<<ans<<endl;

}

int main(){
    maze();

}