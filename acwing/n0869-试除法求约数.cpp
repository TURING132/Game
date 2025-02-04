#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

vector<int> get_div(int x){
    vector<int> res;
    for(int i = 1; i <= x/i; i++){
        if (x%i==0){
            res.push_back(i);
            if(i != x/i) res.push_back(x/i);
        } 
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        vector<int> res = get_div(x);
        for(int & a : res){
            printf("%d ", a);
        }
        printf("\n");
    }
    return 0;
}