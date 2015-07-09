#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

int StringToInt( const string& str )
{
	int result = 0;

	stringstream ss( str );
	ss >> result;

	return result;
}

// Remove all the zeroes at the beginning of the number
void StripZeroes( string& num )
{
	size_t i = 0;
	while ( i < num.size() && num[i] == '0' )
	{
		i++;
	}
	num = num.substr( i );

	if ( num.empty() )
	{
		num = "0";
	}
}

// Add 2 numbers
string BigAdd( string num1, string num2 )
{
	if ( num2.size() > num1.size() )
	{
		// First number should be greater than or equal to the second number in length
		swap( num1, num2 );
	}

	// Pad the second number with zeroes at the front to make it equal in length to the first number
	num2.insert( 0, num1.size() - num2.size(), '0' );

	const int size = num1.size();
	string result( size + 1, '*' );

	int i, temp = 0;
	for ( i = size - 1; i >= 0; i-- )
	{
		// temp/10 is the carry
		temp = ( num1[i] - '0' ) + ( num2[i] - '0' ) + temp / 10;
		result[i + 1] = ( '0' + temp % 10 );
	}
	result[++i] = ( '0' + temp / 10 );

	StripZeroes( result );

	return result;
}

// Returns abs(num1 - num2)
string BigSubtract( string num1, string num2 )
{
	// The first number should be greater than the second number in value
	if ( num2.size() > num1.size() || ( num2.size() == num1.size() && num2 > num1 ) )
	{
		// Uncomment to return "0" if num1 < num2
		//return "0";
		swap( num1, num2 );
	}

	// Pad the smaller number with zeroes at the front
	num2.insert( 0, num1.size() - num2.size(), '0' );

	const int size = num1.size();
	string result( size, '*' );

	int i, temp = 0;
	bool borrow = false;
	for ( i = size - 1; i >= 0; i-- )
	{
		temp = ( num1[i] - num2[i] - borrow + 10 ) % 10;
		borrow = ( num1[i] - borrow ) < num2[i];
		result[i] = ( '0' + temp );
	}

	StripZeroes( result );

	return result;
}

// Helper function for BigMul()
// Multiplies a string with a character
string BigMulChar( const string& num1, const char& num2 )
{
	string result( num1.size() + 1, '*' );

	const int size = num1.size();

	int i, prod = 0;
	for ( i = size - 1; i >= 0; i-- )
	{
		prod = ( num1[i] - '0' ) * ( num2 - '0' ) + prod / 10;
		result[i + 1] = ( '0' + prod % 10 );
	}
	result[++i] = ( '0' + prod / 10 );

	StripZeroes( result );

	return result;
}

// Returns the product of 2 numbers
string BigMul( string num1, string num2 )
{
	if ( num2.size() > num1.size() )
	{
		swap( num1, num2 );
	}

	string result;

	const int size = num2.size();
	int i = size - 1;
	while ( i >= 0 )
	{
		result = BigAdd( result, ( BigMulChar( num1, num2[i] ) + string( size - i - 1, '0' ) ) );
		i--;
	}

	StripZeroes( result );

	return result;
}

// Returns floor(num1 / num2)
// **Caution : Very slow**
string BigDiv( string num1, string num2 )
{
	string result = "0";

	while ( num1.size() > num2.size() || ( num1.size() == num2.size() && num1 >= num2 ) )
	{
		num1 = BigSubtract( num1, num2 );
		// Basically we are counting how many times does num2 fit into num1
		result = BigAdd( result, "1" );
	}

	return result;
}

// Returns num % mod
int BigMod( const string& num, const int& mod )
{
	int result = 0;

	for ( size_t i = 0; i < num.size(); i++ )
	{
		result = ( ( result * 10 ) + ( num[i] - '0' ) ) % mod;
	}

	return result;
}

// Returns num1 ^ num2
string BigPow( string num1, string num2 )
{
	if ( num2 == "0" )
	{
		return "1";
	}

	if ( ( num2[num2.size() - 1] - '0' ) & 1 )
	{
		string temp = BigPow( num1, BigDiv( num2, "2" ) );
		return BigMul( BigMul( num1, temp ), temp );
	}
	else
	{
		string temp = BigPow( num1, BigDiv( num2, "2" ) );
		return BigMul( temp, temp );
	}

}

// Returns num1 ^ num2
string BigPow( string num1, int num2 )
{
	if ( num2 == 0 )
	{
		return "1";
	}

	if ( num2 & 1 )
	{
		string temp = BigPow( num1, num2 >> 1 );
		return BigMul( BigMul( num1, temp ), temp );
	}
	else
	{
		string temp = BigPow( num1, num2 >> 1 );
		return BigMul( temp, temp );
	}
}

int main()
{
	int t;
	//cout << "Enter number of test cases - ";
	cin >> t;

	while ( t-- )
	{
		string num1, num2;
		//cout << "Enter 2 numbers\n";
		cin >> num1 >> num2;

		//cout << "1.Add\n2.Substract\n3.Multiply\n4.Divide\n5.Mod\n6.Power\n7.Power_Int\n";
		char option;
		cin >> option;

		if ( option == '1' )
		{
			cout << BigAdd( num1, num2 ) << "\n";
		}
		else if ( option == '2' )
		{
			cout << BigSubtract( num1, num2 ) << "\n";
		}
		else if ( option == '3' )
		{
			cout << BigMul( num1, num2 ) << "\n";
		}
		else if ( option == '4' )
		{
			cout << BigDiv( num1, num2 ) << "\n";
		}
		else if ( option == '5' )
		{
			int num2Int = StringToInt( num2 );
			cout << BigMod( num1, num2Int ) << "\n";
		}
		else if ( option == '6' )
		{
			cout << BigPow( num1, num2 ) << "\n";
		}
		else if ( option == '7' )
		{
			int num2Int = StringToInt( num2 );
			cout << BigPow( num1, num2Int ) << "\n";
		}
		else
		{
			cout << "Invalid Option!!\n";
			exit( 1 );
		}
	}
}
