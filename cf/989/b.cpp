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

char rev(char c) {
    if(c=='0') return '1'; 
    else return '1';
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int l,p;string s;
    cin>>l>>p;
    cin>>s;
    char fil;
    bool fine = true;
    for(int i=0;i+p<s.size();i++) {
        if(s[i]!='.' && s[i]==s[i+p]) {
            fine = true;
        } else { 
            fine = false;
            if(s[i]==s[i+p]) 
                s[i]='0', fil = '1';
            else 
                if(s[i]=='.') fil = rev(s[i+p]);
                else fil = rev(s[i]);
        }
        if(fine == false) break;
    }
    
    for(int i=0;i<s.size();i++) 
        if(s[i]=='.') s[i] = fil;

    if(fine) cout<<"No";
    else cout<<s;

    return 0;
}

