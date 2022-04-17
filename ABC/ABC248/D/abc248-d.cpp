/**
* @file abc248-d.cpp
* @brief ABC248 Problem D - Range Count Query
* @author Keitaro Naruse
* @date 2022-04-16, 2022-04-17
* @copyright MIT License
* @details https://atcoder.jp/contests/abc248/tasks/abc248_d
*/

// # Solution

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

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > > & vv )
{
    for( const auto& v : vv )  {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 2*10^5 ]
    int N;
    std::cin >> N;
    //  Read Ai = [ 1, N ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    //  Read Q = [ 1, 2*10^5 ]
    int Q;
    std::cin >> Q;
    //  Read Li, Ri, Xi
    std::vector< int > L( Q ), R( Q ), X( Q );
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> L.at( j ) >> R.at( j ) >> X.at( j );
    }

    //  Main
    //  Preprocess
    //  Stores appearance positions i of value Ai, 1-index
    std::vector< std::vector< int > > val_pos( N + 1 );
    for( int i = 0; i < N; i ++ ) {
        val_pos.at( A.at( i ) ).push_back( i + 1 );
    }
    //  Find the solution
    for( int j = 0; j < Q; j ++ ) {
        //  0, 1, 2, 3
        //  [ 1, 2 ] -> lower_bound( L ), upper_bound( R ) -> [ 0, 2 ] -> 2 - 0 = 2
        std::cout 
            << std::upper_bound( val_pos.at( X.at( j ) ).begin(), val_pos.at( X.at( j ) ).end(), R.at( j ) )
             - std::lower_bound( val_pos.at( X.at( j ) ).begin(), val_pos.at( X.at( j ) ).end(), L.at( j ) )
            << std::endl;
    }

    //  Finalize
    return( 0 );
}
