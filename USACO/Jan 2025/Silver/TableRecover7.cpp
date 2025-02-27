#include <cstdio>
#include <vector>

int table[1000][1000];

int ans[2][1000][1000];

int freq[2001];

int rs[1000];
int cs[1000];
int N;

int pick_lexmin(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(ans[0][i][j]<ans[1][i][j]){
	return 0;
      }
      if(ans[0][i][j]>ans[1][i][j]){
	return 1;
      }
    }
  }
  return 0;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&table[i][j]);
      freq[table[i][j]]++;
    }
  }
  for(int u=2;u<=N*2;u++){
    if(freq[u]==1){
      for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
	  if(table[i][j]==u){
	    for(int k=0;k<N;k++){
	      rs[k]=freq[table[k][j]];
	      cs[k]=freq[table[i][k]];
	    }
	    break;
	  }
	}
      }
      break;
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      ans[0][i][j]=rs[i]+cs[j];
      ans[1][i][j]=2*(N+1)-rs[i]-cs[j];
    }
  }
  int k=pick_lexmin();
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(j) printf(" ");
      printf("%d",ans[k][i][j]);
    }
    printf("\n");
  }
}