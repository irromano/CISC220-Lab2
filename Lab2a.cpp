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
#include <cmath>
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
int *stackArray(int length);
void printArrayAddress(int arr[], int len);
void doubleArr(double arr[], int length);
int *removeSequentialDuplicates(int arr[], int &len);
int hanningWindow(int arr[], int length);
int* hanningArray(int arr[], int length);
void printGraph(int arr[], int len, int min, int max);
int **twoDimArray(int *x, int *y);

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
	cout << "Printing out the pointing value and the value of 'threePointer' terminates the program. The value of threePointer zeros when the original function finishes." << endl;
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
	cout << "A array of random length (25 to 49) with random int elements between a random min (-10 to -5) and random max (5 to 10) should print:" << endl;
	int length;
	int max = 0;
	int min = 0;
	int* arr13b = randArrayPoint(&length, &max, &min);
	//int arr13b[length];
	printArray(arr13b, length);
	printLine();

	//Header for Problem 14
	printHeader(problem);
	cout << endl;
	int lengthStackArr = 25;
	int *stackArr = stackArray(lengthStackArr);

	/* This won't work since the array is being put on the stack. After the function is done running,
	 * the array will be taken off the stack and when we try and call it in main,
	 * the function will point to an array that doesn't exist.dP
	 */
	cout << "Doesn't work" << endl;
	printLine();

	//Header for Problem 15
	printHeader(problem);
	cout << endl;
	srand(time(NULL));				//Setting seed for RNG
	int arr15[10];
	for (int i=0; i<10; i++){			//build int array of rand ints
		arr15[i]= rand() % 10 + 1;		//random int 1-10
	}
	printArrayAddress(arr15, 10);
	printLine();

	//Header for Problem 16
	printHeader(problem);

	//Test 1
	cout << "Test 1: " << endl;
	double dbleArr1[10];
	for (int e = 0; e < 10; e++) {
		dbleArr1[e] = (double) rand() / 10000000;
	}
	doubleArr(dbleArr1, 10);
	//Test 2
	cout << "Test 2: " << endl;
	double dbleArr2[20];
	for (int e = 0; e < 20; e++) {
		dbleArr2[e] = (double) rand() / 10000000;
	}
	doubleArr(dbleArr2, 20);
	//Test 3
	cout << "Test 3: " << endl;
	double dbleArr3[30];
	for (int e = 0; e < 30; e++) {
		dbleArr3[e] = (double) rand() / 10000000;
	}
	doubleArr(dbleArr3, 30);
	printLine();

	//Header for Problem 17
	printHeader(problem);
	cout << endl;
	cout << "Testcase 1" << endl;
	int arr17a[] = {1, 2, 2, 4, 4, 5};
	int length17 = 6;
	int* arr17b = removeSequentialDuplicates(arr17a, length17);
	// 4 length array should print: 1, 2, 4, 5
	printArray(arr17b, length17);
	cout << endl;

	cout << "Testcase 2" << endl;
	int arr17c[] = {1, 2, 3, 4, 5, 6};
	length17 = 6;
	int* arr17d = removeSequentialDuplicates(arr17c, length17);
	// 6 length array should print: 1, 2, 3, 4, 5, 6
	printArray(arr17d, length17);
	cout << endl;

	cout << "Testcase 3" << endl;
	int arr17e[] = {10, 10, 9, 9, 8, 8, 7, 7, 7, 7};
	length17 = 10;
	int* arr17f = removeSequentialDuplicates(arr17e, length17);
	// 4 length array should print: 10, 9, 8, 7
	printArray(arr17f, length17);
	printLine();

	//Header for Problem 18
	printHeader(problem);
	//Test 1
	cout << "Test 1: " << endl;
	int arr18_1[9] = { 3, 8, 2, 5, 1, 4, 6, 0, 2 };
	printArray(arr18_1, 9);
	cout << "Average value: " << hanningWindow(arr18_1, 9) << endl;
	cout << "Weighted value: " << hanningWindow(arr18_1, 9) * 25 << endl;
	//Test 2
	cout << "Test 2: " << endl;
	int arr18_2[5] = { 3, 8, 2, 5, 1, };
	printArray(arr18_2, 5);
	cout << "Average value: " << hanningWindow(arr18_2, 5) << endl;
	cout << "Weighted value: " << hanningWindow(arr18_2, 5) * 9 << endl;
	//Test 2
	cout << "Test 3: " << endl;
	int arr18_3[7] = { 8, 2, 5, 1, 4, 6, 0, };
	printArray(arr18_3, 7);
	cout << "Average value: " << hanningWindow(arr18_3, 7) << endl;
	cout << "Weighted value: " << hanningWindow(arr18_3, 7) * 16 << endl;
	printLine();

	//Header for Problem 19
	printHeader(problem);
	//Test 1
	cout << "Test 1: " << endl;
	printArray(arr18_1, 9);
	cout << "New Array: " << endl;
	printArray(hanningArray(arr18_1, 9),9);
	//Test 2
	cout << "Test 2: " << endl;
	printArray(arr18_2, 5);
	cout << "New Array: " << endl;
	printArray(hanningArray(arr18_2, 5),5);
	//Test 2
	cout << "Test 3: " << endl;
	printArray(arr18_3, 7);
	cout << "New Array: " << endl;
	printArray(hanningArray(arr18_3, 7),7);
	printLine();


	//Header for problem 20
	printHeader(problem);
	cout << endl;

	cout << "Testcase 1" << endl;
	int arr20a[] = { 6, 8, 2, 3, 2, 5, -2 };
	printGraph(arr20a, 7, -2, 8);

	cout << "Testcase 2" << endl;
	int arr20b[] = { -9, -8, -7, -6, -5, -4};
	printGraph(arr20b, 6, -9, -4);

	cout << "Testcase 3" << endl;
	int arr20c[] = { 7, 6, 5, 4, 3, 2, 1};
	printGraph(arr20c, 7, 1, 7);
	cout << endl;
	printLine();


	//Header for problem 21
	printHeader(problem);
	cout << endl;
	cout << "This should print a 2-dim int array of random width and height (4-8 and 5-10). All elements are zeros except 5 random 1's." << endl;
	int height;
	int width;
	int **arr21dim = twoDimArray(&height, &width);
	for (int i=0; i<height; i++)
		printArray(arr21dim[i], width);


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
/*Problem 14
 * Creates an array on the stack instead of the heap
 * and fills it with random numbers (doesn't work)
 * Parameters:
 * 		int length: the size of the array b/w 25 and 50
 * Returns:
 * 		int - address of the first value of the array
 */
int *stackArray(int length) {
	length = rand() % 25 + 25;
	int high = rand() % 5 + 5;
	int low = (rand() % 5) * (-1) - 5;
	int arr[length];
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (high - low) - high;
	}
	return arr;
}
/*Problem 15
 * Takes in an int array and prints out the address of each element.
 * Parameters:
 * 	int arr: an array of integers
 * 	int len: length of the array to be printed
 * Returns:
 * 	Nothing
 */
void printArrayAddress(int arr[], int len) {
	for (int i=0; i<len; i++) {
		cout << &arr[i];
		if (i == len-1)
			break;
		cout << ", ";
	}
	cout << endl;
}
/*Problem 16
 * Takes an array of doubles and prints out every address of every value
 * in the array.
 * Parameters:
 * 		double arr[]: an array of doubles
 * 		int length: length of the array
 * Returns:
 * 		Nothing
 */
void doubleArr(double arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << "# " << i << " address: " << &arr[i] << ". Value: " << arr[i]
				<< endl;
	}
}
/*Problem 17
 * This function takes in an int array and an int representing its length. It then returns an array of the same elements with
 * the repeating elements removed. This only removes an element if it is the same value as the element preceding it. The
 * value of the length input is modified to the length of the new array returned.
 * Parameters:
 * 		int arr: an array of integers
 * 		int len: length of the array inputed
 * Returns:
 * 		int newArr: new array with sequential repeated elements removed.
 */
int *removeSequentialDuplicates(int arr[], int &len) {
	int *newArr = new int[len];
	newArr[0] = arr[0];
	int ele = 0;
	for (int i=1; i<len; i++) {
		if (arr[i] != newArr[ele]) {
			newArr[ele + 1] = arr[i];
			ele++;
		}
	}
	len = ele + 1;
	return newArr;
}
/*Problem 18
 * Takes an array of integers, and smoothes the array by taking the average
 * of the array and replace any outliers with the average of the array and
 * replaces the outer values with 0's. It weighs the values of the array
 * to provide a smoother average than a simple low-pass filter.
 * Parameters:
 * 		int arr[]: array of integers
 * 		int length: length of the array
 * Returns:
 * 		int - average value of the array
 */
int hanningWindow(int arr[], int length) {
	int multiply = 1;
	int divide = 0;
	int sum = 0;
	if (length <= 0) {
		return 0;
	}
	for (int i = 0; i < length; i++) {
		sum += multiply * arr[i];
		divide += multiply;
		if ((i + 1) <= ceil(length / 2)) {
			multiply++;
		} else {
			multiply--;
		}
	}
	return (sum / divide);
}

/*Problem 19
 * Takes an array of integers, and uses the function
 * in Problem 18 to smooth out the array and get rid
 * of outliers.
 * Parameters:
 * 		int arr[]: array of integers
 * 		int length: length of the array
 * Returns:
 * 		int - new array of ints
 */
int* hanningArray(int arr[], int length) {
	int i = 0;
	int *newArray = new int[length];
	for (int i = 0; i < length; i++) {
		if (i == 0 || i == 1 || i == length-1 || i == length-2) {
			newArray[i] = 0;
		} else {
			newArray[i] = hanningWindow(&arr[i-2],5);
		}
	}
	return newArray;
}
/*Problem 20
 * This function prints out a graph of an array of values over element iteration.
 * Parameters-
 * 		int arr[]: The array to be graphed
 * 		len: Length of the array
 * 		min: minimum values to be graphed
 * 		max: maximum values to be graphed
 */
void printGraph(int arr[], int len, int min, int max) {
	for (int i=max; i> min-1; i--) {
		cout << i << ':';
		for (int j=0; j<len; j++) {
			if (arr[j] == i) {
				cout <<'*';
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}
/*Problem 21
 * This function takes in two integer addresses and returns the address of a 2-dimensional array.
 * The number of rows will be a random number between 5 and 10. the number of columns will be a random number
 * between 4 and 8. Values of inputs will be changed to lenght and width via call-by-pointer.
 * Parameters-
 * 		int x: number of col
 * 		int y: number of rows
 * Returns-
 * 		A two dimensional array of integers, randomly 5-10 high and 4-8 wide
 */
int **twoDimArray(int *x, int *y) {
	srand(time(NULL));
	*x = rand() % 5 + 5;
	*y = rand() % 4 + 4;
	int **arr21 = new int*[*x];
	for (int i=0; i<*x; i++) {
		arr21[i] = new int[*y];
		for (int j=0; j<*y; j++)
			arr21[i][j] = 0;
	}
	int xa = rand() % *x;
	int ya = rand() % *y;
	int xb;
	int yb;
	int xc;
	int yc;
	int xd;
	int yd;
	int xe;
	int ye;
	do {
		xb = rand() % *x;
		yb = rand() % *y;
	} while (xb == xa && yb == ya);
	do {
		xc = rand() % *x;
		yc = rand() % *y;
	} while ((xc == xa && yc == ya ) || (xc == xb && yc == yb ));
	do {
		xd = rand() % *x;
		yd = rand() % *y;
	} while ((xd == xa && yd == ya) || (xd == xb && yd == yb ) || (xd == xc && yd == yc ));
	do {
		xe = rand() % *x;
		ye = rand() % *y;
	} while ((xe == xa && ye == ya) || (xe == xb && ye == yb)  || (xe == xc && ye == yc) || (xe == xd && ye == yd) );
	arr21[xa][ya] = 1;
	arr21[xb][yb] = 1;
	arr21[xc][yc] = 1;
	arr21[xd][yd] = 1;
	arr21[xe][ye] = 1;
	return arr21;

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

