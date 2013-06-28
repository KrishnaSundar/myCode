//coder : krishna sundar
//topic : Dijkstra algorithm
//data structure used : SET
//implementation : greedy implementation with set same complexity will be provided as that of using the priority queue
//date and time : 28-6-2013 & 4:30 PM
//note : if u have not seen my code for Dijkstra using priority queue please I recommand you to view that one and
//       come here then you will have the clear idea of what is going on.That program will tell u the idea.

#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <string.h>
#include <string>
#include <queue>
#include <iterator>
using namespace std;
//my set of templates
 #define F(i,start,n) for(int i=start;i<n;i++)
 #define sz(a) int((a).size()) 
 #define P_B push_back 
 #define all(c) (c).begin(),(c).end() 
 #define trav(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define ll long long
 #define pi pair<float,int>
 #define pll pair<long,long>
 #define pii pair<int,pi >
 #define X first
 #define Y second
 #define mp make_pair
 #define vi vector<int>
 #define vs vector<string>
 #define vpi vector<pi >
 #define vpii vector<pii >
 #define vpll vector<pll >
 #define MaxV (1<<16)
 #define LLMaxV (1ll<<60)
 #define vl vector<long>
 #define vll vector<long long>
 template<class T>string ToString(T t){stringstream s;s<<t;return s.str();}
 template<class T>void ToOther(T& t,string a){stringstream s(a);s>>t;}
//my declarations
    int N,E;      
void myDijkstra (vector<vpi >& G,vector<float>& D,int source) {
        //source initialization
        set<pi > Q;int u,v;float ud,vd,t;vpi::iterator itv;
        vector<bool> visited(N,false);
        D[source] = 0; 
        Q.insert(mp(0.0,source));
        while(!Q.empty()) {
               u = (Q.begin())->Y;
               ud = (Q.begin())->X;
               visited[u] = true;
               Q.erase(Q.begin());//pop_the least labelled distance
               //thus for every adjacent nodes available not parent. 
               trav(G[u],itv){//here we are updating in the set directly finding the element 
                              //so no check is needed like that of in the priority queue implementation.
                      v = itv->Y;
                      vd = itv->X;
                      if(!visited[v] && D[v] > ud + vd){//if a more optimal distance is found then update
                                t = D[v];
                                D[v] = ud+vd;                      
                                if(present(Q,mp(t,v))) {
                                       Q.erase(Q.find(mp(t,v))); 
                                }
                               //else insert the new node distance
                                        Q.insert(mp(D[v],v));  
                      }
               }
        }
}
//driver function 
int main() {
int i,u,v,source;float W;
scanf("%d%d",&N,&E);
vector<vpi > G(N);
vector<float> D(N,1000.0);
printf("Enter the number of edges u want");
        F(i,0,E){
                        scanf("%d%d%f",&u,&v,&W);                                                        
                        G[u].P_B(mp(W,v));
                        G[v].P_B(mp(W,u));
              }
scanf("%d%d",&source);
myDijkstra(G,D,source);
F(i,0,N)
      if(i!=source)
                cout<<"The shortest path in the given graph from "<<source<<" to "<<i<<" is :"<<D[i]<<endl;              
return 0;
}
