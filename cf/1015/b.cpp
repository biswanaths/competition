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


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; string s,t;
    int moves = 0 ;
    vector<int> ans;
    cin>>n;
    cin>>s>>t;
    int v[52];
    rep(n) { 
        bool found = false;
        for(int j=0;j<n;j++) { 
            if(t[i]==s[j]) { 
                v[j] = i;
                s[j]= 'A';
                found = true; 
                break;
            }
        }
        if(!found) { 
            cout<<-1; return 0;
        }
    }

    for(int i=0;i<n;i++) { 
        for(int j=0;j<n-1;j++) { 
            if(v[j] >  v[j+1]) { 
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                moves++;
                ans.push_back(j+1);
            }
        }
    }
    cout<<moves<<endl;
    for(auto const& value: ans) 
        cout<< value << " ";

    


    return 0;
}

