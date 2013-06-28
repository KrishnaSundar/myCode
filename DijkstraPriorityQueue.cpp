//  Topic : Dijkstra's algorithm
//  Language : C++
//  DataStructure used : Priority Queue
//  Date : 28 - 6 - 2013
//  Time : 3:25 PM
//sufficient explanations are given in the code below it is only for the ones who are having a little idea prior 
//to this code about shortest paths if not naveen garg IIT delhi lectures will help u and CLRS.Have a idea on
//why this works before jumping to implementaion view correctness for each and everything.If u have an idea lets 
//move on. 
//dont be scared of why so much includes it is my usual
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
 #define pi pair<int,int>
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
int N,E;
void Dijkstra(vector<vpi >& G,vi& D,int source) {
//here we use the prioritized queue for greey approach.
        priority_queue<pi,vpi,greater<pi > > Q;
        D[source]=0;//initialize for the source
        pi t;
        int ud,vd,u,v;
        vector<bool> visited(N,false);vpi::iterator it;
        Q.push(mp(0,source));
        while(!Q.empty()) {
                t = Q.top();//extract min
                Q.pop();
                u = t.Y;ud = t.X;
                visited[u] = true;// this one is done and pushed to S(set of found shortest paths)
                if(ud <= D[u]){ // this check is necessary don't omit this beacause this
                                //  eliminates the old distances in the priority queue that are not updated
                                // beacause you are not overwriting here in the queue so only.
                trav(G[u],it) {//for all adj in S'(set of all nodes where the shortest paths are not found)
                                t = *it;
                                v = t.Y;vd = t.X;                        
                                if(!visited[v] && D[v] > ud+vd) {// if itcan be relaxed
                                        D[v] = ud+vd; //relax it
                                        Q.push(mp(D[v],v));//insert it in queue note:not updating only insertion^
                                }                
                        }
                }
        }
}
// remember this one's for UNDIRECTED GRAPHS 
int main() {
        int i,source,u,v,W;
        scanf("%d%d",&N,&E);// get the number of nodes and edges
        vi D (N,MaxV);
        vector<vpi > G(N);//u can also have a array of vectors like vector<int> G[N]; but in the above module trav
                          //wont work u need to write a for loop of for(i=0;i<G[u].size();i++)
        F(i,0,E){
                scanf("%d%d%d",&u,&v,&W);
                G[u].P_B(mp(W,v));//if directed stop with this
                G[v].P_B(mp(W,u));// as it is undirected u need this        
        }
Dijkstra(G,D,source)// call dijkstra
        F(i,0,N){     
        if(i!=source)// just ur display at last
                cout<<"the shortest path from"<<source<<"to the node "<<i<<"is : "<<D[i]<<endl;
        }
return 0;
}
