#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int count_quick;
void quick_sort(int array[], int start_index, int end_index);
int partition(int array[], int start_index, int end_index);
int main()
{
	FILE *out,*out1,*out2;
	out = fopen ("quick","w");
//	out1=fopen("elements_quick","w");
	out2=fopen("quick_time","w");
	clock_t time;
	unsigned long int counter,counter2;
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
		quick_sort(array1,0,counter-1);
		time = clock() - time;
		fprintf(out2,"%lf\n",(double)time/CLOCKS_PER_SEC);
		fprintf(out,"%d\n",count_quick);
				
	}	

}

int partition(int array[], int start_index, int end_index)
{
	int temp1, temp2, counter1, counter2;
	temp1 = array[end_index];
	counter1 = start_index - 1;
	for(counter2 = start_index; counter2<end_index; counter2++)
	{
		if(array[counter2] <= temp1)
		{
			count_quick++;
			counter1 = counter1 + 1;
			temp2 = array[counter1];
			array[counter1] = array[counter2];
			array[counter2] = temp2;
		}
	}
	temp2 = array[counter1+1];
	array[counter1+1] = array[end_index];
	array[end_index] = temp2;
	return(counter1+1);
}
void quick_sort(int array[], int start_index, int end_index)
{
	int mid_index;
	if(start_index < end_index)
	{
		mid_index = partition(array, start_index, end_index);
		quick_sort(array, start_index, mid_index-1);
		quick_sort(array, mid_index+1, end_index);
	}

}	
