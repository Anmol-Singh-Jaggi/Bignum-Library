#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

void stripZeroes( string& num ) // Remove all the zeroes at the beginning of the input...
{
	int i = 0;
	while ( i < ( int )num.size() && num[i] == '0' )
	{
		i++;
	}
	num = num.substr( i );
}

string bigAdd( string n, string m ) // Add numbers "n" and "m"...
{
	if ( m.size() > n.size() )
	{
		swap( n, m );    // "n" should be greater than or equal to "m" in length...
	}
	int size = n.size();
	m.insert( 0, n.size() - m.size(), '0' ); // Pad "m" with zeroes at the front to make it equal in length to "n"..
	string result( size + 1, '*' ); // Stores the result...
	int temp = 0, i;
	for ( i = size - 1; i >= 0; i-- )
	{
		temp = ( n[i] - '0' ) + ( m[i] - '0' ) + temp / 10; // temp/10 is the carry..
		result[i + 1] = ( char )( '0' + temp % 10 );
	}
	result[++i] = ( char )( '0' + temp / 10 );
	stripZeroes( result );
	if ( result.empty() )
	{
		result = "0";
	}
	return result;
}

string bigSubtract( string n, string m ) // returns abs(n-m)
{
	if ( m.size() > n.size() || ( m.size() == n.size() && m > n ) ) // "n" should be greater than "m" in value...
	{
		//return "0";  // Uncomment to return "0" if n<m ...
		swap( n, m );
	}
	int size = ( int )n.size();
	m.insert( 0, n.size() - m.size(), '0' ); // Pad the smaller number with zeroes at the front...
	string result( size, '*' );
	int i, temp = 0;
	bool borrow = false;
	for ( i = size - 1; i >= 0; i-- )
	{
		temp = ( n[i] - m[i] - borrow + 10 ) % 10;
		borrow = ( n[i] - borrow ) < m[i];
		result[i] = ( char )( '0' + temp );
	}
	stripZeroes( result );
	if ( result.empty() )
	{
		result = "0";
	}
	return result;
}

string bigMulChar( const string& n, const char& m ) //  Helper function for bigmul() ...  [ Multiplies a string with a character ]
{
	string result( n.size() + 1, '*' );
	int i, size = n.size(), prod = 0;
	for ( i = size - 1; i >= 0; i-- )
	{
		prod = ( n[i] - '0' ) * ( m - '0' ) + prod / 10;
		result[i + 1] = ( char )( '0' + prod % 10 );
	}
	result[++i] = ( char )( '0' + prod / 10 );
	stripZeroes( result );
	if ( result.empty() )
	{
		result = "0";
	}
	return result;
}

string bigMul( string n, string m ) // Returns n*m...
{
	if ( m.size() > n.size() )
	{
		swap( n, m );
	}
	string result;
	int size = m.size();
	int i = size - 1;
	while ( i >= 0 )
	{
		result = bigAdd( result, ( bigMulChar( n, m[i] ) + string( size - i - 1, '0' ) ) );
		i--;
	}
	stripZeroes( result );
	if ( result.empty() )
	{
		result = "0";
	}
	return result;
}

string bigDiv( string n, string m ) // Returns floor(n/m) **Caution : Very slow**
{
	string result = "0";
	while ( n.size() > m.size() || ( n.size() == m.size() && n >= m ) )
	{
		n = bigSubtract( n, m );
		result = bigAdd( result, "1" ); // Basically we are counting how many times does "m" fit into "n"...
	}
	return result;
}

int bigMod( string s, int mod ) // Returns s%mod ...
{
	int sum = 0;
	for ( int i = 0; i < ( int )s.size(); i++ )
	{
		sum = ( ( sum * 10 ) + ( s[i] - '0' ) ) % mod;
	}
	return sum;
}

string bigPow( string n, string m ) // Returns n^m.. ( Recursive )
{
	if ( m == "0" )
	{
		return "1";
	}
	if ( ( m[m.size() - 1] - '0' ) & 1 )
	{
		string temp = bigPow( n, bigDiv( m, "2" ) );
		return bigMul( bigMul( n, temp ), temp );
	}
	else
	{
		string temp = bigPow( n, bigDiv( m, "2" ) );
		return bigMul( temp, temp );
	}
}

string bigPow( string n, int m ) // Returns n^m.. ( Iterative )
{
	if ( m == 0 )
	{
		return "1";
	}
	if ( m & 1 )
	{
		string temp = bigPow( n, m >> 1 );
		return bigMul( bigMul( n, temp ), temp );
	}
	else
	{
		string temp = bigPow( n, m >> 1 );
		return bigMul( temp, temp );
	}
}

int main()
{
	int t;
	cout << "Enter number of test cases - ";
	cin >> t;
	while ( t-- )
	{
		string n, m;
		cout << "Enter 2 numbers..\n";
		cin >> n >> m;

		cout << "1.Add\n2.Substract\n3.Multiply\n4.Divide\n5.Mod\n6.Power\n7.Power_Int\n";
		char option;
		cin >> option;

		if ( option == '1' )
		{
			cout << bigAdd( n, m ) << "\n";
		}
		else if ( option == '2' )
		{
			cout << bigSubtract( n, m ) << "\n";
		}
		else if ( option == '3' )
		{
			cout << bigMul( n, m ) << "\n";
		}
		else if ( option == '4' )
		{
			cout << bigDiv( n, m ) << "\n";
		}
		else if ( option == '5' )
		{
			int mInt = atoi( m.c_str() );
			cout << bigMod( n, mInt ) << "\n";
		}
		else if ( option == '6' )
		{
			cout << bigPow( n, m ) << "\n";
		}
		else if ( option == '7' )
		{
			int mInt = atoi( m.c_str() );
			cout << bigPow( n, mInt ) << "\n";
		}
		else
		{
			cout << "Invalid Option!!\n";
			exit( 1 );
		}
	}

}
