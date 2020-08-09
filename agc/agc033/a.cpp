#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int H,W;
    cin>>H>>W;
    vector<string> data(H);
    for (int i=0;i<H;i++){
            cin>>data[i];

    }
    queue <vector<int>> d_queue;
    int count =0;
    int ans =0;

    for (int k=0;k<H;k++){
        for (int l=0;l<W;l++){
            if (data[k].at(l) == '#'){
                d_queue.push({k,l,count});
            }

        }
    }

    vector<vector<int>> move = {
            {0,  1},
            {1,  0},
            {-1, 0},
            {0,  -1},
    };
    vector<int> temp_vec(3);
    while (!d_queue.empty()){
        temp_vec = d_queue.front();
        d_queue.pop();
        for (int c=0;c<4;c++){
            int a,b;
            a=move[c][0];
            b=move[c][1];

            if (0 <= temp_vec[0]+a && temp_vec[0]+a < H && 0 <= temp_vec[1]+b && temp_vec[1]+b < W){
                if (data[temp_vec[0]+a][temp_vec[1]+b]== '.'){
                    d_queue.push({temp_vec[0]+a,temp_vec[1]+b,temp_vec[2]+1});
                    ans = max(ans,temp_vec[2]+1);
                    data[temp_vec[0]+a][temp_vec[1]+b] = '#';
                }
            }
        }

    }
    cout<<ans<<endl;


}
