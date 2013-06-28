//coder:Krishna
//problem:ABCpath-SPOJ
//implementation:DFS
//date and time:28-6-2013 && 9:00 PM.

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<iterator>
using namespace std;

const int R[] = {0,1,1,1,0,-1,-1,-1};
const int C[] = {1,1,0,-1,-1,-1,0,1};
 
 
int row,column,maxlength;
bool visited[52][52];
vector<string> input;

bool isPass(int r,int c) {
  if(r >= 0 && r < row && c >=0 && c < column && !visited[r][c])
		return true;
	else	
		return false;
}
void DFS(int i,int j,int l) {
	int start;
	visited[i][j]=true;
	if(l > maxlength) maxlength = l;	
	for(start=0;start<8;start++)
		{
			if(isPass(i+R[start],j+C[start]) && input[i+R[start]][j+C[start]]-input[i][j]==1 )
				DFS(i+R[start],j+C[start],l+1);
		}
}

int main(){
int i,j,answer,k=1;string in; 
scanf("%d%d",&row,&column);
while(row !=0 && column!=0) {
answer = 0;
for(i=0;i<row;i++){
	cin>>in;
	input.push_back(in);
	}
for(i=0;i<row;i++){
	for(j=0;j<column;j++){
		if(input[i][j]=='A')
			{ 
				maxlength = 1;
				memset(visited,false,sizeof(visited));
				DFS(i,j,1);
				if(maxlength > answer) answer = maxlength;
			}
	}
}
cout<<"Case "<<k<<": "<<answer<<endl;k++;
input.clear();
scanf("%d%d",&row,&column);
}
return 0;
}
