#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int InitialData1[80] = {37,50,54,50,56,0,43,43,74,71,32,36,16,43,56,100,50,25,15,17,37,50,54,50,56,0,43,43,74,71,32,36,16,43,56,100,50,25,15,17,37,50,54,50,56,0,43,43,74,71,32,36,16,43,56,100,50,25,15,17,37,50,54,50,56,0,43,43,74,71,32,36,16,43,56,100,50,25,15,17};
int InitialData2[80] = {35,51,54,58,55,32,36,69,27,39,35,40,16,44,55,14,58,75,18,15,35,51,54,58,55,32,36,69,27,39,35,40,16,44,55,14,58,75,18,15,35,51,54,58,55,32,36,69,27,39,35,40,16,44,55,14,58,75,18,15,35,51,54,58,55,32,36,69,27,39,35,40,16,44,55,14,58,75,18,15};

#define SIZE 600000

int main(int argc, char **argv)
{

	time_t start, stop;
   	clock_t ticks;
   	
   	time(&start);
   	//int i = 0;
   	
	// Two integer source vectors in Host memory
	int HostVector1[SIZE], HostVector2[SIZE];
	//Output Vector
	int HostOutputVector[SIZE];
	// Initialize with some interesting repeating data
	//int n;
	for(int c = 0; c < SIZE; c++)
	{
		HostVector1[c] = InitialData1[c%20];
		HostVector2[c] = InitialData2[c%20];
		HostOutputVector[c] = 0;
	}
     
	for(int i = 0; i < SIZE; i++)
	{
        HostOutputVector[i] = HostVector1[i] + HostVector2[i];
        ticks = clock();
	}
     
	/*for( int i = 0 ; i < SIZE; i++)
	{
		printf("[%d + %d = %d]\n",HostVector1[i], HostVector2[i], HostOutputVector[i]);
	}*/
	
	
	/*while(i<50000)
	{
		printf("Work work %d\n", i);
		i++;
		ticks = clock();
	}*/

	time(&stop);
	
	printf("\nExecution time in miliseconds = %0.3f ms", ((double)ticks/CLOCKS_PER_SEC)*1000);
	//printf("Finished in about %.3f miliseconds. \n", (difftime(stop, start))*1000);
	printf("\nExecution time in seconds = %0.3f s\n\n", (double)ticks/CLOCKS_PER_SEC);
	//printf("Finished in about %.3f seconds. \n", difftime(stop, start));

	return 0;
}


