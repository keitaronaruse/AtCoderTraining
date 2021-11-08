/*
    sample5.cpp
    Test patter genelator 5: N = 10000, Ai = {-1000, 1000 }
    for Maximum sum problem
        in Knapsack DP: https://qiita.com/drken/items/a5e6fe22863b7992efdb
    Author: Keitaro Naruse
    Date:   2021-11-07
    MIT License
*/

#include <iostream>
#include <vector>

int main()
{
    //  Set and print N
    size_t N( 10000 );
    std::cout << N << std::endl;

    //  Set and print Ai
    std::vector<int> A( N, 0 );
    for( size_t i = 0; i != A.size(); i+=2 ) {
        A.at( i )     = -1000;
        A.at( i + 1 ) =  1000;
        std::cout << A.at( i ) << " " << A.at( i + 1 ) << " ";
    }
    std::cout << std::endl;

    //  Finalize
    return( 0 );
}
