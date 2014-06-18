#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define J 3
#define K 5
#define N 15
#define SWAP 1000


void printheader(){
	int i;
	printf("digraph sample{\n\tlayout=neato;\n");
	for(i=0;i<N;i++){
		printf("\t%d%d%d [shape = box, label = \"%d\"];\n",i+1,i+1,i+1,i+1);
	}
}

void printglaph(int ldpc[][N]){
	int i,j;
	int line = (N-K)/J;
	line = line*J;
	for(i=0;i<line;i++){
		for(j=0;j<N;j++){
			if(ldpc[i][j]){
				printf("\t%d -> %d%d%d;\n",i+1,j+1,j+1,j+1);
			}
		}
	}
}

void printfooter(){
	int i;
	for(i=0;i<((N-K)/J)*J;i++){
		printf("\t%d [pos=\"%d,0!\"]\n",i+1,i);
	}
	for(i=0;i<N;i++){
		printf("\t%d%d%d [pos=\"%d,-3!\"]\n",i+1,i+1,i+1,i);
	}
	printf("}\n");
}

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
	
//	srand((unsigned)time(NULL));

	for(i=0;i<N-K;i++){
		for(j=0;j<N;j++){
			scanf("%d",&ldpc[i][j]);
		}
	}

//	for(i=1;i<J;i++){
//		randomswap(ldpc,i*line,line);
//	}

//	printldpc(ldpc);
	printheader();
	printglaph(ldpc);
	printfooter();


	return 0;
}




	
	
