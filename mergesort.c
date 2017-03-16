#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int count_merge;

void merge_sort(int array[], int start_index, int end_index);
void merge(int array[], int start_index, int mid_index, int end_index);

int main()
{
	clock_t time;
	FILE *out,*out1,*out2;
	out = fopen ("merge","w");
//	out1=fopen("elements_merge","w");
	out2=fopen("merge_time","w");
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
		
		merge_sort(array1,0,counter-1);
		time = clock() - time;
		fprintf(out2,"%lf\n",(double)time/CLOCKS_PER_SEC);
		fprintf(out,"%d\n",count_merge);
				
	}	
}
void merge_sort(int array[], int start_index, int end_index)
{
	int mid_index;
	if(start_index < end_index)
	{
		mid_index = (start_index+end_index)/2;	
		merge_sort(array, start_index, mid_index);
		merge_sort(array, mid_index+1, end_index);
		merge(array, start_index, mid_index, end_index);
	}

}
void merge(int array[], int start_index, int mid_index, int end_index)
{
	int n1, n2, counter1, counter2, counter3;
	n1 = mid_index - start_index + 1;
	n2 = end_index - mid_index;
	int L[start_index+end_index], R[start_index+end_index];
	for(counter1=0; counter1<n1; counter1++)
	{
		L[counter1] = array[start_index + counter1 ];
	}
	for(counter2=0; counter2<n2; counter2++)
	{
                R[counter2] = array[mid_index + counter2+1];
 	}
	L[n1+1] = 100000;
	R[n2+1] = 100000;
	counter1 = 0;
	counter2 = 0;
	counter3 = start_index;
        while(counter1<n1 && counter2<n2){
		count_merge++;
        	if(L[counter1] <= R[counter2])
                {
                        array[counter3++] = L[counter1];
                        counter1=counter1+1;
                }
                else
                {
                        array[counter3++] = R[counter2];
                        counter2 = counter2+1;
                }
		}
        while(counter1<n1){
        	  array[counter3++] = L[counter1++];
		}
		while(counter2<n2){
        	  array[counter3++] = R[counter2++];
		}
}

