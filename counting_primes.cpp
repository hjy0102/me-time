#include <iostream>
#include <array>

using namespace std;

/*
MapReduce and Parallelism 
Question: Count the number of prime numbers in an array of postive integers
*/
//some CUTOFF value for sequential reduction


int CUTOFF = 10;

// returns True if n is prime
bool IsPrime(int number)
{	// Given:   num an integer > 1
	// Returns: true if num is prime
	// 			false otherwise.
	for (int i = 2; i<number; i++){
		if (number % i == 0){
			return false;
		}
	}
	return true;	
}

int linearCPH(int A[], int lo, int hi) {
	int total;
	for (int i = lo; i < (hi + 1); i++) {
		total = total + A[i];
	}
	return total;
}

int cpHelper(int A[], int lo, int hi) {
	if ((hi - lo) <= CUTOFF)
		return linearCPH(A, lo, hi);

	int sub1, sub2;

	#pragma omp task untied shared(sub1)
	{sub1 = cpHelper(A, lo, (lo+hi)/2);}
	sub2 = cpHelper(A, (lo+hi)/2, hi);
	#pragma omp taskwait

	return sub1+sub2;
}

int countPrimes(int count[], int A[], int n) {
	int total;
	int i;
	forall (i=0; i<=n; i++) {
		count[i] = (isPrime(A[i]))? 1 : 0;
	}
	#pragma omp parallel
	#pragma omp single
	{total = cpHelper(count, 0, n);}
	return total;
}

void printArray(int A[], int n){
	cout << "Array size of : " << n <<endl;
	cout << "The contents of the array are: " << endl;
	for (int i =0; i < n; i++ ) {
		cout << A[i] << "    "; 
	}
}

int main() {

	int A[] = {1,2,13,22,90,44,56,29,5};
	int n = sizeof(A)/sizeof(int);
	int count[n];

	cout << "Number of prime numbers in the array is: " << countPrimes(count, A, n) << endl;

}


