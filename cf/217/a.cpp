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

int rook(int a,int b,int x,int y) { 
    if(a==x || b==y) {
        return 1;
    }
    else {
        return 2;
    }
}

int bishop(int a,int b,int x,int y) { 
    if((abs(a-x) + abs(b-y)) % 2)
        return 0;
    else if( abs(a-x) == abs(b-y))
        return 1;
    else 
        return 2;
}

int king(int a,int b,int x,int y) {
    int ax = abs(a-x);
    int ay = abs(b-y);
    return max(ax,ay);
}

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    cout<<rook(a,b,x,y)<<" "<<bishop(a,b,x,y)<<" "<<king(a,b,x,y)<<endl;
    return 0;
}

