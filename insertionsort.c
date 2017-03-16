#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int count_insertion;
void insertion_sort(int array[], int size);

int main()
{
	FILE *out,*out1,*out2;
	out = fopen ("insertion","w");
//	out1=fopen("elements_insertion","w");
	out2=fopen("insertion_time","w");
	unsigned long int counter,counter2,asize;
	
	clock_t time;
	
	for(counter=100; counter<10000; counter+=100)
	{
		time = clock();
		fprintf(out,"%lu\t",counter);
		fprintf(out2,"%lu\t",counter);
		int array[counter],array1[counter];
		for(counter2=0;counter2<counter;counter2++)
		{
		array[counter2] = rand() % counter;
		array1[counter2] = array[counter2];
		}
		insertion_sort(array1,counter);
		time = clock() - time;
		fprintf(out2,"%lf\n",(double)time/CLOCKS_PER_SEC);
		fprintf(out,"%d\n",count_insertion);
				
	}	
}
void insertion_sort(int array[], int size)
{
	int counter1, counter2, key,temp;
	for(counter2=1;counter2<size;counter2++)
	{
		key = array[counter2];
		counter1=counter2-1;
		while(counter1>=0 && array[counter1]>key)
		{
			temp = array[counter1+1];
			array[counter1+1] = array[counter1];
			array[counter1]=temp;
			counter1=counter1-1;
			count_insertion++;
		}	
		array[counter1+1] = key;
	} 
}	
