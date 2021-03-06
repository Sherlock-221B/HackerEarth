/**
** Problem: https://www.hackerearth.com/december-circuits-16/algorithm/christmas-string/
**/
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <limits>
using namespace std;
#define LOOP(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPR(i,u,l) for(int (i)=(int)(u);(i)>=(int)(l);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }
template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}

int main(){

    string s;
    cin>>s;
    int N,len=s.length(),matched=0;
    cin>>N;
    vector<string> vs(N);
    LOOP(i,0,N-1) cin>>vs[i];
    VI dissimilarity(N,0),index(N,-1),count(len,0);

    LOOP(i,0,N-1){
        LOOP(j,0,len-1){
            if(s[j]!='*' && s[j]!=vs[i][j]){
                dissimilarity[i]++;
                if(dissimilarity[i]==1) index[i]=j;
            }
        }
        if(dissimilarity[i]==0) matched++;
    }

    LOOP(i,0,N-1) if(dissimilarity[i]==1) count[index[i]]++;
    int answer=0;
    LOOP(i,0,len-1) MAX(answer,count[i]);
    cout<<answer+matched;
    return 0;
}
