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

const bool Debug = true;

int main()
{
    //  Read N = [ 1, 2 * 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read S
    std::string s;
    std::cin >> s;
    if( Debug ) {
        std::cerr << s << std::endl;
    }

    //  Main
    //  Analysis
    
    //  check no need to swap
    bool is_no_change = true;
    for( int i = 0; i < N - 1; i ++ ) {
        if( s.at( i ) > s.at( i + 1)  ) {
            is_no_change = false;
            break;
        }
    }
    if( is_no_change ) {
        std::cout << s << std::endl;
    }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
