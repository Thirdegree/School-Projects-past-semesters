// CSE240 Homework 01
// Christiansen, Joel

#include <stdio.h>
#include <string.h>

#pragma warning(disable: 4996)

// Q1: Find the error in this function (and then determine if the error is a syntactic, contextual, or semantic error) [10 pts]
// Expected Result: x ^ 2 
// (ex: x = 10, Result = 100) 
int case_one(int x, char *error_type) {

	// What type of error? (Replace INPUT with either Syntactic, Semantic, or Contextual)
	strcpy(error_type, "Semactic");

	return x * x;
}

// Q2: Find the error in this function (and then determine if the error is a syntactic, contextual, or semantic error) [10 pts]
// Expected Result: if x is even number then return "EVEN" else return "ODD" 
// (ex: x = 5, Result = ODD)
char* case_two(int x, char *error_type) {

	// What type of error? (Replace INPUT with either Syntactic, Semantic, or Contextual)
	strcpy(error_type, "semantic");

	if ((x % 2) == 0)
	{
		return "EVEN";
	}
	else
	{
		return "ODD";
	}
}

// Q3: Find the error in this function (and then determine if the error is a syntactic, contextual, or semantic error) [10 pts]
// Expected Result: factorial (assume all values for x are positive integers.)
// (ex: x = 3, Result = 6)
int case_three(int x, char *error_type) {
	int index, result = 1;

	// What type of error? (Replace INPUT with either Syntactic, Semantic, or Contextual)
	strcpy(error_type, "semantic");

	for (index = 1; index <= x; index++)
	{
		result = result * index;
	}

	return result; 
}

// Q4: Find the error in this function (and then determine if the error is a syntactic, contextual, or semantic error) [10 pts]
// Expected Result: determine if the integer value correspond to an alphabetic character.
// (ex: x = 66, Result = "This is an alphabetic character.")
char* case_four(int value, char* error_type) {

	// What type of error? (Replace INPUT with either Syntactic, Semantic, or Contextual)
	strcpy(error_type, "semantic");

	if (((65 <= value) && (value <= 90)) || ((97 <= value) && (value <= 122)))
		return "This is an alphabetic character.";
	else
		return "Invalid character.";
}

// Q5: Find the errors in this function	 [10 pts]
// Expected Result: Print the phrase, "Hello World - x", x number of times.  
// (ex: x = 0, Result = "")
// (ex: x = 2, Result = "Hello World - 1"
//					    "Hello World - 2")
void case_five(int x) {
	int index = 0; 

	while (index < x) {
		printf("Hello World - %d\n", index+1);
		index++;
	}
}

int main() {
	char error_type[50]; 

	printf("Expected result: 100  \tActual result: %d\n", case_one(10, error_type));
	printf("Expected result: EVEN \tActual result: %s\n", case_two(-2, error_type));
	printf("Expected result: 6    \tActual result: %d\n", case_three(3, error_type));
	printf("Expected result: \"Invalid character.\" \tActual result: \"%s\"\n", case_four('$', error_type));
	
	case_five(5);

	return 0; 
}