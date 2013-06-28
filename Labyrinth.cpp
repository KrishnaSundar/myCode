//coder:Krishna
//problem:Labyrinth-SPOJ
//implementation: 2-BFS
//date and time:28-6-2013 && 9:00 PM.
// sorry actually the code could be more optimized by using direction array technique but this was the 
// coded before i had knowledge of it so i dont actually feel of editing it now <LAZINESS level-38>.
//but the code is here.

#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<cstring>
using namespace std;

pair<long int,long int> farthest;

long int BFS(vector<string>& labyrinth,long int m,long int n,pair<long int,long int> source_grid,bool setflag)
{
long int longest_path=0,i,j;
long int visited[m+1][n+1];
long int layer_update[m+1][n+1];
for(i=0;i<=m;i++)
{
        for(j=0;j<=n;j++)
        {
                visited[i][j]=0;
                layer_update[i][j]=1;
        }
}
queue< pair<long int,long int> > Q;
pair<long int,long int> t;
Q.push(source_grid);
visited[source_grid.first][source_grid.second]=1;
if(setflag)
labyrinth[source_grid.first][source_grid.second]='#';
long int u,v;
while(!Q.empty())
        {
                t=Q.front();
                Q.pop();
                u=t.first;v=t.second;
                long int x1=u+1,y1=v,x2=u-1,y2=v,x3=u,y3=v+1,x4=u,y4=v-1;
                if(setflag==true)
                labyrinth[u][v]='#';
                        if(labyrinth[x1][y1]=='.' && visited[x1][y1]==0)
                        {
                                Q.push(make_pair(x1,y1));
                                visited[x1][y1]=1;
                                layer_update[x1][y1]=layer_update[u][v]+1;
                        }
                        if(labyrinth[x2][y2]=='.' && visited[x2][y2]==0)
                        {
                                Q.push(make_pair(x2,y2));
                                visited[x2][y2]=1;
                                layer_update[x2][y2]=layer_update[u][v]+1;
                        }
                        if(labyrinth[x3][y3]=='.' && visited[x3][y3]==0)
                        {
                                Q.push(make_pair(x3,y3));
                                visited[x3][y3]=1;
                                layer_update[x3][y3]=layer_update[u][v]+1;
                        }
                        if(labyrinth[x4][y4]=='.' && visited[x4][y4]==0)
                        {
                                Q.push(make_pair(x4,y4));
                                visited[x4][y4]=1;
                                layer_update[x4][y4]=layer_update[u][v]+1;
                        }
        }
for(i=1;i<=m;i++)
        {
                for(j=1;j<=n;j++)
                        {
                                if(layer_update[i][j]>longest_path)         
                                        {
                                                longest_path=layer_update[i][j];
                                                farthest=make_pair(i,j);
                                        }
                        }
        }   
return longest_path;
}
long long int compute_longest_path(long int m,long int n)
{
long int longest_path=0,i,j,temp_longest_path,temp;
vector<string> labyrinth;
string s,t;
for(i=0;i<=m+1;i++)
        {
        if(i==0 || i==m+1)
                {
                        s.append(n+2,'#');
                        labyrinth.push_back(s);
                        s.erase();
                }
        else
                {
                        s.append(1,'#');
                        cin>>t;
                        s.append(t);
                        s.append(1,'#');
                        labyrinth.push_back(s); 
                        s.erase(); 
                }
        }        
for(i=1;i<=m;i++)
        {
                for(j=1;j<=n;j++)
                        {
                                if(labyrinth[i][j]=='.')
                                        {
                                                temp=BFS(labyrinth,m,n,make_pair(i,j),false);
                                                temp_longest_path=BFS(labyrinth,m,n,farthest,true);
                                                if(temp_longest_path>longest_path)
                                                longest_path=temp_longest_path;       
                                        }
                        }
        }
return longest_path;
}
int main()
{
long int cases,m,n;
scanf("%ld",&cases);
while(cases--)
        {
        scanf("%ld%ld",&n,&m);
        printf("%ld\n",compute_longest_path(m,n)-1);
        }
return 0;
}
