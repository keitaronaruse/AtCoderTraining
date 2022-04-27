/**
* @file arc138-b.cpp
* @brief ARC138 Problem X
* @author Keitaro Naruse
* @date 2022-04-09, 2022-04-28
* @copyright MIT License
* @details https://atcoder.jp/contests/arc138/tasks/arc138_b
*/

// # Solution
// - First: the inverse operation of B
//   - Delete 0s at the tail
// - Second: the inverse operation of A
//   - Delete 0 at the head and flip the rest
//   - Repeat the above operation until 1 appers at the head 
// - If the sequence is empty, return Yes
// - If the sequence is not (including 1), return No

#include <iostream>
#include <vector>
#include <algorithm>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
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
