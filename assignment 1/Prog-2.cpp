#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int partitionn (int *A,int l,int r,int pivot_position);
void quicksort(int *A,int l,int r);
int select_random_middle(int *A,int l,int r);
void swapp(int *A,int i,int j);



int main (){

    int sizee=0;
    int A[10000]={0};
    char ch[20];
    char X[]="x";
    int i=0;
    scanf("%19s",&ch);
    while(strcmp(ch,X) != 0)
    {

        A[i]=atoi(ch);
        //cout<< A[i] << endl;
        i++;
        scanf("%19s",&ch);
    }

    sizee=i;

    quicksort(A, 0, sizee - 1);
    for(int c=0;c<sizee;c++)
        printf("%d ",A[c]);
    printf("\n");



}
int partitionn(int *A,int l,int r,int pivot_position){   //return pivot's position

	int i=l+1;
	swapp(A,pivot_position,l);
	for(int j=l+1;j<=r;j++){
		if(A[j]<A[l])
			{
            swapp(A,j,i);
			   //swap with the bigger and leftest entry
              i=i+1;
			}
	}
    swapp(A,l,i-1); //swap with the smaller and rightest entry
      return i-1;
}
//  quicksort recursively sort
  void swapp(int *A,int i,int j)
  {
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
  }


   void quicksort(int *A,int l,int r){
    	  if(l<r){
          int old_pivot_position=select_random_middle(A,l,r);

    	  int new_pivot_position = partitionn(A,l,r,old_pivot_position);
          quicksort(A,l,new_pivot_position-1);
    	  quicksort(A,new_pivot_position+1,r);
    	  }


}



int select_random_middle(int *A,int l,int r){
    int middle_position=(l+r)/2;
    int temp=0;
    temp=A[middle_position];
    if((A[l]<temp&&A[l]>A[r])||(A[l]<A[r]&&A[l]>temp)) //A[0] is median
       middle_position=l;

	else if((A[r]<temp&&A[r]>A[l])||(A[r]<A[l]&&A[r]>temp)) //A[size-1] is the median
	   middle_position=r;
    return middle_position ;


}

