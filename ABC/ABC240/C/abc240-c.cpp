/**
* @file abc240-c.cpp
* @brief ABC240 Problem C
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc240/tasks/abc240_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <set>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 100 ] and X = [ 1, 10000 ]
    int N = 0, X = 0;
    std::cin >> N >> X;
    if( Debug ) {
        std::cerr << N << " " << X << std::endl;
    }
    //  Read ai and bi = [ 1, 100 ]
    int sum_a = 0, sum_b = 0;
    std::vector< int > a( N, 0 ), b( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> a.at( i ) >> b.at( i );
        sum_a += a.at( i );
        sum_b += b.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << a.at( i ) << " " << b.at( i ) << std::endl;
        }
        std::cerr << sum_a << " " << sum_b << std::endl;
    }

    //  Main
    bool isYes = false;
    if( sum_a == X || sum_b == X ) {
        isYes = true;
    }
    else if( X < sum_a || sum_b < X ) {
        isYes = false;
    }
    else {
        std::vector< std::set< int > > sum( N );
        sum.at( 0 ).insert( a.at( 0 ) );
        sum.at( 0 ).insert( b.at( 0 ) );
        if( Debug ) {
            for( auto p : sum.at( 0 ) ) {
                std::cerr << p << " ";
            }
            std::cerr << std::endl;
        }
        for( int i = 1; i < N; i ++ ) {
            if( sum.at( i - 1 ).empty() ) {
                isYes = false;
                break;
            }
            else {
                for( auto p : sum.at( i - 1 ) ) {
                    if( p + a.at( i ) <= X ) {
                        sum.at( i ).insert( p + a.at( i ) );
                    }
                    if( p + b.at( i ) <= X ) {
                        sum.at( i ).insert( p + b.at( i ) );
                    }
                }
                if( Debug ) {
                    for( auto p : sum.at( i ) ) {
                        std::cerr << p << " ";
                    }
                    std::cerr << std::endl;
                }
            }
        }
        if( sum.at( N - 1 ).count( X ) == 1 ) {
            isYes = true;
        }
        else {
            isYes = false;
        }
    }

    if( isYes ) {
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
