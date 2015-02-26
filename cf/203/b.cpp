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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)	
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repi(n) for(int i =0;(i)<(int)(n);(i)++)
#define repj(n) for(int j =0;(j)<(int)(n);(j)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)
#define rep1n(n) for(int i=1;i<(int )(n);i++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define PB push_back
#define ST first
#define ND second

int m; int n ; 
struct point { 
    int x,y;
};

bool compare(point a,point b) { 
    return abs(a.x) < abs(b.x) || (abs(a.x) == abs(b.x) && abs(a.y) < abs(b.y) );
}

char xdir(int x) { 
    if( x>0) return 'R';
    else return 'L';
}

char rxdir(int x) { 
    return xdir( -1 * x);
}

char ydir(int y) { 
    return (y>0) ? 'U' :'D';
}

char rydir(int y) { 
    return ydir( -1 * y);
}

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif

    cin>>n; 
    vector<point> points;
    int moves = 0;
    for(int i=0;i<n;i++) { 
        point p; 
        cin>>p.x>>p.y;
        points.push_back(p);
        moves += (p.x && p.y)?6:4;
    }

    cout<<moves<<endl;

    sort(points.begin(),points.end(),compare);

    for(int i=0;i<points.size();i++) { 
        point p = points[i];
        if(p.x !=0 ) { 
            cout<<1<<" "<<abs(p.x)<<" "<<xdir(p.x)<<endl;
        }
        if(p.y !=0) { 
            cout<<1<<" "<<abs(p.y)<<" "<<ydir(p.y)<<endl;
        }
        cout<<2<<endl;
        if(p.y != 0 ) { 
            cout<<1<<" "<<abs(p.y)<<" "<<rydir(p.y)<<endl;
        }
        if(p.x != 0 ) { 
            cout<<1<<" "<<abs(p.x)<<" "<<rxdir(p.x)<<endl;
        }
        cout<<3<<endl;
    }

	return 0;
}
