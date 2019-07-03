#include <stdio.h>
#define rep(i,n) for(i=0;i<(n);i++)
#define MAXL 95
#define MAXK 95
#define INF 1023456789
/*
** RAKESH KUMAR **
*/
int K,L, F[MAXL];
char keys[MAXK], letters[MAXL];

int dp[MAXK][MAXL];
int pi[MAXK][MAXL];

void solve() {
 int i,j,k,cur;
 rep(i,K) rep(j,L) dp[i][j] = INF;
 rep(i, K) {
  if(i == 0) { //initialize for first key
   rep(j, L) {
    if(j == 0) { 
     dp[i][j] = F[j]; 
     pi[i][j] = 0; 
    }
    else { 
     dp[i][j] = dp[i][j-1] + F[j] * (j+1); 
     pi[i][j] = 0;
    }
   }
   continue;
  }

  rep(j,L) if(dp[i-1][j] < INF) {
   cur = 0;
   for(k=j+1;k<L;k++) {
    cur += F[k] * (k-j);
    if(dp[i-1][j] + cur < dp[i][k]) {
     dp[i][k] = dp[i-1][j] + cur;
     pi[i][k] = j+1;
    }
   }
  }
 }
}

void print(int k, int l) {
 if(k < 0) return;
 print(k-1, pi[k][l]-1);
 printf("%c: ",keys[k]);
 int i;
 for(i=pi[k][l];i<=l;i++) printf("%c",letters[i]);
 printf("\n");
}

int main() {
 int T,kase=1;
 int i;
 scanf(" %d",&T);
 while(T--) {
  printf("Keypad #%d:\n",kase++);
  scanf(" %d %d",&K,&L);
  scanf(" %s",keys);
  scanf(" %s",letters);
  rep(i,L) scanf(" %d",&F[i]);

  solve();
  print(K-1,L-1);
  printf("\n");
 }
 return 0;
}
