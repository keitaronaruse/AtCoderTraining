/**
* @file abc219-a.cpp
* @brief ABC219 Problem D - Between Two Arrays
* @author Keitaro Naruse
* @date 2022-04-14
* @copyright MIT License
* @details https://atcoder.jp/contests/abc219/tasks/abc219_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    //  Const
    const int K = 26;
    //  Read | X | = 26
    std::string X;
    std::cin >> X;
    //  Read N = [ 2, 5*10^4 ]
    int N;
    std::cin >> N;
    //  Read | Si | = 10
    std::vector< std::string > S( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    } 

    //  Main
    //  Preprocess
    std::vector< int > order( K );
    for( int k = 0; k < K; k ++ ) {
        order.at( X.at( k ) - 'a' ) = k;
    }
    //  Sort
    std::vector< std::string > T = S;
    std::sort( T.begin(), T.end(), 
        [ & ]( const std::string& s, const std::string& t ) {
            int len = std::min( s.size(), t.size() );
            for( int i = 0; i < len; i ++ ) {
                if( s.at( i ) != t.at( i ) ) {
                    return( order.at( s.at( i ) - 'a' ) < order.at( t.at( i ) - 'a' ) );
                }
            }
            return( s.size() < t.size() );
        }  
    );

    for( int i = 0; i < N; i ++ ) {
        std::cout << T.at( i ) << std::endl;
    }

    //  Finalize
    return( 0 );
}
