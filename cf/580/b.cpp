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

vector<PII> fs;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,d;cin>>n>>d;
    rep(n) {
        int m,f; cin>>m>>f;
        fs.push_back(make_pair(m,f));
    }

    sort(fs.begin(),fs.end());

    lld first=fs[0].first, total=0, mtotal =0;

    rep(n) { 
        if(fs[i].first - first >= d) {
            first = fs[i].first;
            total = fs[i].second;
        } else {
            total += fs[i].second;
        }
        if(mtotal < total ) mtotal = total;
    }

    cout<<mtotal<<endl;

    return 0;
}

