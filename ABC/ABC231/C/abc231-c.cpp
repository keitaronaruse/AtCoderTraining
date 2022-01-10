/*
    ABC231 Problem C - Counting 2
        https://atcoder.jp/contests/abc231/tasks/abc231_c
        Author: Keitaro Naruse
        Date:   2021-12-11, 2022-01-10
        MIT License
*/

// # Solution
// - Sort give numbers
// - Find a given query by binary search
// - The sum equals to the number of the numbers above the queries

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    if( Debug ) {
        std::cerr << N << " " << Q << std::endl;
    }
    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cout << std::endl;
    }

    //  Main
    //  Sort Ai and find x by binary search
    std::sort( A.begin(), A.end() );

    //  Read xj
    for( int j = 0; j < Q; j ++ ) {
        int x = 0;
        std::cin >> x;
        if( Debug ) {
            std::cerr << x << std::endl;
        }
        std::vector< int >::iterator it = std::lower_bound( A.begin(), A.end(), x );
        std::cout << A.end() - it << std::endl;
    }

    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
