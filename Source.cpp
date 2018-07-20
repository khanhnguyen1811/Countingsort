//count sort algorthim. 
#include <iostream>
using namespace std; 
void printarr(int arr[], int n){
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n"; 
}

void countsort(int arr[], int sizeN){
	int maxEl, minEl; 
	int i, j, id = 0; 
	

	//find max min element. 
	maxEl = minEl = arr[0];
	for (i = 0; i < sizeN; i++)
	{
		if (arr[i] > maxEl)
		{
			maxEl = arr[i]; 
		}
		if (arr[i] < minEl)
		{
			minEl = arr[i];
		}
	}

	//cal range. 
	int range = maxEl - minEl + 1; 
	//cal output. 
	int *output = new int[range]; 

	//mang phan tu 0 voi sz = range. 
	for (i = 0; i < range; i++)
	{
		output[i] = 0; 
	}
	for (i = 0; i < sizeN; i++)
	{
		output[arr[i] - minEl] ++;

	}
	//xuat output. 
	for (i = minEl; i <= maxEl; i++)
	{
		for (j = 0; j < output[i-minEl]; j++)
		{
			arr[id++] = i;
		}
	}
	//print array. 
	//restore heap. 
	delete[] output; 
}
int main(){
	int arr[100], i, n; 
	cout << "Nhap size cua array: "; cin >> n; 
	for (i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}
	//call function. 
	countsort(arr, n); 
	cout << "mang array sx la: "; printarr(arr, n);
	return 0;
}