/**
* @file arc137-b.cpp
* @brief ABC137 Problem B - Count 1's
* @author Keitaro Naruse
* @date 2022-03-19, 2022-03-20
* @copyright MIT License
* @details https://atcoder.jp/contests/arc137/tasks/arc137_b
*/

// # Solution

#include <iostream>
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
    //  Read N = [ 1, 3 * 10^5 ]
    int N = 0;
    std::cin >> N;

    //  Read Ai = [ 0, 1 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    int diff_1_0 = 0, max_diff_1_0 = 0, min_diff_1_0 = 0;
    int curr_0 = 0, curr_1 = 0;

    for( int i = 0; i < N; i ++ ) {
        if( A.at( i ) == 1 ) {
            diff_1_0 ++;
        }
        else if( A.at( i ) == 0 ) {
            diff_1_0 --;
        }
        curr_0 = std::max( curr_0, diff_1_0 - min_diff_1_0 ); 
        curr_1 = std::min( curr_1, diff_1_0 - max_diff_1_0 ); 
        min_diff_1_0 = std::min( diff_1_0, min_diff_1_0 );
        max_diff_1_0 = std::max( diff_1_0, max_diff_1_0 );
    }
    std::cout << curr_0 - curr_1 + 1 << std::endl;

    //  Finalize
    return( 0 );
}
