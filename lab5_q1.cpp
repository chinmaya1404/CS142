#include<iostream>
using namespace std;
//define partition function
int part(int arr[],int pivot,int low, int high){
	int i,j;
	int a= arr[pivot];
	i= low;
	j= high;
	while(i != j){
      
        	if(arr[i]>a){
			//swap values
        		int b = arr[i];
        		arr[i] = arr[j-1];
        		arr[j-1] = b;
        		j--;

        	}
        	else
        	    i++;
        }
		if(i!=high){
		//swap pivot with high
		int c = arr[i];
        		arr[i] = arr[high];
        		arr[high] = c;
		}
    pivot=i;
    return pivot;
   
}
//define quicksort

void quicksort(int arr[],int low,int high)
{
	int p;
	int pivot = high;     
	if(low<high)
	{
		//call partition
		p = part(arr,pivot,low,high);
		quicksort(arr,low,p-1);
		quicksort(arr,p+1,high);
	}
}
//define display
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"-";

	}
	cout<<endl;
}


int main(){
//declare array
int arr[7]={2,7,4,6,3,8,5};
//call quicksort
quicksort(arr,0,6);
//display
display(arr,7);
return 0;
}	

