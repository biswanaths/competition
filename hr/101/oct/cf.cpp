#include <iostream>

using namespace std;

int m; int n ; int c;

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    int t;cin>>t;
    while(t--) {
        cin>>n>>c>>m;
        int total = n/c; 
        int temp = total; 
        while(temp>=m) {
             int tc = 1,mm=m;
             while(mm<=temp) {
                 tc+=mm;
                 mm *=m;
            }
             mm/=m,tc-=mm;
             cout<<tc<<" "<<mm<<endl;
             temp-= mm; 
             temp+=1;
             total += tc; 
        }
        cout<<total<<endl;
    }
    return 0;
}
