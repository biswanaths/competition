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

#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

LL cs[2001][2001];



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m; cin>>n>>m; 
    vector< pair<LL, pair<int, int>  > > sa; 
    LL s;
    vector<LL> r(n);
    vector<LL> c(m);

    rep(n) cin>>r[i];
    rep(m) cin>>c[i];
    cin>>s;
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=m;j++) { 
            cs[i][j] = cs[i-1][j] + cs[i][j-1] - cs[i-1][j-1] + r[i-1] * c[j-1];
            cout<<cs[i][j]<<" ";
            sa.push_back( { cs[i][j] , { i,j}});
        }
        cout<<endl;
    }

    LL ma = -1;

    sort(sa.begin(), sa.end());

    for(int i=0, j= 1; i < sa.size() && j<sa.size(); ) { 
        auto l = sa[i].second, r = sa[j].second;
        cout<<l.first<<":"<<l.second<<" "<<r.first<<":"<<r.second<<" ";
        if( r.first>= l.first && r.second>= l.second)  {
            LL diff = cs[r.first][r.second] - cs[1][r.second] -cs [ l.second][1] + cs[l.first][l.second];
            cout<<diff<<endl;
            if(diff <=s) {
                LL carea = ( r.first- l.first +1 ) * ( r.second-l.second+1);
                ma = ( ma > carea) ? ma : carea;
                j++; 
            } else i++;
        } else { 
            j++;
        }

    }

    cout<<ma<<endl;

    cout<<"good"<<endl;

    return 0;
}

