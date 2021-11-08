/*
    sample3.cpp
    Test patter genelator 3: N = 1, Ai = -1000
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
    size_t N( 1 );
    std::cout << N << std::endl;

    //  Set and print Ai
    std::vector<int> A( N, 0 );
    A.at(0) = -1000;
    for( size_t i = 0; i != A.size(); ++i ) {
        std::cout << A.at(i) << " ";
    }
    std::cout << std::endl;

    //  Finalize
    return( 0 );
}
