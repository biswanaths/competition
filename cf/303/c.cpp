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

#define PB push_back
#define ST first
#define ND second

vector< pair< lld, lld> > trees;

int fell = 0;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    rep(n) { 
        pair<lld,lld> temp; cin>>temp.first>>temp.second;
        trees.PB(temp);
    }

    lld left = -trees[0].second-2;

    rep(n) { 
        pair<lld,lld> cur = trees[i];
        lld posleft = cur.first;
        if(left < cur.first-cur.second) { 
            left = cur.first; 
            fell++;
        } else { 
            if(i < n-1 && cur.first+cur.second < trees[i+1].first ) { 
                left = cur.first + cur.second;
                fell++;
            }
            else if( i==n-1) {
                left = cur.first + cur.second;
                fell++;
            }
        }
        left = max(left,posleft);
        //cout<<cur.first<<" "<<cur.second<<" "<<left<<endl;
    }
    cout<<fell;

    return 0;
}

