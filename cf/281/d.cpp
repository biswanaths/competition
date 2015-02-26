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

struct state {
    LL a,b,c,d;
};

bool operator < (const state &l, const state &r) { return l.a < r.a && l.b < r.b && l.c < r.c && l.d < r.c ; }


map<state,int> states;

int move(struct state cur) {
    if(states.find(cur) == states.end()) {
        if(cur.a %2 ==0) { 
            struct state next = cur;
            next.a = next.a/2;
            value = move(next);
        }
        if(cur.
        // not found
    } else { 
        return states[cur];
    }
}


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    struct state cur; 
    cur.a = a; cur.b = b; cur.c = c; cur.d = d;
    return 0;
}

