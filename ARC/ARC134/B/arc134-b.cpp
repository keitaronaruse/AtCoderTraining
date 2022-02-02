/**
* @file arc134-b.cpp
* @brief ARC134 Problem B - Reserve or Reverse
* @author Keitaro Naruse
* @date 2022-01-29, 2022-02-01
* @copyright MIT License
* @details https://atcoder.jp/contests/arc134/tasks/arc134_b
*/

// # Solution
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, std::map< char, int >& m) 
{
    for( auto p : m ) {
        os << "(" << p.first << "," << p.second << ")"; 
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 2 * 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read S
    std::string S;
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Main
    //  Preprocess: Make alphabet counters
    std::string s = S;
    //  ( alphabet, counts )
    std::map< char, int > counters;
    for( int i = 0; i < N; i ++ ) {
        counters[ s.at( i ) ] ++;
    }
    //  Minimum char
    char min_ch = 'a';
    for( auto p : counters ) {
        if( p.second != 0 ) {
            min_ch = p.first;
            break;
        }
    }
    if( Debug ) {
        std::cerr << counters << min_ch << std::endl;
    }

    //  Main
    int r = N - 1;
    for( int l = 0; l < r; l ++ ) {
        bool not_swapped = true;
        counters[ s.at( l ) ] --;
        for( auto p : counters ) {
            if( p.second != 0 ) {
                min_ch = p.first;
                break;
            }
        }
        if( Debug ) {
            std::cerr << counters << min_ch << std::endl;
        }
        for( char k = min_ch; not_swapped && counters[ k ] != 0 && k < s.at( l ); k ++ ) {
            for( int i = r; i > l; i -- ) {
                if( s.at( i ) == k ) {
                    for( int j = i; j <= r; j ++ ) {
                        counters[ s.at( j ) ] --;
                    }
                    for( auto p : counters ) {
                        if( p.second != 0 ) {
                            min_ch = p.first;
                            break;
                        }
                    }
                    if( Debug ) {
                        std::cerr << counters << min_ch << std::endl;
                    }
                    std::swap( s.at( l ), s.at( i ) );
                    not_swapped = false;
                    r = i - 1;
                    break;
                }
            }
        }
    }
    //  Display the result
    std::cout << s << std::endl;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
