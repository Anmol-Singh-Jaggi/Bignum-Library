#include<bits/stdc++.h>
#define fastin std::ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

string rand_num(const int& size)
{
    string result((rand()%size)+1,'*');
    result[0]='0'+rand()%9+1;
    for(int i=1; i<(int)result.size(); i++)
    {
        result[i]='0'+rand()%10;
    }
    return result;
}

const int Add=1;
const int Subtract=2;
const int Multiply=3;
const int Divide=4;  // Too slow
const int Mod=5;
const int Power=6;  // Too slow
const int Power_Int=7;  // Too slow

int main()
{
    fastin;
    srand(time(NULL));
    int t=100,i;
    cout<<t*7<<"\n";
    for(i=0; i<t; i++)
    {
        cout<<rand_num(1000)<<" "<<rand_num(1000)<<" "<<Add<<"\n";
    }
    for(i=0; i<t; i++)
    {
        cout<<rand_num(1000)<<" "<<rand_num(1000)<<" "<<Subtract<<"\n";
    }
    for(i=0; i<t; i++)
    {
        cout<<rand_num(1000)<<" "<<rand_num(1000)<<" "<<Multiply<<"\n";
    }
    for(i=0; i<t; i++)
    {
        cout<<rand_num(5)<<" "<<rand_num(10)<<" "<<Divide<<"\n";
    }
    for(i=0; i<t; i++)
    {
        cout<<rand_num(1000)<<" "<<rand_num(8)<<" "<<Mod<<"\n";
    }
    for(i=0; i<t; i++)
    {
        cout<<rand_num(5)<<" "<<rand_num(3)<<" "<<Power<<"\n";
    }
    for(i=0; i<t; i++)
    {
        cout<<rand_num(5)<<" "<<rand_num(3)<<" "<<Power_Int<<"\n";
    }
}
