/**
* @file arc134-b.cpp
* @brief ARC134 Problem B
* @author Keitaro Naruse
* @date 2022-01-29, 2022-01-30
* @copyright MIT License
* @details https://atcoder.jp/contests/arc134/tasks/arc134_b
*/

// # Solution
// - Double pointers from the head and the tail
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

std::ostream& operator<<( std::ostream& os, const std::map< char, int >& m )
{
    for( auto p : m ) {
        std::cerr << "( " << p.first << ": " << p.second << " )" << " ";
    }
    return( os );
}

char find_smallest_char( std::map< char, int >& m )
{
    char ch = 'a';
    while( m[ ch ] == 0 ) {
        ch ++;
    }
    return( ch );
}

const bool Debug = false;

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
    std::string s = S;
    //  Analysis: character -> frequency
    std::map< char, int > counters;
    for( size_t i = 0; i < s.size(); i ++ ) {
        counters[ s.at(i) ] ++;
    }
    //  Main
    int l = 0, r = N - 1;
    bool is_continue = true;
    while( is_continue ) {
        if( Debug ) {
            std::cerr << counters << std::endl;
        }
        //  Find the target character
        char ch = find_smallest_char( counters );
        if( Debug ) {
            std::cerr << ch << std::endl;
        }
        //  Find r, the tail end
        if( is_continue ) {
            while( s.at( r ) != ch ) {
                if( -- r <= l ) {
                    is_continue = false;
                    break;
                }
            }
        }
        //  Find l, the head end
        if( is_continue ) {
            while( s.at( l ) <= s.at( r ) ) {
                if( ++ l >= r ) {
                    is_continue = false;
                    break;
                }
            }
        }
        //  Swap the characters at l and r
        if( is_continue ) {
            std::swap( s.at( l ), s.at( r ) );
            counters[ s.at( l ) ]--;
            counters[ s.at( r ) ]--;
            r --;
            l ++;
            if( r <= l ) {
                is_continue = false;
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
