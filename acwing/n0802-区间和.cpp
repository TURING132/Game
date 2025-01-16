#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
vector<int>all;
vector<PII>add, query;
const int N = 300010;
int a[N], s[N];
int n, m;

int discrete(int x){
    int l = 0, r = all.size()-1;
    while(l<r){ // find first >= x
        int mid = l+r>>1;
        if(all[mid] >= x) r = mid;
        else l = mid+1; 
    }
    return l+1;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i < n; i++){
        int x, c; scanf("%d%d",&x,&c);
        add.push_back({x,c}); 
        all.push_back(x);
        }
    for(int i=0; i<m;i++){
        int l, r;scanf("%d%d",&l,&r);
        query.push_back({l,r}); 
        all.push_back(l); all.push_back(r);
    }
    // 去重
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for(int i = 0; i < add.size(); i++){
        a[discrete(add[i].first)] += add[i].second;
    }
    for(int i = 1; i < all.size()+1; i++)s[i] = s[i-1] + a[i];
    for(auto q : query){
        cout << s[discrete(q.second)] - s[discrete(q.first)-1] << endl;
    }

    return 0;
}