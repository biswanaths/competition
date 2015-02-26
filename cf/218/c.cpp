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
#define N 100002
#define MOD 1000000007


string s,o,f;

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>s;
    for(int i=0;i<s.size();i++) {
        int j=i+1;
        for(j=i;j<s.size()&& s[i]==s[j];j++);
        o+=s[i];
        if(j-i>=2) o+=s[i];
        i=j-1;
    }
    cout<<o<<endl;
    char prev=o[0]-1;
    for(int i=0;i<o.size();){
        cout<<f<<endl;
        int j=i;
        string p;
        for(;j<o.size()-1 && s[j] == s[j+1];p+=o[jj+=2);
        cout<<j<<endl;
        if(i==j) {
            f+=o[i];
            i++;
        }
        else {
            f+=o[i];f+=o[i+1];
            i=j;
        }
    }

    cout<<f;
    return 0;
}   

