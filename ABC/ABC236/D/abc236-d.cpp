/**
* @file abc236-d.cpp
* @brief ABC236 Problem D - Dance
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}
std::ostream& operator<<( std::ostream& os, const std::vector< std::pair< int, int > >& vp )
{
    for( auto p : vp ) {
        os << "( " << p.first << ", " << p.second << " ) ";
    }
    return( os );
}

class digit_counter {
    public:
        int n;
        std::vector< int > digit;
        std::vector< int > max_value, min_value;
    public:
        digit_counter( int n_ ) : n( n_ ) {
            digit = std::vector< int >( n, 0 );
            max_value = std::vector< int >( n, 0 );
            min_value = std::vector< int >( n, 0 );
            for( int i = 0; i < n; i ++ ) {
                max_value.at( i ) = 2 * ( n - i ) - 1;
            }
        }
        bool next() {
            bool is_available = false;
            for( int i = n - 1; i >= 0; i -- ) {
                digit.at( i ) ++;
                if( digit.at( i ) >= max_value.at( i ) ) {
                    digit.at( i ) = min_value.at( i );
                }
                else {
                    is_available = true;
                    break;
                }
            }
            return( is_available );
        }
};


int first_n_available( int n, std::vector< bool >& used )
{
    int k = 0;
    for( int i = 0; i < used.size(); i ++ ) {
        if( !used.at( i ) ) {
            used.at( i ) = true;
            if( k == n ) {
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

    digit_counter c( N );
    do {
        std::cerr << c.digit << std::endl;
    } while( c.next() );
    
    

    //  Read Aij = [ 0, 2^30 ) 
    // std::vector< std::vector< int > > A( 2 * N, std::vector< int>( 2 * N, -1 ) );
    // for( int i = 0; i < 2 * N - 1; i ++ ) {
    //     for( int j = i + 1; j < 2 * N; j ++ ) {
    //         std::cin >> A.at( i ).at( j );
    //         A.at( j ).at( i ) = A.at( i ).at( j );
    //     }
    // }
    // if( Debug ) {
    //     for( int i = 0; i < 2 * N; i ++ ) {
    //         for( int j = 0; j < 2 * N; j ++ ) {
    //             std::cerr << A.at( i ).at( j ) << " ";
    //         }
    //         std::cerr << std::endl;
    //     }
    // }

    //  Main
    //  N = 1   {0,1}
    //          (0,1)
    //  N = 2   {0,1,2,3}
    //          0(0,1)0(2,3) 1(0,2)0(1,3) 2(0,3)0(1,2)     
    //  N = 3   0(0,1)0(2,3)0(4,5) 0(0,1)1(2,4)0(3,5) 0(0,1)2(2,5)0(3,4)  
    //          1(0,2)0(1,3)0(4,5) 1(0,2)1(1,4)0(3,5) 1(0,2)2(1,5)0(3,4) 
    //          2(0,3)0(1,2)0(4,5) 2(0,3)1(1,4)0(2,5) 2(0,3)2(1,5)0(2,4) 
    //          3(0,4)0(1,2)0(3,5) 3(0,4)1(1,3)0(2,5) 3(0,4)2(1,5)0(2,3) 
    //          4(0,5)0(1,2)0(3,4) 4(0,5)1(1,3)0(2,4) 4(0,5)2(1,4)0(2,3)
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
