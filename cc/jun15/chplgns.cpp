#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

vector<   vector < PII >   > polys;

bool isin(double x,double y,vector<PII>& poly) {
    int i,j, c=0,sz =poly.size();
    double xi,yi,xj,yj;
    for(i=0,j=sz-1 ; i < sz ; j = i++) {
        xi = poly[i].first,yi = poly[i].second, xj = poly[j].first, yj= poly[j].second;
        if( (( yi > y) != ( yj > y)) && 
            ( x < ( xj - xi ) * ( y-yi) / (yj-yi) + xi ))
            c = !c;
    }
    return c;
}

vector<int> merge(vector<int> left,vector<int> right) {
    vector<int> merged;
    int i=0,j=0;
    for(;i<left.size() && j<right.size();) {
        int x = polys[left[i]][0].first,y =polys[left[i]][0].second;
        if(isin(x,y,polys[right[j]]))
        //if(left[i] <= right[j]) 
            merged.push_back(left[i++]);
        else 
            merged.push_back(right[j++]);
    }

    while(i<left.size()) merged.push_back(left[i++]);
    while(j<right.size()) merged.push_back(right[j++]);
    return merged;
}


vector<int> ms(vector<int> list) {
    if(list.size() <= 1)
        return list;
    vector<int> left, right;
    int m = list.size()/2;
    for(int i=0;i<m;i++) left.push_back(list[i]);
    for(int i=m;i<list.size();i++) right.push_back(list[i]);
    left = ms(left);
    right = ms(right);
    list = merge(left,right);
    return list;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        polys.resize(n);
        for(int i=0;i<n;i++) {
            int m; cin>>m;
            polys[i].resize(m);
            for(int j=0;j<m;j++) {
                int a,b;cin>>a>>b;
                polys[i][j].first=a, polys[i][j].second=b;
            }
        }
        vector<int> ord;
        rep(polys.size()) ord.push_back(i);
        ord = ms(ord);
/*
        for(int i=0;i<polys.size();i++) {
            int x = polys[i][0].first, y = polys[i][0].second;
            for(int j=i+1;j<polys.size();j++) {
                if(isin(x,y,polys[j])) 
                    ord[j]++;
                else 
                    ord[i]++;
            }
        } */
        vector<int> less(ord.size());
        rep(ord.size()) 
            less[ord[i]]=i;
        rep(less.size())
            cout<<less[i]<<" " ; PEL;
    }
    return 0;
}

