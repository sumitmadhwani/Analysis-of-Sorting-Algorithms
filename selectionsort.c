#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int count_selection;
void selection_sort(int array[], int size);

int main()
{
	FILE *out,*out1,*out2;
	out2=fopen("selection_time","w");
	out = fopen ("selection","w");
//	out1 = fopen("elements_selec","w");
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
		selection_sort(array1,counter);
		time=clock()-time;
		fprintf(out,"%d\n",count_selection);
		fprintf(out2,"%lf\n",(double)time/CLOCKS_PER_SEC);
	}
	
        
        }
void selection_sort(int array[], int size)
{
	int counter1, counter2, temp;
	for(counter1=0; counter1<size; counter1++)
	{
		for(counter2=counter1+1; counter2<size; counter2++)
		{
			if(array[counter2]<array[counter1])
			{	
				count_selection++;
				temp=array[counter2];
				array[counter2]=array[counter1];
				array[counter1]=temp;
			}
			else count_selection++;
		}
	}
}
