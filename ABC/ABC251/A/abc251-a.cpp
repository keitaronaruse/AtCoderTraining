/**
 * @file abc251-a.cpp
 * @brief ABC251 Problem A - Six Characters
 * @author Keitaro Naruse
 * @date 2022-05-14
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc251/tasks/abc251_a
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read | S | = [ 1, 3 ]
    std::string S;
    std::cin >> S;

    //  Main
    std::string answer;
    if( S.size( ) == 1 ) {
        answer = S + S + S + S + S + S;
    } else if( S.size( ) == 2 ) {
        answer = S + S + S;
    } else if( S.size( ) == 3 ) {
        answer = S + S;
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
