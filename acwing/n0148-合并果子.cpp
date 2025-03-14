#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        heap.push(x);
    }
    int res;
    while(heap.size() > 1){
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    printf("%d", res);

    return 0;
}