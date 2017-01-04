/**
** Problem: https://www.hackerearth.com/january-easy-17/algorithm/simple-function/
**/
#include<bits/stdc++.h>
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

bool simple(set<char> &s1,set<char> &s2){
    for(char c='9';c>='1';c--){
        if(s1.find(c)!=s1.end() && s2.find(c)!=s2.end()){
            if(c%2==0) return true;
            else return false;
        }
    }
    return true;
}

int main(){

    int t;
    cin>>t;
    cout<<fixed;
    cout<<setprecision(3);
    while(t--){
        int n1,n2;
        cin>>n1>>n2;
        vector<string> vs1(n1),vs2(n2);
        LOOP(i,0,n1-1) cin>>vs1[i];
        LOOP(i,0,n2-1) cin>>vs2[i];
        set<char> s1[n1],s2[n2];
        LOOP(i,0,n1-1){
            for(char c:vs1[i]){
                s1[i].insert(c);
                if(s1[i].size()==9) break;
            }
        }
        LOOP(i,0,n2-1){
            for(char c:vs2[i]){
                s2[i].insert(c);
                if(s2[i].size()==9) break;
            }
        }
        LL count=0;
        LOOP(i,0,n1-1){
            LOOP(j,0,n2-1){
                if(simple(s1[i],s2[j])) count++;
            }
        }
        //DEBUG(count);
        double prob=count/((double)n1*n2);
        cout<<prob<<endl;
    }

    return 0;
}
