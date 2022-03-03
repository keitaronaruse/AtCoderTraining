/**
* @file arc136-a.cpp
* @brief ARC136 Problem A - A ↔ BB
* @author Keitaro Naruse
* @date 2022-02-27
* @copyright MIT License
* @details https://atcoder.jp/contests/arc136/tasks/arc136_a
*/

// # Solution
// - BA -> (BBB) -> AB
// - BB -> A

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read N = [ 1, 2*10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read S
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S <<  std::endl;
    }

    //  Main
    //  First stage 
    std::string tBB;
    int i = 0;
    while( i < S.size() ) {
        if( S.at( i ) == 'A' ) {
            tBB.push_back( 'B' );
            tBB.push_back( 'B' );
            i ++;
        }
        else {
            tBB.push_back( S.at( i ) );
            i ++ ;
        }
    }
    // std::cout << tBB << std::endl;

    //  Second stage 
    std::string tA;
    i = 0;
    while( i < tBB.size() ) {
        if( i < tBB.size() - 1 && tBB.at( i ) == 'B' && tBB.at( i + 1 ) == 'B' ) {
            tA.push_back( 'A' );
            i += 2;
        }
        else {
            tA.push_back( tBB.at( i ) );
            i ++ ;
        }
    }
    std::cout << tA << std::endl;

    // bool is_modified = true;
    // while( is_modified ) {
    //     s = t;
    //     t = "";
    //     is_modified = false;
    //     int i = 0;
    //     while( i < s.size() ) {
    //         if( i < s.size() - 1 && s.at( i ) == 'B' && s.at( i + 1 ) == 'A' ) {
    //             t.push_back( 'A' );
    //             t.push_back( 'B' );
    //             is_modified = true;
    //             i += 2;
    //         }
    //         else if( i < s.size() - 1 && s.at( i ) == 'B' && s.at( i + 1 ) == 'B' ) {
    //             t.push_back( 'A' );
    //             is_modified = true;
    //             i += 2;
    //         }
    //         else {
    //             t.push_back( s.at( i ) );
    //             i ++ ;
    //         }
    //     }
    // }
    // std::cout << t << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
