/**
 * @file arc145-a.cpp
 * @brief ARC145 Problem A - AB Palindrome
 * @author Keitaro Naruse
 * @date 2022-07-30
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc145/tasks/arc145_a
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read N = [ 2, 2*10^5 ]
    int N;
    std::cin >> N;

    //  Read | S | = [ N ]
    std::string S;
    std::cin >> S;

    //  Main
    bool answer = true;
    if( N == 2 ) {
        if( S.at( 0 ) == S.at( N - 1 ) ) {
            answer = true;
        } else {
            answer = false;
        }
    } else {
        if( S.at( N - 1 ) == 'A' ) {
            answer = true;
        } else if( S.at( N - 1 ) == 'B' && S.at( 0 ) == 'B' ) {
            answer = true;
        } else {
            answer = false;
        }
    }
    if( answer ) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return ( 0 );
}
