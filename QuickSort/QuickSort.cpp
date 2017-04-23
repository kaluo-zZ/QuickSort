// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

void exchange(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int* A, int p, int r){
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++){
		if (A[j] <= x){
			i++;
			exchange(A[i],A[j]);
		}
	}
	exchange(A[i+1],A[r]);
	return i + 1;
}

void QuickSort(int* A, int p, int r){
	if (p < r){
		int q = Partition(A, p, r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
}

void printArray(int* A,int length){
	for (int i = 1; i <= length; i++){
		printf("%d\t",A[i]);
	}
	printf("\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
    int len=0;
	printf("please input the number of array:");
	scanf_s("%d",&len);
	int* A = (int*)malloc((len+1)*sizeof(int));
	for (int i = 1; i <= len; i++){
		A[i] = rand();
	}
	printArray(A,len);
	QuickSort(A,1,len);
	printArray(A,len);
	free(A);
	return 0;
}

