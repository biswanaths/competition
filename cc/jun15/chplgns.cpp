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
        vector<   vector < PII >  * > polys;
        for(int i=0;i<n;i++) {
            int m; cin>>m;
            vector< PII> poly(m);
            for(int j=0;j<m;j++) {
                int a,b;cin>>a>>b;
                poly[j].first=a, poly[j].second=b;
            }
            polys.push_back(&poly);
        }
        vector<int> ord;
        rep(polys.size()) ord.push_back(0);

        for(int i=0;i<polys.size();i++) {
            vector<PII> poly = * (polys[i]);
            int x = poly[0].first, y = (*polys[i])[0].second;
            cout<<x<<" "<<y<<endl;
            for(int j=i+1;j<polys.size();j++) {
                if(isin(x,y,(*polys[j]))) 
                    ord[j]++;
                else 
                    ord[i]++;
            }
        }
        rep(ord.size()) 
            cout<<ord[i]<<" " ; PEL;
    }
    return 0;
}

