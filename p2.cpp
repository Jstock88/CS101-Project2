#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <climits>
#include <cstring>
using namespace std;



bool icheck(int a, int place, int b[]) {
	for (int i = 0; i < place; i++) {
		if (b[i] == a) {
			return true;
		}
	}
	return false;
}

bool scheck(string a, int place, string b[]) {
	for (int i = 0; i < place; i++) {
		if (b[i] == a) {
			return true;
		}
	}
	return false;
}



void Merge(int numbers[], int i, int j, int k) {
	int mergedSize;                            // Size of merged partition
	int mergePos;                              // Position to insert merged number
	int leftPos;                               // Position of elements in left partition
	int rightPos;                              // Position of elements in right partition
	int* mergedNumbers = nullptr;

	mergePos = 0;
	mergedSize = k - i + 1;
	leftPos = i;                               // Initialize left partition position
	rightPos = j + 1;                          // Initialize right partition position
	mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
	// for merged numbers

// Add smallest element from left or right partition to merged numbers
	while (leftPos <= j && rightPos <= k) {
		if (numbers[leftPos] < numbers[rightPos]) {
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
		}
		else {
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;

		}
		++mergePos;
	}

	// If left partition is not empty, add remaining elements to merged numbers
	while (leftPos <= j) {
		mergedNumbers[mergePos] = numbers[leftPos];
		++leftPos;
		++mergePos;
	}

	// If right partition is not empty, add remaining elements to merged numbers
	while (rightPos <= k) {
		mergedNumbers[mergePos] = numbers[rightPos];
		++rightPos;
		++mergePos;
	}

	// Copy merge number back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		numbers[i + mergePos] = mergedNumbers[mergePos];
	}
	delete[] mergedNumbers;
}

void MergeSort(int numbers[], int i, int k) {
	int j;

	if (i < k) {
		j = (i + k) / 2;  // Find the midpoint in the partition

		// Recursively sort left and right partitions
		MergeSort(numbers, i, j);
		MergeSort(numbers, j + 1, k);

		// Merge left and right partition in sorted order
		Merge(numbers, i, j, k);
	}
}


 
int Partition(string numbers[], int i, int k) {
	int l;
	int h;
	int midpoint;
	string pivot;
	string temp;
	bool done;

	/* Pick middle element as pivot */
	midpoint = i + (k - i) / 2;
	pivot = numbers[midpoint];

	done = false;
	l = i;
	h = k;

	while (!done) {

		/* Increment l while numbers[l] < pivot */
		while (numbers[l] < pivot) {
			++l;
		}

		/* Decrement h while pivot < numbers[h] */
		while (pivot < numbers[h]) {
			--h;
		}

		/* If there are zero or one elements remaining,
		 all numbers are partitioned. Return h */
		if (l >= h) {
			done = true;
		}
		else {
			/* Swap numbers[l] and numbers[h],
			 update l and h */
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers[h] = temp;

			++l;
			--h;
		}
	}

	return h;
}

void Quicksort(string numbers[], int i, int k) {
	int j;

	/* Base case: If there are 1 or zero elements to sort,
	 partition is already sorted */
	if (i >= k) {
		return;
	}

	/* Partition the data within the array. Value j returned
	 from partitioning is location of last element in low partition. */
	j = Partition(numbers, i, k);

	/* Recursively sort low partition (i to j) and
	 high partition (j + 1 to k) */
	Quicksort(numbers, i, j);
	Quicksort(numbers, j + 1, k);
}





int main(int argc, char* argv[]) {
	ifstream input1;
	ifstream input2;
	input1.open(argv[2]);
	input2.open(argv[3]);
	

	//Sees if the second arg is i
	if (strcmp(argv[1], "i") == 0) {
		int One[20000];
		int Two[20000];
		int Common[20000];
		int place1 = 0;
		int place2 = 0;
		int place3 = 0;

		string line;


		//reads all of the input one file and
		//stores it in One
		while (getline(input1, line)) {

			istringstream iss(line);
			int number;
			while (iss >> number) {
				One[place1] = number;
				place1++;

			}

		}



		//reads all of the input one file and
		//stores it in Two
		while (getline(input2, line)) {

			istringstream iss(line);
			int number;
			while (iss >> number) {
				Two[place2] = number;
				place2++;

			}

		}



		for (int i = 0; i < place1; i++) {
			for (int j = 0; j < place2; j++) {
				if (One[i] == Two[j]) {
					if (!icheck(One[i], place3, Common)) {
						Common[place3] = One[i];
						place3++;

					}

				}
			}
		}
		//cout << endl;
		MergeSort(Common, 0, place3 - 1);

		for (int i = 0; i < place3; i++) {
			cout << Common[i] << endl;
		}

	}

		
	//If the data is strings
	if (strcmp(argv[1], "s") == 0) {
		string One[20000];
		string Two[20000];
		string Common[20000];
		int place1 = 0;
		int place2 = 0;
		int place3 = 0;

		string line;


		//reads all of the input one file and
		//stores it in One
		while (getline(input1, line)) {

			istringstream iss(line);
			string Hold;
			while (iss >> Hold) {
				One[place1] = Hold;
				place1++;

			}
		}



		while (getline(input2, line)) {

			istringstream iss(line);
			string Hold;
				while (iss >> Hold) {
					Two[place2] = Hold;
					place2++;
				}
		}

		while (getline(input1, line)) {

			istringstream iss(line);
			string Hold;
			while (iss >> Hold) {
				One[place1] = Hold;
				place1++;

			}
		}

		for (int i = 0; i < place1; i++) {
			for (int j = 0; j < place2; j++) {
				if (One[i] == Two[j]) {
					if (!scheck(One[i], place3, Common)) {
						Common[place3] = One[i];
						place3++;

					}

				}
			}
		}

		Quicksort(Common, 0, place3 - 1);

		for (int i = 0; i < place3; i++) {
			cout << Common[i] << endl;
		}




	}
	return 0;
}