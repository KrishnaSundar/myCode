//coder : Krishna
//language : C++
//category : primes,simple BFS
//logic : find primes upto 10,000 using sieve then for each all possible digitwise transition is recorded 
//and then as unit distance simple BFS is used for recording this then once reached the destination return 
//value else atlast return a negative score if it can be reached. 
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
#include<string>
using namespace std;
#define MAXX 10000
int flag[MAXX];
bool visited[MAXX];
int d[MAXX];
int digits[6];
void sieve() {
    int i,j,k;flag[0]=1;flag[1]=1;
	for(i=4;i<MAXX;i+=2) flag[i]=1;
	for(i=3;i<100;i+=2) {
		if(!flag[i]) {
			for(j=i*i,k=i<<1;j<MAXX;j+=k) {
				flag[j]=1;
			}
		}
	}
}
int BFS(int source , int destination) {
	queue<int> Q;
    	int start,jump,t,parent,num,pos,k,r;
	Q.push(source);
	memset(d,-1,sizeof(d));
    	memset(visited,false,sizeof(visited));
	visited[source]=true;
	d[source]=0;
	while(!Q.empty()) {
		parent = Q.front();
		t=parent;
        	Q.pop();
		pos=3;
		while(pos>=0) {
			digits[pos]=t%10;
			t=t/10;	
			--pos;
		}		
		for(k=0;k<=3;k++) {
			if(k==0 || k==3) start=1;
			else start=0;
			if(k==3) jump=2;
			else jump=1;
			r = digits[k];
				for(;start <= 9;start = start + jump) {
					digits[k]=start;
					pos=0;num=0;
					while(pos<4) {
						num = (num*10)+digits[pos];
						++pos;
					}
					if(num != parent && !visited[num] && !flag[num]) {
						Q.push(num);
						d[num]=d[parent]+1;
						visited[num]=true;
						if(destination == num) return d[num];
					}				
				}
			digits[k] = r;	
		}		
	}
	return d[destination];	
}
int main() {
	int cases,A,B,D;
	scanf("%d",&cases);
	sieve();
	while(cases--) {
		scanf("%d%d",&A,&B);
		if(A==B) {
			printf("0\n");continue;
        }
		D = BFS(A,B);
		if(D == -1) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n",D);
		}
	}	
return 0;
}
