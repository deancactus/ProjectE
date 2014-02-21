/*
 * problem1.cpp
 *
 *  Created on: Feb 19, 2014
 *      Author: dean
 */
#include <iostream>
//#include <limits>
#include <cmath>	//Problem 3

void problem1();
void problem2();
void problem3();
void problem4();

int main() {
	/*
	 * Un-comment the solution you wish to compute:
	 */

	//problem1();
	//problem2();
	//problem3();
	problem4();
	return 0;
}


void problem1() {
	/* TO DO:
	 * 	Find multiples of 3 or 5 below 1000
	 * 	Sum the list
	 * OR
	 *	Add to a rolling sum every time we find a multiple of 3 or 5 <---
	 */
	int sum = 0;	//Initiate the sum

	for (int i = 1; i < 1000; ++i) {
		if (( i % 3 == 0 ) || ( i % 5 == 0 )) sum += i;
	}

	std::cout << "Sum: " << sum << std::endl;
}

void problem2() {
	/*
	 * TO DO:
	 * 	Sum even members of Fibonacci sequence <= 4 million
	 */
	long sum = 2;	//First even value of the sequence is one of the seed values
	int last1 = 1;	//First seed value of Fibonacci sequence
	int last2 = 2;	//Second seed value of Fibonacci sequence
	int temp = 0;	//Will hold a seed value as it's updated

	while (true) {
		temp = last1;
		last1 = last2;
		last2 += temp;
		if (last2 > 4000000) break;
		else if (last2 % 2 == 0) sum += last2;
	}

	std::cout << "Sum: " << sum << std::endl;
}

//Slow and dirty prime check
bool isPrime(unsigned long long num2test) {
	//Check 2
	if (num2test % 2 == 0) return false;
	//Check odd numbers
	for (unsigned long long i = 3; i*i < num2test; i+=2) {
		if (num2test % i == 0) return false;
	}
	return true;
}

void problem3() {
	/*
	 * TO DO:
	 * 	Identify the largest prime factor of 600851475143 (BIG_NUM)
	 * OPTIONS:
	 * 	Identify all prime numbers up to BIG_NUM
	 * 	Check from the largest to smallest for a factor of BIG_NUM
	 * OR
	 * 	Identify factors of BIG_NUM
	 * 	Identify prime numbers up to largest factor
	 * 	Find a match
	 */
	unsigned long long int BIG_NUM = 600851475143;
	//unsigned primeList[62115] = {};
	//unsigned primesFound = 0;
	//bool thisPrime;
	unsigned long long int LPF; //Largest prime factor

	//Find factors of BIG_NUM and check them for prime
	// - starting with the largest
	for (unsigned divisor = 2; divisor*divisor < BIG_NUM; ++divisor) {
		if (BIG_NUM % divisor == 0) {
			if (isPrime(BIG_NUM/divisor)) {
				LPF = BIG_NUM/divisor;
				break;
			}
		}
	}


	/*
	for (unsigned i = 3; i < std::sqrt(BIG_NUM); i+=2) {
		thisPrime = true;
		for (unsigned int j = 0; j < primesFound; ++j) {
			if (i % primeList[j] == 0) {
				thisPrime = false;
				break;
			}
		}
		if (thisPrime) {
			primeList[primesFound] = i;
			++primesFound;
			if (BIG_NUM % i == 0) LPF = i;
		}
	}
	*/
	std::cout << "Largest prime factor so far: " << LPF << std::endl;
}


void problem4() {


}
