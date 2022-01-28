/**
* @file abc236-d.cpp
* @brief ABC236 Problem D - Dance
* @author Keitaro Naruse
* @date 2022-01-23, 2022-01-28
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <list>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< std::pair< int, int > >& vp )
{
    for( auto p : vp ) {
        os << "( " << p.first << ", " << p.second << " ) ";
    }
    return( os );
}

namespace nrs {
    bool list_comb( std::vector< int >& comb, const std::vector< int >& len ) 
    {
        int n = comb.size();
        bool next_exist = true;
        
        for( int i = n - 1; i >= 0; i -- ) {
            comb.at( i ) ++;
            if( comb.at( i ) < len.at( i ) ) {
                break;
            }
            else {
                comb.at( i ) = 0;
                if( i == 0) {
                    next_exist = false;
                }
            } 
        }
        return( next_exist );
    }
}

int first_n_available( int n, std::vector< bool >& used )
{
    int k = 0;
    for( size_t i = 0; i < used.size(); i ++ ) {
        if( !used.at( i ) ) {
            if( k == n ) {
                used.at( i ) = true;
                return( i );
            }
            else {
                k ++;
            }
        }
    }
    return( used.size() );
}

int main()
{
    //  Read N = [ 1, 8 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read Aij = [ 0, 2^30 ) 
    std::vector< std::vector< int > > A( 2 * N, std::vector< int >( 2 * N, -1 ) );
    for( int i = 0; i < 2 * N - 1; i ++ ) {
        for( int j = i + 1; j < 2 * N; j ++ ) {
            std::cin >> A.at( i ).at( j );
            // A.at( j ).at( i ) = A.at( i ).at( j );
        }
    }
    if( Debug ) {
        for( int i = 0; i < 2 * N; i ++ ) {
            for( int j = 0; j < 2 * N; j ++ ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    std::vector< int > max_value( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        max_value.at( i ) = 2 * ( N - i ) - 1;
    }
    
    std::vector< int > digits( N ); 
    int max_sum_fun = 0;
    do {
        std::list< int > waiting;
        for( int i = 0; i < 2 * N; i ++ ) {
            waiting.push_back( i );
        }
        std::vector< bool > used( 2 * N, false );
        std::vector< std::pair< int, int > > pair( N );
        int sum_fun = 0;
        for( int i = 0; i < N; i ++ ) {
            pair.at( i ).first = first_n_available( 0, used );
            pair.at( i ).second = first_n_available( digits.at( i ), used );
            sum_fun ^= A.at( pair.at( i ).first ).at( pair.at( i ).second );
            if( Debug ) {
                std::cout << "(" << pair.at( i ).first << ", " << pair.at( i ).second << ") ";
            }
        }
        if( Debug ) {
            std::cerr << pair << sum_fun << std::endl;
        }
        max_sum_fun = std::max( max_sum_fun, sum_fun );
    } while( nrs::list_comb( digits, max_value ) );

    //  Display the result
    std::cout << max_sum_fun << std::endl; 
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
