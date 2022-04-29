/**
* @file arc138-b.cpp
* @brief ARC138 Problem B - 01 Generation 
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
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;

    //  Read Ai = [ 0, 1 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    bool is_flipped = false;
    int l = 0, r = N - 1;

    int head = A.at( l ), tail = A.at( r );
    while( l != r ) {
        if( is_flipped ) {
            head = A.at( l ) ^ 1;
            tail = A.at( r ) ^ 1;
        }
        else {
            head = A.at( l );
            tail = A.at( r );
        }
        if( tail == 0 ) {
            r --;
        }
        else if( head == 0 ){
            l ++ ;
            is_flipped = is_flipped ? false : true;
        }
        else {
            break;
        }
    }

    bool isYes = true;
    if( l == r ) {
        isYes = ( head == 0 ) ? true : false;
    }
    else {
        isYes = false;
    }

    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    //  Finalize
    return( 0 );
}
