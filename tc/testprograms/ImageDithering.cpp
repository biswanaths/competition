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

using namespace std;

#define fori(n) for(int i=0;i<(n);i++) 

class ImageDithering {
public:
	int count(string dithered, vector <string> screen) {
		int c =0;
		for(int i=0;i<screen.size();i++) { 
			for(int j=0;j<screen[0].size();j++) { 
				if(dithered.find(screen[i][j])!=-1) c++;
			}
		}
		return c;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ImageDithering *obj;
	int answer;
	obj = new ImageDithering();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "BW";
	string t1[] = {"AAAAAAAA","ABWBWBWA","AWBWBWBA","ABWBWBWA","AWBWBWBA","AAAAAAAA"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 24;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "BW";
	string t1[] = {"BBBBBBBB","BBWBWBWB","BWBWBWBB","BBWBWBWB","BWBWBWBB","BBBBBBBB"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 48;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "ACEGIKMOQSUWY";
	string t1[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 150;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "CA";
	string t1[] = {"BBBBBBB","BBBBBBB","BBBBBBB"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "DCBA";
	string t1[] = {"ACBD"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
