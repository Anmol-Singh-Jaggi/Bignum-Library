#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

// Returns a number having "size" digits at max.
string RandNum( const size_t& size )
{
	string result( ( rand() % size ) + 1, '*' );
	result[0] = ( '0' + rand() % 9 + 1 );

	for ( size_t i = 1; i < result.size(); i++ )
	{
		result[i] = ( '0' + rand() % 10 );
	}

	return result;
}

const int add = 1;
const int subtract = 2;
const int multiply = 3;
const int divide = 4; // Too slow
const int mod = 5;
const int power = 6; // Too slow
const int powerInt = 7; // Too slow

void OutputOperationTestCases( const int operation, const int& first, const int& second, const size_t& testCases )
{
	for ( size_t i = 0; i < testCases; i++ )
	{
		cout << RandNum( first ) << " " << RandNum( second ) << " " << operation << "\n";
	}
}

int main()
{
	srand( time( NULL ) );

	const size_t testCases = 100;
	cout << testCases * 7 << "\n";

	OutputOperationTestCases( add, 1000, 1000, testCases );
	OutputOperationTestCases( subtract, 1000, 1000, testCases );
	OutputOperationTestCases( multiply, 1000, 1000, testCases );
	OutputOperationTestCases( divide, 5, 10, testCases );
	OutputOperationTestCases( mod, 1000, 8, testCases );
	OutputOperationTestCases( power, 5, 3, testCases );
	OutputOperationTestCases( powerInt, 5, 3, testCases );

}
