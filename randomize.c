#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap numbers
void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//print array
void display (int arr[], int n)
{
	int i =0;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void randomize ( int arr[], int n )
{
	//Setting seed to get different random number at different interval of time
	srand ( time(NULL) );

	int i;
	for (i = n-1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = rand() % (i+1);

		// Swap arr[i] with the element at random index
		swap(&arr[i], &arr[j]);
	}
}


int main()
{
    int n;
    printf("Enter array size:");
    scanf("%d",&n);
    int *arr = (int*) malloc(n * sizeof(int));
    int i;
    for(i=0;i<n;i++){
        printf("Enter arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    
    printf("Entered Array:");
	display(arr,n);
	
	randomize (arr, n);
	
	printf("Randomized Array:");
	display(arr, n);

	return 0;
}
