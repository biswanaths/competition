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

map<int, set<int> > v;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,k; cin>>n>>k;
    rep(n) { 
        int p; cin>>p; 
        if(v.find(p)==v.end()) 
            v[p] = set<int>();
        v[p].insert(i);
    }

    int ans =0;

    For(v) { 
        if(it->first%k) continue;
        int f0 = (it->first)/k;
        int f1 = it->first;
        int f2 = f1 * k; 
        if(v.find(f2) == v.end() || v.find(f0) == v.end()) continue;
        for(set<int>::iterator i=v[f1].begin(); i!=v[f1].end(); ++i) {
            int f0c=0,f2c=0;
            set<int>::iterator j = v[f2].lower_bound((*i)+1);
            while(j!=v[f2].end()) f2c++,j++; 
            set<int>::iterator k = v[f0].upper_bound((*i)-1);
            while(k!=v[f0].begin()) f0c++,k--;
            ans+=(f0c*f2c);
        }
    }

    cout<<ans;

    return 0;
}

