#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <cstddef>
#include <vector>

using namespace std;

void DecimalToBinary(int n)
{	
	vector<string> binary;
	//while (n > 0 || n == 0){
		if ( n  != 0){

			binary.push_back( to_string(n % 2) );
			n = n / 2;
			DecimalToBinary(n);
		
		}
	//}
	for (int i =0; i < binary.size(); i++){
		cout << binary[i];
	}
	//cout << endl;
}
int main(){
	int number = 3;
	DecimalToBinary(number);
	cout<<endl;
	//cout << 15 /2 <<endl;
	return 0;

}
/*
 algorithm ToBinary(n)
	Pre: n≥0
	Post: n has been converted into its base 2 representation
	while n>0
		list.Add(n % 2)
		n ← n/2
	 end while
	return Reverse(list)
    end ToBinary
*/