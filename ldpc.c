#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define J 3
#define K 5
#define N 15
#define SWAP 1000


void printldpc(int ldpc[][N]){
	int i,j;
	int line = (N-K)/J;
	line = line*J;
	for(i=0;i<line;i++){
		for(j=0;j<N;j++){
			printf("%d ",ldpc[i][j]);
		}
		putchar('\n');
	}
}

void randomswap(int ldpc[][N],int l,int le){
	int i,j;
	int randvalue1;
	int randvalue2;
	int tmp[le];
	for(i=0;i<SWAP;i++){
		randvalue1 = rand()%N;
		randvalue2 = rand()%N;
		for(j=0;j+l<l+le;j++){
			tmp[j] = ldpc[j+l][randvalue1];
			ldpc[j+l][randvalue1] = ldpc[j+l][randvalue2];
			ldpc[j+l][randvalue2] = tmp[j];
		}
	}
}

int main(){
	int i,j,k;
	int line = (N-K)/J;
	int ldpc[N-K][N] = {0};
	
	srand((unsigned)time(NULL));

	for(k=0;k<J;k++){
	for(i=0;i<line;i++){
		for(j=0;j<K;j++){
			ldpc[k*line+i][i*K+j]=1;
		}
	}
	}

	for(i=1;i<J;i++){
		randomswap(ldpc,i*line,line);
	}

	printldpc(ldpc);

	return 0;
}




	
	
