/**
* @file abc244-x.cpp
* @brief ABC244 Problem X
* @author Keitaro Naruse
* @date 2022-03-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc244/tasks/abc244_x
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
    //  Read N = [ 1, 10^3 ]
    int N = 0;
    std::cin >> N;

    //  Read Ai = [ 0, 10^9 ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Read | S | = [ 1, 10^6 ]
    std::string S = "";
    std::cin >> S;

    //  Main

    //  Finalize
    return( 0 );
}
