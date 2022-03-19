/**
* @file past09-l.cpp
* @brief PAST 9 Problem L - 嘘つきな生徒たち
  @author Keitaro Naruse
* @date 2022-03-18
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_l
*/

#include <iostream>
#include <vector>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( auto k : v ) {
        os << k << " ";
    }
    os << std::endl;
    return( os );
}

int main()
{
    //  N = [ 2, 2 * 10^5 ]
    int N;
    //  P = [ 1, 10^9 ]
    int P;
    std::cin >> N >> P;

    //  Ai = [ 0, P ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    int count = 0;
    for( int i = 0; i < N - 1; i ++ ) {
        if( A.at( i ) <= A.at( i + 1) ) {
            count ++;
        }
    }
    std::cout << count << std::endl;

    return( 0 );
}
