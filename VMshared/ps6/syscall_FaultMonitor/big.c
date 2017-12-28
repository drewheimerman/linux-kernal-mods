#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include <stdlib.h>

//Code with help from StackExchange//
//User: VAndrei
//April 25, 2015
//https://stackoverflow.com/questions/29850001/how-to-write-a-simple-page-fault-generator

int main(void)
{
	double* array = (double*)malloc(sizeof(double) * 536870912); //4GB
	double dummy_sum = 0.0;
	while (1)
	{
	   int i = rand() % 536870912; //pick random index to access in the malloc'd array
	   dummy_sum += array[i];
	}
}