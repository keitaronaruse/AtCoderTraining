/**
* @file arc136-b.cpp
* @brief ARC136 Problem B - Triple Shift
* @author Keitaro Naruse
* @date 2022-02-27, 2022-03-02
* @copyright MIT License
* @details https://atcoder.jp/contests/arc136/tasks/arc136_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int inversion_number( const std::vector< int >& v )
{
    int num = 0;
    for( int l = 0; l < v.size(); l ++ ) {
        for( int r = l + 1; r < v.size(); r ++ ) {
            if( v.at( l ) >= v.at( r ) ) {
                num ++;
            }
        }
    }
    return( num );
}

int main()
{
    //  Read N = [ 3, 5000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Ai
    std::vector< int > A( N, 0 ), a( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        a.at( i ) = A.at( i );
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }
    //  Read Bi
    std::vector< int > B( N, 0 ), b( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
        b.at( i ) = B.at( i );
    }
    if( Debug ) {
        std::cerr << B << std::endl;
    }

    //  Main
    //  Preprocess: Contents check
    std::sort( a.begin(), a.end() );
    std::sort( b.begin(), b.end() );
    for( int i = 0; i < N; i ++ ) {
        if( a.at( i ) != b.at( i )) {
            std::cout << "No" << std::endl;
            return( 0 );
        }
    }

    //  Preprocess: Distinct check
    std::map< int, int > counters;
    for( int i = 0; i < N; i ++ ) {
        counters[ A.at( i ) ] ++;
        if( counters[ A.at( i ) ] > 1 ) {
            std::cout << "Yes" << std::endl;
            return( 0 );
        }
    }

    //  Judge
    int inv_num_a = inversion_number( A );
    int inv_num_b = inversion_number( B );
    if( inv_num_a % 2 == inv_num_b % 2 )  {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
