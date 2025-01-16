#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII> & segs){
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int beg = -2e9, end = -2e9;
    for(auto p: segs){
        if(end < p.first){
            if(beg!=-2e9) res.push_back({beg, end});
            beg = p.first;
            end = p.second;
        }else{
            end = max(end, p.second);
        }
    }
    if(beg!=-2e9)res.push_back({beg, end});
    segs = res;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int l, r;
        cin>>l>>r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;

    return 0;
}