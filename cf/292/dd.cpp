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

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

char a[2002][2002];  
int n,m;

void print() { 
    for(int i=0;i<n;i++) { 
        for(int j=0;j<m;j++) { 
            cout<<a[i][j];
        }
        cout<<endl;
    }
}



int consistent(int x,int y) { 
    int f =0;
    if(x>0 && a[x-1][y]=='.' ) f++;
    if(x<n-1 && a[x+1][y]== '.') f++;
    if(y>0 && a[x][y-1]=='.' ) f++;
    if(y<m-1 && a[x][y+1]== '.') f++;
    return f;
}

char consistentchar(int x,int y) { 
    if(x>0 && a[x-1][y]=='.') return 'v';
    if(x<n-1 && a[x+1][y]== '.') return '^';
    if(y>0 && a[x][y-1]=='.') return '>'; 
    if(y<m-1 && a[x][y+1]== '.') return '<'; 
    return '.';
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n>>m;int change;
    for(int i=0;i<n;i++) {
        string s; cin>>s;
        for(int j=0;j<m;j++) { 
            a[i][j]=s[j];
        }
    }

    while(1) { 
        change = 0;
        for(int i=0;i<n;i++) { 
            for(int j=0;j<m;j++) { 
                if(a[i][j]=='.') {
                    if(consistent(i,j)==1) {
                        a[i][j] = consistentchar(i,j);
                        if(a[i][j]=='^') a[i+1][j]='v';
                        else if(a[i][j]=='v') a[i-1][j]='^';
                        else if(a[i][j]=='<') a[i][j+1]='>';
                        else if(a[i][j]=='>') a[i][j-1]='<';
                        change++;
                        //print();
                    }
                }
            }
        }
        if(change==0) break;
        change = 0;
        for(int i=n-1;i>=0;i--) { 
            for(int j=m-1;j>=0;j--) { 
                if(a[i][j]=='.') {
                    if(consistent(i,j)==1) {
                        a[i][j] = consistentchar(i,j);
                        if(a[i][j]=='^') a[i+1][j]='v';
                        else if(a[i][j]=='v') a[i-1][j]='^';
                        else if(a[i][j]=='<') a[i][j+1]='>';
                        else if(a[i][j]=='>') a[i][j-1]='<';
                        change++;
                        //print();
                    }
                }
            }
        }
        if(change==0) break;
        change = 0;
        for(int i=n-1;i>=0;i--) { 
            for(int j=0;j<m;j++) { 
                if(a[i][j]=='.') {
                    if(consistent(i,j)==1) {
                        a[i][j] = consistentchar(i,j);
                        if(a[i][j]=='^') a[i+1][j]='v';
                        else if(a[i][j]=='v') a[i-1][j]='^';
                        else if(a[i][j]=='<') a[i][j+1]='>';
                        else if(a[i][j]=='>') a[i][j-1]='<';
                        change++;
                        //print();
                    }
                }
            }
        }
        if(change==0) break;
        change = 0;
        for(int i=0;i<n;i++) { 
            for(int j=m-1;j>=0;j--) { 
                if(a[i][j]=='.') {
                    if(consistent(i,j)==1) {
                        a[i][j] = consistentchar(i,j);
                        if(a[i][j]=='^') a[i+1][j]='v';
                        else if(a[i][j]=='v') a[i-1][j]='^';
                        else if(a[i][j]=='<') a[i][j+1]='>';
                        else if(a[i][j]=='>') a[i][j-1]='<';
                        change++;
                        //print();
                    }
                }
            }
        }
        if(change==0) break;
    }
    int missing = 0 ;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) { 
            missing+= ( a[i][j]=='.');
        }
    }
    if(missing ==0) { 
        print();
    } else { 
        cout<<"Not unique";
    }

    return 0;
}

