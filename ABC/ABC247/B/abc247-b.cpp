/**
* @file abc247-b.cpp
* @brief ABC247 Problem B - Unique Nicknames
* @author Keitaro Naruse
* @date 2022-04-10
* @copyright MIT License
* @details https://atcoder.jp/contests/abc247/tasks/abc247_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    //  Read N = [ 2, 10^2 ]
    int N;
    std::cin >> N;

    //  Read si, ti
    std::vector< std::string > s( N ), t( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> s.at( i ) >> t.at( i );
    }

    //  Main
    //  Preprocess
    std::map< std::string, int > counters;
    for( int i = 0; i < N; i ++ ) {
        counters[ s.at( i ) ] ++;
        counters[ t.at( i ) ] ++;
    }
    //  Find the solution
    int num_duplicates = 0;
    for( auto p : counters ) {
        if( p.second >= 2 ) {
            num_duplicates ++;
        }
    }
    if( num_duplicates <= 1 ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;        ;
    }

    //  Finalize
    return( 0 );
}
