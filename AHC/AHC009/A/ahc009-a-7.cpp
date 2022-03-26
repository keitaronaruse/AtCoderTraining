/**
* @file ahc009-a-7.cpp
* @brief AHC009 Problem A - Robust Memory of Commuting Routes
* @author Keitaro Naruse
* @date 2022-03-26
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc009/tasks/ahc009_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
#include <list>

namespace nrs {
    class multi_digit_counter {
        public:
            size_t n;
            std::vector< int > digit;
            std::vector< int > max_value, min_value;
        public:
            multi_digit_counter( int n_ ) : n( n_ ) {
                digit = std::vector< int >( n, 0 );
                max_value = std::vector< int >( n, 0 );
                min_value = std::vector< int >( n, 0 );
            }
            bool set_max_value( const std::vector< int >& v ) {
                bool is_assignable = ( n == v.size() );
                if( is_assignable ) {
                    max_value = v;
                }
                return( is_assignable ); 
            }
            bool set_min_value( const std::vector< int >& v ) {
                bool is_assignable = ( n == v.size() );
                if( is_assignable ) {
                    min_value = v;
                }
                return( is_assignable ); 
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

    template < class T >
    T abs( T a )
    {
        return( ( a > 0 ) ? a : -a );
    }
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

void simulate( int& x, int& y, const std::vector< int >& actions, 
    const std::vector< std::vector< int > >& h, 
    const std::vector< std::vector< int > >& v, 
    int N 
)
{
    for( int i = 0; i < ( int )actions.size(); i ++ ) {
        for( int k = 0; k < 10; k ++ ) {
            switch( actions.at( i ) ) {
                case 0: //  R
                    if( y < N - 1 && h.at( x ).at( y ) == 0 ) {
                        y ++;
                    }
                break;
                case 1: //  D
                    if( x < N - 1 && v.at( x ).at( y ) == 0 ) {
                        x ++;
                    }
                break;
                case 2: //  R
                    if( 0 < y  && h.at( x ).at( y - 1 ) == 0 ) {
                        y --;
                    }
                break;
                case 3: //  D
                    if( 0 < x && v.at( x - 1 ).at( y ) == 0 ) {
                        x --;
                    }
                break;
            }
        }
    }
}

int main()
{
    //  Constant
    int N = 20;
    //  Read si, sj, = [ 0, 4 ], ti, tj = [ 15, 19 ]
    int si, sj, ti, tj;
    std::cin >> si >> sj >> ti >> tj;
    //  Read p = [ 0.1, 0.5 ]
    double p;
    std::cin >> p;

    //  Read hij = [ 0, 1 ]
    std::vector< std::vector< int > > h( N, std::vector< int >( N - 1, 0 ) ); 
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N - 1; j ++ ) {
            char c;
            std::cin >> c;
            h.at( i ).at( j ) = c - '0';
        }
    }
    //  Read vij = [ 0, 1 ]
    std::vector< std::vector< int > > v( N - 1, std::vector< int >( N, 0 ) ); 
    for( int i = 0; i < N - 1; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            char c;
            std::cin >> c;
            v.at( i ).at( j ) = c - '0';
        }
    }

    //  Main
    const int M = 11;
    std::vector< int > max_value( M, 4 ), min_value( M, 0 );
    
    nrs::multi_digit_counter mdc( M );
    mdc.max_value = max_value;
    mdc.min_value = min_value;

    int min_dist = nrs::abs( si - ti ) + nrs::abs( sj - tj );
    std::vector< int > min_actions;
    do {
        int x = si, y = sj;
        simulate( x, y, mdc.digit, h, v, N );
        int dist = nrs::abs( x - ti ) + nrs::abs( y - tj ); 
        if( dist < min_dist ) {
            min_actions = mdc.digit;
            min_dist = dist;
        }
    } while( mdc.next() );

    const int K = 200;
    std::string actions( K, 'R' ); 
    int k = 0;
    for( int m = 0; m < M; m ++ ) {
        for( int r = 0; r < 10; r ++ ) {
            switch( min_actions.at( m ) ) {
                case 0: actions.at( k ) = 'R';  k ++;  break; 
                case 1: actions.at( k ) = 'D';  k ++;  break; 
                case 2: actions.at( k ) = 'L';  k ++;  break; 
                case 3: actions.at( k ) = 'U';  k ++;  break; 
            }
        }
    }
    for( ; k < K; k ++ ) {
        switch( k % 4 ) {
            case 0: actions.at( k ) = 'R'; break;
            case 1: actions.at( k ) = 'D'; break;
            case 2: actions.at( k ) = 'L'; break;
            case 3: actions.at( k ) = 'U'; break;
            default: break;
        }
    }
    std::cout << actions << std::endl;

    return( 0 );
}
