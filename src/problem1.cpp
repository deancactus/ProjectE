/*
 * problem1.cpp
 *
 *  Created on: Feb 19, 2014
 *      Author: dean
 */
#include <iostream>
#include <iomanip>
//#include <limits>
//#include <cmath>	// sqrt
#include <cstdlib>	// atoi
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();

using namespace std;

int main() {
	/*
	 * Un-comment the solution you wish to compute:
	 */

	//problem1();
	//problem2();
	//problem3();
	//problem4();
	//problem5();
	//problem6();
	//problem7();
	//problem8();
	problem9();


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
	//Check
	for (unsigned long long i = 2; i*i <= num2test; ++i) {
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
	 * 	Identify factors of BIG_NUM	<----
	 * 	Check for prime
	 */
	unsigned long long int BIG_NUM = 600851475143;
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
	std::cout << "Largest prime factor: " << LPF << std::endl;
}


void problem4() {
	string prod;	//Product of two 3-digit numbers as a string
	string rprod;	//Reversed prod
	int largestPalindrome = 0;
	for (int i = 999; i > 99; --i) {
		for (int j = 999; j > 99; --j) {
			rprod.clear();
			prod = boost::lexical_cast<string>(i*j);
			for (string::reverse_iterator rit = prod.rbegin(); rit != prod.rend(); ++rit) {
				rprod += *rit;
			}
			if (prod.compare(rprod) == 0) {
				largestPalindrome = atoi(prod.c_str()) > largestPalindrome ? atoi(prod.c_str()) : largestPalindrome;
			}
		}
	}
	cout << "Largest 3-digit product palindrome: " << largestPalindrome << endl;
}


void problem5() {
	unsigned long long smallestNumber = -1; //58198140
	bool allFactors;

	for (unsigned long long i = 20; i < 300000000; i += 20) {
		allFactors = true;
		for (unsigned long long divisor = 1; divisor < 21; ++divisor) {
			if (i % divisor) {
				allFactors = false;
				break;
			}
		}
		if (allFactors) {
			smallestNumber = i;
			break;
		}
	}

	cout << "Smallest number that meets the criteria: " << smallestNumber << endl;
}


void problem6() {
	unsigned justSum = 0;
	unsigned sumOfSquares = 0;
	unsigned squareOfSum = 0;

	for (unsigned i = 1; i < 101; ++i) {
		sumOfSquares += (i * i);
		justSum += i;
	}

	squareOfSum = justSum * justSum;

	cout << "Difference: " << squareOfSum - sumOfSquares << endl;

}

void problem7() {
	unsigned long long currentNum = 5;
	unsigned long long MAX_TRY = 4000000000;
	unsigned primesFound = 2;

	for (; currentNum < MAX_TRY; currentNum+=2) {
		if (isPrime(currentNum)) {
			cout << currentNum << endl;
			++primesFound;
		}
		if (primesFound == 10001) break;
	}

	cout << "10001st prime: " << currentNum << endl;
}


void problem8() {
	string master_string = "";
	master_string.reserve(1000);
	master_string += "73167176531330624919225119674426574742355349194934";
	master_string += "96983520312774506326239578318016984801869478851843";
	master_string += "85861560789112949495459501737958331952853208805511";
	master_string += "12540698747158523863050715693290963295227443043557";
	master_string += "66896648950445244523161731856403098711121722383113";
	master_string += "62229893423380308135336276614282806444486645238749";
	master_string += "30358907296290491560440772390713810515859307960866";
	master_string += "70172427121883998797908792274921901699720888093776";
	master_string += "65727333001053367881220235421809751254540594752243";
	master_string += "52584907711670556013604839586446706324415722155397";
	master_string += "53697817977846174064955149290862569321978468622482";
	master_string += "83972241375657056057490261407972968652414535100474";
	master_string += "82166370484403199890008895243450658541227588666881";
	master_string += "16427171479924442928230863465674813919123162824586";
	master_string += "17866458359124566529476545682848912883142607690042";
	master_string += "24219022671055626321111109370544217506941658960408";
	master_string += "07198403850962455444362981230987879927244284909188";
	master_string += "84580156166097919133875499200524063689912560717606";
	master_string += "05886116467109405077541002256983155200055935729725";
	master_string += "71636269561882670428252483600823257530420752963450";

	//cout << master_string.size() << endl;

	string sub_string;

	int current_product;
	int max_product = 0;

	for (unsigned sub_start_pos = 0; sub_start_pos < master_string.size() - 5; ++sub_start_pos) {
		sub_string = master_string.substr(sub_start_pos, 5);
		current_product = 1;
		for (string::iterator it = sub_string.begin(); it != sub_string.end(); ++it) {
			current_product *= (*it) - '0'; //*it returns a char, - '0' converts to int
		}
		if (current_product > max_product) max_product = current_product;
	}
	cout << "Max 5-digit product found: " << max_product << endl;
}

class Triple {
public:
	int a, b, c;
	Triple(const int &input_a, const int &input_b, const int &input_c) : a(input_a), b(input_b), c(input_c) {}
	Triple(Triple &o)
	int sum() const {return a + b + c;}
	int prod() const {return a * b * c;}
	void set_a(const int &new_a) {a = new_a;}
	void set_b(const int &new_b) {b = new_b;}
	void set_c(const int &new_c) {c = new_c;}
};

// In-progress

void problem9() {
	vector<Triple> tripleStack; //Holds triples that sum to less than 1000
	Triple seedTriple(3, 4, 5); //The seed triple for
	tripleStack.push_back(seedTriple);	//Add initial seed value to stack
	Triple magicTriple(3, 4, 5);
	Triple T1(0, 0, 0), T2(0, 0, 0), T3(0, 0, 0);
	unsigned safetyCount = 0;

	while (!tripleStack.empty()) {
		++safetyCount;
		Triple parentTriple = tripleStack.back();
		tripleStack.pop_back();

		T1.set_a(parentTriple.a - 2 * parentTriple.b + 2 * parentTriple.c);
		T1.set_b(2 * parentTriple.a - parentTriple.b + 2 * parentTriple.c);
		T1.set_c(2 * parentTriple.a - 2 * parentTriple.b + 3 * parentTriple.c);
		cout << T1.a << " " << T1.b << " " << T1.c << endl;
		if (T1.sum() == 1000) {
			cout << "Product of magic triple1: " << T1.prod() << endl;
			magicTriple = T1;
			break;
		}
		else if (T1.sum() < 10000) tripleStack.push_back(T1);

		T2.set_a(parentTriple.a + 2 * parentTriple.b + 2 * parentTriple.c);
		T2.set_b(2 * parentTriple.a + parentTriple.b + 2 * parentTriple.c);
		T2.set_c(2 * parentTriple.a + 2 * parentTriple.b + 3 * parentTriple.c);
		cout << T2.a << " " << T2.b << " " << T2.c << endl;
		if (T2.sum() == 1000) {
			cout << "Product of magic triple2: " << T2.prod() << endl;
			magicTriple = T2;
			break;
		}
		else if (T2.sum() < 10000) tripleStack.push_back(T2);

		T3.set_a(-parentTriple.a + 2 * parentTriple.b + 2 * parentTriple.c);
		T3.set_b(-2 * parentTriple.a + parentTriple.b + 2 * parentTriple.c);
		T3.set_c(-2 * parentTriple.a + 2 * parentTriple.b + 3 * parentTriple.c);
		if (T3.sum() == 1000) {
			cout << "Product of magic triple3: " << T3.prod() << endl;
			magicTriple = T3;
			break;
		}
		else if (T3.sum() < 10000) tripleStack.push_back(T3);

		if (safetyCount > 10000000) {
			cout << safetyCount << endl;
			break;
		}
		cout << "Loop has run: " << safetyCount << endl;
	}

	cout << "Product of magic triple: " << magicTriple.prod() << endl;
}
