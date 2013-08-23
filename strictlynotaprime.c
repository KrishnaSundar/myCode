//coder:Krishna
//language:C++
//logic:Simple may sound the question but there lies a trick there in interpreting it well as this 
//small carelessness caused me 50 attempts consisting of TLE and WA and then thanks to misof and 
//some yellow coder who guided me very well.You can view my post at TC forums for further details
//for strictly not a prime.
//key:"Understand the difference between stricly not a prime and not stricly a prime".
//category:Subsequence generation,prime,Dynamic programming.
#include<stdio.h>
#include<stdlib.h>
#define MAXX 100020
#define LIMIT 317
int flag[MAXX];
int sum[MAXX];
int digits[6];
int see(int i) {
int n=0,j,k=0,res;
while(i) {
    digits[k++]=i%10;i/=10;
    n++;
}
for(j=1;j<(1<<n);j++) {
         res=0;
         for(k=0;k<n;k++) {
            if(j&(1<<k)) {
				res=(res*10)+(digits[n-k-1]);
				}
			}
		      if(!flag[res]) return 1;					
		      }
return 0;		      
}
void check_for_primeinteger() {
		int i,j,k;
		    sum[0]=1;
    		sum[1]=2;
    		sum[2]=2;
    		for(i=3;i<100001;i++) {
    			j=see(i);
    			if(!j) {
    				sum[i]=sum[i-1]+1;
    			}
    			else {
    				sum[i]=sum[i-1];flag[i]=0;
    			}	
    		}
}
void sieve () {
	int i,j,k;flag[0]=flag[1]=1;flag[2]=0;
	for(i=2*2;i<MAXX;i=i+2) {flag[i]=1;}
	for(i=3;i<LIMIT;i=i+2) {
		if(!flag[i])
			for(j=i*i,k=i*2;j<MAXX;j=j+k) {
				flag[j]=1;;
			}
	}
	check_for_primeinteger();
}
int strict_prime(int A,int B) {
if(A > B ) {
    A=A^B;B=A^B;A=A^B; 
}
return sum[B]-sum[A-1];
}
int main() {
sieve();
int cases,A,B;
scanf("%d",&cases);
while(cases--) {
	scanf("%d%d",&A,&B);
	printf("%d\n",strict_prime(A,B));
}
return 0;
}
