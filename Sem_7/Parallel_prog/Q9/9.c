#include<mpi.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void get_input(int argc, char* argv[], int myRank, long* totalToss);
long toss(long numProcess, int myRank);

int main(int argc, char* argv[])
{
	int myRank, numProc;
	long totalNumToss, numProcess,processNumInCircle, totalNumInCircle;
	double start, finish, loc_elapsed,elapsed, piEst;
	double PI25 = M_PI;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &numProc);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	get_input(argc,argv,myRank,&totalNumToss);

	numProcess = totalNumToss/numProc;

	MPI_Barrier(MPI_COMM_WORLD);
	start = MPI_Wtime();
	processNumInCircle = toss(numProcess, myRank);
	finish = MPI_Wtime();
	loc_elapsed = finish - start;


	MPI_Reduce(&loc_elapsed, &elapsed, 1 ,MPI_DOUBLE, MPI_MAX,0,MPI_COMM_WORLD);
	MPI_Reduce(&processNumInCircle, &totalNumInCircle, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

	if(myRank == 0){
		piEst = (4*totalNumInCircle)/((double)totalNumToss);
		printf("elapsed time = %f seconds \n", elapsed);
		printf("PI is approx %.16f, error is %.16f\n",piEst,fabs(piEst - PI25));
	}
	MPI_Finalize();
	return 0;
}


void get_input(int argc, char* argv[],int myRank, long* totalNumToss){
	if(myRank == 0){
		if(argc != 2){
			printf("Error\n");
			*totalNumToss = 0;
		}
		else{
			*totalNumToss = atoi(argv[1]);
		}

	}

	MPI_Bcast(totalNumToss, 1, MPI_LONG, 0,MPI_COMM_WORLD);

	if(*totalNumToss == 0){
		MPI_Finalize();
		exit(-1);
	}
}


long toss(long numProc,int myRank){
	long toss, numInCircle = 0;
	double x,y;

	unsigned int seed = (unsigned)time(NULL);
	srand(seed+myRank);

	for(toss = 0;toss < numProc;toss++){
		x = rand_r(&seed) / (double)RAND_MAX;
		y = rand_r(&seed) / (double)RAND_MAX;
		if((x*x+y*y) <= 1.0)
			numInCircle++;
	}
	return numInCircle;
}