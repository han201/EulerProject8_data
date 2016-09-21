// With the use of long int, I could get the correct answer as Python. If I use regular int, the answer will be just wrong.
// (Q) I spent a lot of time to try to convert the string (or in fact, 'char') of the outputstring[j]. 
// I used atoi, stoi, stringstream convert, etc, but all failed until I subtracted '0' and put (int). Is there any cleverer way?


/*
#Find the thirteen adjacent digits in the 1000 - digit number that have the greatest product.
# What is the value of this product ?

fhand = open('EulerProject8_data.txt')   # Open the data
inp = fhand.read()                       # read as a string
inp = ''.join([line.strip() for line in inp])   # removes newline space

maximum = 1                               #maximum number for result
numOfMul = 13                             #number of numbers that are mulplied
for i in range(0, len(inp) - numOfMul) :
	product = 1  # initial value
	for j in range(i, i + numOfMul) :
		product = product * int(inp[j])
		if (maximum<product) :
			maximum = product
			print inp[i:i + numOfMul], maximum
*/



#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

int main() {
	ifstream file("EulerProject8_data.txt");
	string outputstring;
	string buffer;
	
	while (getline(file, buffer)) {
			outputstring += buffer;
		}
			
	cout << outputstring << endl;

	
	long long int maximum = 1;                               
	int	numOfMul = 13;                             
		
	for (int i=0;i <(outputstring.length()-numOfMul);i++) {
		long long int product = 1;
		
		for (int j = i; j < i + numOfMul; j++) {
			// cout << typeid(outputstring[j]).name() << endl;
			int x = outputstring[j] - '0';
			product = product *x;
		}
		if (maximum < product) {
			maximum = product;
		    for (int k = i;k < i+numOfMul; k++)
				cout << outputstring[k] << endl;
			cout << maximum << endl;
		}
		
	}
	system("pause");
	return 0;	
}

