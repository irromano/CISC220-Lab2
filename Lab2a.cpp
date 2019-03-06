/*
 * Ian Romano, Kyle Sapia
 * TA: Daniel Gaston
 * 2/22/19
 *
 * Lab2a.cpp
 * This file contains the problem functions for lab 2. Most of the functions are not releated to each other.
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void printHeader(int &problemCounter);
void printLine();
void printValandAddress();
void add4andPrintValandAddress(int num);
int randZerotoFifty();
void cubeByPointer(int *num);
void addRand(int &num);
void change32_42(int *numA, int *numB);
void changeChars(char char1, char &char2, char *char3);
bool swapIfGreaterthan(int &numa, int &numb);
void randSwap();
void arrayMaker(int len, int &small);
void arrayMakerReverse(int len);
void arrayMakerOrder(int len, int max);
int* returnIntAddress();
void printArray(int arr[], int len);
int *randArrayPoint(int *len, int *high, int *low);

int main() {
	int problem = 0;
	//Header for problem 1
	printHeader(problem);
	printValandAddress();
	printLine();

	//Header for problem 2
	printHeader(problem);
	int num = 6;
	add4andPrintValandAddress(num);	//we're plugging num into a function. This is a 'Call by Value'
	cout << num << endl;//value of num is NOT changed by add4andPrintValandAddress().
	cout << &num << endl;//And know we're showing that the num in main and the function have different values and address locations
	printLine();

	//Header for problem 3
	printHeader(problem);
	int newRand = randZerotoFifty();//We're declaring a new variable and assigning it a random number. The function itself will print the value and address of the functions scope return value.
	cout << newRand << endl;
	cout << &newRand << endl;//This will print newRand's value and address, showing that the address is different than the value generated within the scope of the previous function
	printLine();

	//Header for problem 4
	printHeader(problem);
	int num4 = 4;
	cout << num4 << endl;
	cout << &num4 << endl;
	cubeByPointer(&num4);			//Call by pointer
	cout << num4 << endl;//value of num4 is changed by cubByPointer() because of call by pointer.
	cout << &num4 << endl;//address of value is same as what was printed by function
	printLine();

	//Header for problem 5
	printHeader(problem);
	int num5 = 5;
	cout << num5 << endl;			//Print value of num5
	cout << &num5 << endl;			//Print address of num5
	addRand(num5);					//Call by reference with num5
	cout << num5 << endl;			//Print new value of num5
	cout << &num5 << endl;			//Print address of num5
	printLine();

	//Header for problem 6
	printHeader(problem);
	int num6a = 10;
	int num6b = 20;
	change32_42(&num6a, &num6b);
	cout << num6a << endl;			//New value of num6a is 32
	cout << num6b << endl;			//New value of num6b is 42
	printLine();

	//Header for problem 7
	printHeader(problem);
	char charD = 'D';
	char charO = 'O';
	char charG = 'G';
	cout << charD << charO << charG << endl;	//Print 'DOG'
	changeChars(charD, charO, &charG);
	cout << charD << charO << charG << endl;	//Print 'DIG'
	printLine();

	//Header for problem 8
	printHeader(problem);
	cout << "part a" << endl;
	int num8a, num8b;
	num8a = 7;
	num8b = 5;
	cout << endl;
	cout << "Testcase 1" << endl;
	cout << swapIfGreaterthan(num8a, num8b) << endl;//Prints out 1 because the swap occurred (num8a > num8b)
	cout << num8a << endl;								//Prints out 5
	cout << num8b << endl;								//Prints out 7
	cout << endl;
	cout << "Testcase 2" << endl;
	cout << swapIfGreaterthan(num8a, num8b) << endl;//Prints out 0 because the swap did not occur (num8a < num8b)
	cout << num8a << endl;								//Prints out 5
	cout << num8b << endl;								//Print out 7
	cout << endl;
	cout << "Testcase 3" << endl;
	num8a = num8b;						//Now setting them equal to each other
	cout << swapIfGreaterthan(num8a, num8b) << endl;//Prints out 0 becaused the swap did not occur (num8a == num8b)
	cout << num8a << endl;								//Prints out 7
	cout << num8b << endl;								//Prints out 7
	cout << endl;

	cout << "part b" << endl;
	randSwap();		//This function prints 20 iterations of swapIfGreaterthan()
	cout << endl;

	cout << "part c" << endl;		//Called 'Problem 8' in the lab document.
	int small;
	cout << "Testcase 1" << endl;
	arrayMaker(5, small);//Prints an int array of length 5 filled with random numbers from 0-50.
	cout << small << endl;	//Prints the smallest value from the length 5 array
	cout << endl;
	cout << "Testcase 2" << endl;
	arrayMaker(9, small);//Prints an int array of length 9 filled with random numbers from 0-50.
	cout << small << endl;	//Prints the smallest value from the length 5 array
	cout << endl;
	cout << "Testcase 3 (No Array Expected)" << endl;
	arrayMaker(-5, small);			//Prints nothing, invalid input
	cout << small << endl;			//Prints -1 since no array was generated
	printLine();

	//Header for Problem 9
	printHeader(problem);
	cout << "Testcase 1" << endl;
	arrayMakerReverse(5);			//Prints out a 5-element int array of random numbers from 0-50. Then Prints out the same array in reverse.
	cout << endl;

	cout << "Testcase 2" << endl;
	arrayMakerReverse(10);			//Prints out a 10-element int array of random numbers from 0-50. Then Prints out the same array in reverse.
	cout << endl;

	cout << "Testcase 3 (Nothing Expected)" << endl;
	arrayMakerReverse(-1);			//Prints out nothing because a number less-than 1 was used.
	printLine();

	//Header for Problem 10
	printHeader(problem);
	cout << endl;
	cout << "Testcase 1" << endl;	//Prints out an int array of length 10. The values are in accending order and range from 0-4
	arrayMakerOrder(10, 5);
	cout << endl;

	cout << "Testcase 2" << endl;
	arrayMakerOrder(100, 50);	//Prints out an int array of length 100. The values are in accending order and range from 0-49.

	cout << "Testcase 3 (Nothing Expected)" << endl;
	arrayMakerOrder(2, -1);			//Prints out nothing because a negative max value was used.
	cout << endl;
	printLine();

	//Header for Problem 11
	printHeader(problem);
	cout << endl;

	cout << "Testcase 1" << endl;
	int *threePointer = returnIntAddress();
	//cout << *threePointer << endl;			//Printing out the pointing value and the value of 'threePointer' terminates the program. The value of threePointer zeros when the original function finishes.
	//cout << threePointer << endl;
	cout << endl;
	printLine();

	//Header for Problem 12
	printHeader(problem);
	cout << endl;

	srand(time(NULL));				//Setting seed for RNG
	int arr12[10];
	for (int i=0; i<10; i++){			//build int array of rand ints
		arr12[i]= rand() % 10 + 1;		//random int 1-10
	}

	cout << "Test Case 1" << endl;
	cout << "An int array of 10 random integers should print out:" << endl;
	printArray(arr12, 10);
	cout << endl;
	printLine();

	//Header for Problem 13
	printHeader(problem);
	cout << endl;
	int length;
	int max = 0;
	int min = 0;
	int* arr13b = randArrayPoint(&length, &max, &min);
	//int arr13b[length];
	printArray(arr13b, length);
//	for (int i=0; i<length; i++) {
//		delete arr13b[i];
//	}
//	delete [] arr13b;


	return 0;



}

/*Problem 1
 * This function creates an int variable and prints out it's value and address.
 * Parameters-
 * 		None
 * Returns-
 * 		Nothing
 */
void printValandAddress() {
	int num = 5;
	cout << num << endl;
	cout << &num << endl;

}
/*Problem 2
 * This function takes an integer, adds 4, prints out its value and address.
 * Parameters-
 * 		int num: an integer value
 * Returns-
 * 		Nothing
 */
void add4andPrintValandAddress(int num) {
	num += 4;
	cout << num << endl;
	cout << &num << endl;
}
/*Problem 3
 * This function generates a random number from 0-50 (excluding 50).
 * It prints out the value and address and returns the value.
 * Parameters-
 * 		None
 * Returns-
 * 		int num: random number (0-49)
 */
int randZerotoFifty() {
	srand(time(NULL));
	int randInt = rand() % 50;
	cout << randInt << endl;
	cout << &randInt << endl;
	return randInt;
}
/*Problem 4
 * This function takes in a parameter int address, cube's the value at the address, and prints out
 * the value of the address, the address in the parameter, and the address of the parameter.
 * Parameters-
 * 		int *num: The address of the value to be cubed.
 * Returns-
 * 		Nothing
 */
void cubeByPointer(int *num) {
	*num = *num * *num * *num;		//num = num^3
	cout << *num << endl;		//print value @ num
	cout << num << endl;		//print address in num
	cout << &num << endl;		//print address of num
}
/*Problem 5
 * This function takes an alias of an integer, adds a random number from 0-10, and prints the random number, the new value and the address of the
 * parameter. It returns nothing.
 * Parameters-
 * 		int &num: alias of number
 * Returns-
 * 		Nothing
 */
void addRand(int &num) {
	srand(time(NULL));
	int randInt = rand() % 10 + 1;	//random number between 0-10
	num += randInt;
	cout << randInt << endl;	//print random number
	cout << num << endl;		//print new value of input
	cout << &num << endl;		//print address of input
}
/*Problem 6
 * This function takes two int addresses as inputs and changes their values to 32 and 42 using Call by pointer. It returns nothing.
 * Parameters-
 * 		int *numA
 * 		int *numB
 * Returns-
 * 		Nothing
 */
void change32_42(int *numA, int *numB) {
	int *temp = numA;
	*temp = 32;
	temp = numB;
	*temp = 42;
}
/*Problem 7
 * Parameters-
 * 		char char1
 * 		char &char2
 * 		char *char3
 * Returns-
 * 		Nothing
 */
void changeChars(char char1, char &char2, char *char3) {
	char1 = 'Z';		//out of scope of main
	char2 = 'I';		//in scope of main. Call by Reference
	*char3 = 'G';		//in scope of main. Call by Pointer
}
/*Problem 8a
 * This function swaps the values of the parameters if a is greater than b.
 * It returns a bool swap, true if swap occurred, false if not.
 * Parameters-
 * 		int &numa
 * 		int &numb
 * Returns-
 * 		bool swap
 */
bool swapIfGreaterthan(int &numa, int &numb) {
	bool swap = 0;
	if (numa > numb) {
		int temp = numa;
		numa = numb;
		numb = temp;
		swap = 1;
	}
	return swap;
}
/*Problem 8b
 * This function generates a pair of random numbers 20 times. The random numbers value from 0 to 25.
 * For each generated pair, the number value are printed out, then fed into swapIfGreaterthan() function from problem 8a.
 * If swapped, the values will be printed out again.
 * Parameters-
 * 		None
 * Returns-
 * 		Nothing
 */
void randSwap() {
	srand(time(NULL));
	int randIntA, randIntB;
	for (int i = 0; i < 20; i++) {
		randIntA = rand() % 26;
		randIntB = rand() % 26;
		cout << "Before Swap" << endl;
		cout << randIntA << endl;
		cout << randIntB << endl;
		if (swapIfGreaterthan(randIntA, randIntB)) {
			cout << "After Swap" << endl;
			cout << randIntA << endl;
			cout << randIntB << endl;
		}
	}
}
/*Problem 8c
 * This function generates an int array of random numbers. The length is set by the first parameter while the smallest value of the
 * array is set to the second parameter. The random values will range from 1 to 50.
 * Parameters-
 * 		int len: length of the array
 * 		int &small:	smallest value found in the array
 * Returns-
 * 		Nothing
 */
void arrayMaker(int len, int &small) {
	small = -1;						//Initialized to -1 as per instruction
	if (len < 1)
		return;
	srand(time(NULL));
	int arr[len];
	for (int i = 0; i < len; i++) {
		int randInt = rand() % 50 + 1;
		arr[i] = randInt;
		cout << randInt << ", ";
		if (randInt < small || small < 0)
			small = randInt;
	}
	cout << endl;
	return;
}
/*Problem 9
 * This function generates an int array. It's length is set by the parameter int len. The values of the array are random from 0 to 50.
 * It then prints the array and returns nothing. It
 * Parameters-
 * 		int num
 * Returns-
 * 		Nothing
 */
void arrayMakerReverse(int len) {
	if (len < 1)			//Prevents the function from running an invalid parameter.
		return;
	srand(time(NULL));
	int arr[len];
	for (int i = 0; i < len; i++) {
		int randInt = rand() % 50 + 1;
		arr[i] = randInt;
		cout << randInt << ", ";
	}
	cout << endl;
	int first, last;
	first = 0;
	last = len - 1;
	while (first < last) {
		int temp = arr[first];
		arr[first] = arr[last];
		arr[last] = temp;
		first++;
		last--;
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}
/*Problem 10
 * This function takes in two ints, len and max. It then generates an int array of
 * len amount of values of random numbers. The max value an element can equal is
 * max -1.
 * Parameters-
 * 		int len: Length of int array to be generated
 * 		int max: Max value an array element can be
 * Returns-
 * 		Nothing
 */
void arrayMakerOrder(int len, int max) {
	if (len < 1 || max < 1)
		return;
	srand(time(NULL));
	int arr[len];
	for (int i=0; i<len; i++) {
		int randInt = rand() % max;
		arr[i] = randInt;
		//cout << arr[i] << ", ";			//Used to print original array
	}

	for (int i=0; i<len; i++) {
		int min = max;
		int minElement;
		for (int j=0; j<len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minElement = j;
			}
		}
		cout << min << ", ";
		arr[minElement] = max +1;
	}
	cout << endl;
}
/*Problem 11
 * This function creates a new int variable and initializes it to 3. It prints the value and address, then returns the address.
 * Parameters-
 * 		None
 * Returns-
 * 		int &three: The address of the newly created int variable.
 */
int* returnIntAddress() {
	int three = 3;
	cout << three << endl;
	cout << &three << endl;
	return &three;
}
/*Problem 12
 * Takes in an array of integers and prints out each element. It returns nothing
 * Parameters-
 * 		int arr - An array of integers
 * 		int len - An int representing the length of the array
 * Returns-
 * 		Nothing
 */
void printArray(int arr[], int len) {
	for (int i=0; i<len; i++) {
		cout << arr[i];
		if (i == len-1)
			break;
		cout << ", ";
	}
	cout << endl;
}

/*Problem 13
 * Random num 25-49 -> array on heap of len randnum. It then fills each element
 * with a random number between a random low of -10--5 and random high between 5-10.
 * Input parameters are modified based on the generated array.
 * Parameters:
 * 		int len: Length of the randomly generated array (25-49)
 * 		int high: randomly generated max of array (5-10)
 * 		int low: randomly generated min of array (-10--5)
 * Returns:
 * 		Nothing
 */
int *randArrayPoint(int *len, int *high, int *low) {
	srand(time(NULL));
	*len = rand() % 25 + 25;
	int *arr13 = new int[*len];
	*high = rand() % 11 + 5;
	*low = (rand() % 11 + 5) * -1;		//Negative of possible high values
	for (int i=0; i<*len; i++) {
		int ele = rand() % (*high - *low) + *low;
		arr13[i] = ele;
	}
	return arr13;

}
/*
 * This function prints a line of stars
 * Parameters-
 * 		None
 * Returns-
 * 		Nothing
 */
void printLine() {
	cout << "************************************************************"
			<< endl;
}
/*
 * This function prints the header with the problem number. The problem number increments automatically
 */
void printHeader(int &problemCounter) {
	problemCounter++;
	cout << "Problem " << problemCounter << endl;
}

