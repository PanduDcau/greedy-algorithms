//C++ program to print Egyptian fractions
#include <bits/stdc++.h>
using namespace std;

//Prints the Egyptian fractions
void egyptianFraction(int n, int d){
//Returns when both Numerator and denominator becomes zero
	if(d==0 || n==0)
		return;
		
	//Finds the ceiling of the d/n
	if(d%n == 0){
		cout << "1/" << d/n;
		return;
	}
	
	if(n%d == 0){
		cout << n/d;
		return;
	}
	
	if(n > d){
		cout << n/d << " + ";
		egyptianFraction(n%d, d);
		return;
	}
	
	int x = d/n + 1;
	cout << "1/" << x << " + ";
	egyptianFraction(n*x-d, d*x);
}

//Main code
int main(){
	int numerator = 12, denominator = 13;
	
	cout << "The Egyptian Fraction representation of " << numerator << "/" << denominator << ": ";
	
	//Function call
	egyptianFraction(numerator, denominator);
	
	return 0;
}

