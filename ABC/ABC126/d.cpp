#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int N;
    cin>>N;

    vector<int>color(N+1,-1);
    vector<vector<int>>edge_gragh(N+1, vector<int>());
    vector<vector <long long> > distance (N+1,vector<long long>());

    for (int i = 0; i < N-1; ++i) {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        edge_gragh[u].push_back(v);
        distance[u].push_back(w%2);
        edge_gragh[v].push_back(u);
        distance[v].push_back(w%2);

    }
    color[1]=0;
    queue<int>q;
    q.push(1);
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < edge_gragh[now].size(); ++i) {
            int U =edge_gragh[now][i];
            int W=distance[now][i];
            if (color[U] != -1) continue;
                color[U] =(color[now]+W) % 2;
                q.push(U);
        }
    }
    for (int j = 1; j < N+1; ++j) {
        cout<<color[j]<<endl;
    }

}
