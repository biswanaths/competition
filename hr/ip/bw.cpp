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
#include <climits>
#include <cfloat>


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

vector<pair<double,double> > points;
double ma = -2, mi = 2;


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    rep(n) {
        double x,y; cin>>x>>y;
        points.push_back(make_pair(x,y));
        ma = ( ma<y)?y:ma;
        mi = ( mi>y)?y:mi;
    }

    bool square = true;
    vector<bool> ts;

    For(points) {
        square = square && (it->second == ma || it->second ==mi);
        if(it->second ==ma ) {
            if(ts.size()==0) ts.push_back(1);
            else {
                if(ts[ts.size()-1]==1) ;
                else ts.push_back(1);
            }
        }

        if(it->second ==mi ) {
            if(ts.size()==0) ts.push_back(0);
            else {
                if(ts[ts.size()-1]==0) ;
                else ts.push_back(0);
            }
        }
    }

    cout<<(square?"square":"sine")<<"-wave"<<endl;
    cout<<ts.size()/2<<endl;

    return 0;
}

