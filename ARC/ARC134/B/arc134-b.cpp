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

const bool Debug = false;

char find_smallest_char( std::map< char, int >& m )
{
    char ch = 'a';
    while( m[ ch ] == 0 ) {
        ch ++;
    }
    return( ch );
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
    std::string s = S;
    //  Analysis: character -> frequency
    std::map< char, int > counters;
    for( int i = 0; i < s.size(); i ++ ) {
        counters[ s.at(i) ] ++;
    }
    if( Debug ) {
        std::cerr << counters << std::endl;
    }
    //  Main
    int l = 0, r = N - 1;
    while( l < r ) {
        //  Find the target character
        char ch = find_smallest_char( counters );
        if( Debug ) {
            std::cerr << ch << " ";
        }
        //  Find r, the tail end
        for( ; r > l; r -- ) {
            if( s.at( r ) == ch ) {
                break;
            }
        }
        //  Find l, the head end
        for( ; l < r; l ++ ) {
            if( s.at( l ) > s.at( r ) ) {
                break;
            }
        }
        if( Debug ) {
            std::cerr << l << " " << r << " " << std::endl;
        }
        //  Swap the characters at l and r
        if( l < r ) {
            std::swap( s.at( l ), s.at( r ) );
            //  Update the counter
            counters[ s.at( l ) ]--;
            counters[ s.at( r ) ]--;
        }
        else {
            break;
        }
        if( Debug ) {
            std::cerr << counters << std::endl;
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
