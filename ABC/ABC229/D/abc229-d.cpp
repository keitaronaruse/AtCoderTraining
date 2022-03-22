/**
* @file abc229-d.cpp
* @brief ABC229 Problem D - Longest X 
* @author Keitaro Naruse
* @date 2022-03-21
* @copyright MIT License
* @details https://atcoder.jp/contests/abc229/tasks/abc229_d
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read | S | = [ 1, 2 * 10^5 ]
    std::string S;
    std::cin >> S;

    //  Read K = [ 0, 2 * 10^5 ]
    int K;
    std::cin >> K;

    //  Preprocess
    int N = S.size();
    std::vector< int > num_period( N + 1, 0 );
    for( int i = 0; i < N; i ++ ) {
        num_period.at( i + 1 ) = num_period.at( i );
        if( S.at( i ) == '.' ) {
            num_period.at( i + 1 ) ++;
        }
    }

    //  Main
    int r = 0;
    int max_num_X = 0;
    for( int l = 0; l < N; l ++ ) {
        while( r < N && K >= num_period.at( r + 1 ) - num_period.at( l ) ) {
            r ++;
        }
        max_num_X = std::max( max_num_X, r - l ); 
    }
    std::cout << max_num_X << std::endl;

    //  Finalize
    return( 0 );
}
