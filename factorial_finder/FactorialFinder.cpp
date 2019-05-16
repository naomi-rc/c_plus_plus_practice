/**
Author: Naomi Catwell
Description: This program finds the factorial of number using recursion and loops
Date: May 15, 2019
*/

#include <iostream>
using namespace std;

int fact(int number){
	if(number == 1){
		return number;
	}
	else{
		return number * fact(number - 1);
	}
}

int main(){
	int number, result;
	do{
		cout << "Enter a whole number to find its factorial (-1 to exit): ";
		try{
			cin >> number; //Check how to check for validation ie don't creash when string is entered as input
			if(number < 0){
				throw "Invalid input!";
			}
			else{
				result = fact(number);
				cout << "The factorial of " << number << " is " << result << endl << endl;
			}
			
		}
		catch(const char* msg){
			if(number != -1)
				cout << "Please enter a positive whole number.";
		}	
		
	}while(number != -1);
	
}
