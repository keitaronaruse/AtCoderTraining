/*
    ABC231 Problem C - Counting 2
        https://atcoder.jp/contests/abc231/tasks/abc231_c
        Author: Keitaro Naruse
        Date:   2021-12-11
        MIT License
*/

// # Solution
// - Sort give numbers
// - Find a given query by binary search
// - The sum equals to the number of the numbers above the queries

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
        //  Debug
        // std::cout << A.at( i ) << " ";
    }
    //  Debug
    // std::cout << std::endl;

    //  Main
    //  Sort Ai and find x by binary search
    sort( A.begin(), A.end() );

    //  Read xj
    int x = 0;
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> x;
        auto it = std::lower_bound( A.begin(), A.end(), x );
        std::cout << A.end() - it << std::endl;
    }

    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
