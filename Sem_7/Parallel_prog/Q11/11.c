#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

#define BUFFER_SIZE sizeof(int)*4


int main(int argc, char* argv[]){
	int a[2][2] = {{1,2},{3,4}};
	int b[2][2] = {{1,0},{0,1}};
	int c[2][2] = {{0,0},{0,0}};

	int rank,size;

	MPI_Init(&argc,&argv);

	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	MPI_Status status;

	if(rank == 1){
		for(int i = 0;i<2;i++){
			for(int j = 0;j<2;j++){
				c[i][j] = 0;
				for(int k =0;k<2;k++){
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		MPI_Send(&c,BUFFER_SIZE,MPI_INT,0,0,MPI_COMM_WORLD);
	}
	else if(rank == 0){
		MPI_Recv(&c, BUFFER_SIZE,MPI_INT,1,0,MPI_COMM_WORLD,&status);
		for(int i = 0;i<2;i++){
			for(int j = 0;j < 2;j++){
				printf("%d\t", c[i][j]);
			}
			printf("\n");
		}
	}

	MPI_Finalize();
	return 0;
}