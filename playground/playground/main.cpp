//#include<stdio.h>
//#include<conio.h>
#include<iostream>
using namespace std;

void reverseArray(int arr1[],int size);
void removeOdd(int arr2[],int size);
void splitParity(int arr3[],int size);


void printArray(int arr[],int arrSize);

int main()
{
//    clrscr();
    int arr1[10] = {9,2,14,12,-3};
    int arr1Size = 5;
    
    int arr2[10] = {21,12,6,7,14};
    int arr2Size = 5;
    
    int arr3[10] = {3,6,4,1,12};
    int arr3Size = 5;
    
    reverseArray(arr1,arr1Size);
    printArray(arr1,arr1Size);
    
    removeOdd(arr2,arr2Size);
    printArray(arr2,arr2Size);
    
    splitParity(arr3,arr3Size);
    printArray(arr3,arr3Size);
//    getch();
    return 0;
}

void reverseArray(int arr1[],int arr1Size)
{
    int x,i,j=arr1Size;
    for(i=0;i<=(arr1Size/2);i++)
    {
        x = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = x;
        j--;
    }
    
}

void removeOdd(int arr2[],int arr2Size)
{
    int i,j,z=1;
    for(i=0;i<=arr2Size;i++)
    {
        if(arr2[i]%2!=0)
        {
            arr2[i]=arr2[i+z];
            z++;
            arr2Size -=z;
        }
    }
}

void splitParity(int arr3[],int arr3Size)
{
    int i,j=0,x,y;
    
    for(i=0;i<=arr3Size;i++)
    {
        if(arr3[i] % 2!=0)
        {
            x = arr3[i] ;
            arr3[i] = arr3[j];
            arr3[j] = x;
            j++;
        }
        
    }
    
}

void printArray(int arr[],int arrSize)
{
    int i;
    for(i=0;i<=arrSize;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

