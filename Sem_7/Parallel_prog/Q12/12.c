#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


long F(long a){
	return a*a;
}

void search(long limit, long num, int id){
	for(long i =(long)(limit*id)/4;i<=(limit*(id+1))/4;i++){
		if(F(i) == num){
			printf("Process %d found !",id);
			break;
		}
	}
}


int main(int argc,char* argv[]){
	int rank,numproc;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &numproc);
	search(100,49,rank);
	MPI_Finalize();
	return 0;

}