// C++ program to print largest contiguous array sum 
#include<iostream> 
#include<climits> 
using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
	int max = INT_MIN, m = 0; 

	for (int i = 0; i < size; i++) 
	{ 
		m = m + a[i]; 
		if (max < m) 
			max = m; 

		if (m < 0) 
			m = 0; 
	} 
	return max; 
} 

/*Driver program to test maxSubArraySum*/
int main() 
{ 
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int max_sum = maxSubArraySum(a, n); 
	cout << "Maximum contiguous sum is " << max_sum; 
	return 0; 
} 
