#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

int bfs(string start){
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    q.push(start);
    d[start] = 0;

    int da[4] = {-1, 0, 1, 0}, db[4] = {0, 1, 0, -1};

    while(q.size()){
        auto t = q.front();
        q.pop();
        int dis = d[t];
        if(t == end) return dis;
        // find
        int k = t.find('x'); // 找到指定元素的第一个index
        int x = k / 3, y = k%3;
        for(int i = 0; i < 4; i++){
            int a=  x + da[i], b = y + db[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
                swap(t[k], t[a * 3 + b]);
                if(!d.count(t)){
                    d[t] = dis + 1;
                    q.push(t);
                }
                swap(t[k], t[a * 3 + b]); // 恢复是为了进行下一个方向的探索
            }
        }
    }
    return - 1;
}

int main(){
    string start;
    for(int i = 0; i <9; i++){
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start)  << endl;
    return 0;
}