#include <iostream>
using namespace std;

long fact (long i) 
{
  	long result = 1;
  	while (i > 0) {
   	 result = result * i;
   	 i = i-1;
  }
  	return(result);
}

	int main () {
  	int n;
  	cout << "Enter a natural number: ";
  	cin >> n;
  	while (n < 0) {
    	cout << "Please re-enter: ";
    	cin >> n;
  }
  	cout << n << "! = " << fact(n) << endl;
  	return(0);
}

