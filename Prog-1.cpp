#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int Quick_Sort(int left,int right);
int data[10000];
int main (){

    int sizee=0;
    //int data[10000]={0};
    char ch[20];
    char X[]="x";
    int i=0;
    scanf("%19s",&ch);
    while(strcmp(ch,X) != 0)
    {

        data[i]=atoi(ch);
        //cout<< A[i] << endl;
        i++;
        scanf("%19s",&ch);
    }

    sizee=i;

    Quick_Sort(0, sizee - 1);
    for(int c=0;c<sizee;c++)
        printf("%d ",data[c]);
    printf("\n");



}
int Quick_Sort(int left,int right){
    if(left < right){
        int i = left + 1, j = right, splitting = data[left], temp;
        do{
            while(i < right && data[i] <= splitting) i++;   // Note the "<" and "<="
            while(j > left && data[j] > splitting) j--;
            if(i < j){
            temp = data[i]; data[i] = data[j]; data[j] = temp;   // Note this line, swap data[i + 1] and data[i]
            }
        }while(i < j);
        temp = data[j]; data[j] = data[left]; data[left] = temp;   // Note this line, swap data[j] and the data[left] (splitting)
        Quick_Sort(left, j - 1);
        Quick_Sort(j + 1, right);
    }
}
