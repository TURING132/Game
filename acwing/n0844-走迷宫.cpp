#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;

const int N = 110;
int m, n;
int mt[N][N] = {0}, d[N][N] = {0};
bool st[N][N] = {false};

int a[4] = {1, 0, -1, 0};
int b[4] = {0, 1, 0, -1};

int bfs(){
    queue<PII> q;
    q.push({0, 0});
    while(!q.empty()){
        PII ne = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            PII next = {ne.first + a[i], ne.second + b[i]};
            if (next.first >= 0 && next.first < n && next.second >=0 && next.second <m 
                && !st[next.first][next.second] && mt[next.first][next.second] == 0){
                    st[next.first][next.second] = true;
                    d[next.first][next.second] = d[ne.first][ne.second] + 1;
                    q.push(next);
                }
        }
    }
    return d[n-1][m-1];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mt[i][j]);
        }
    }
    printf("%d", bfs());
    return 0;
}