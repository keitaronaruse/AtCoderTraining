/**
 * @file abc260-a.cpp
 * @brief ABC260 Problem A - A Unique Letter
 * @author Keitaro Naruse
 * @date 2022-07-17
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc260/tasks/abc260_a
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read | S | = [ 3 ]
    std::string S;
    std::cin >> S;

    //  Main
    std::string answer;
    if( S.at( 0 ) == S.at( 1 ) && S.at( 1 ) == S.at( 2 ) ) {
        answer = "-1";
    } else if( S.at( 0 ) == S.at( 1 ) ) {
        answer.push_back( S.at( 2 ) );
    } else if( S.at( 1 ) == S.at( 2 ) ) {
        answer.push_back( S.at( 0 ) );
    } else if( S.at( 2 ) == S.at( 0 ) ) {
        answer.push_back( S.at( 1 ) );
    } else {
        answer.push_back( S.at( 0 ) );
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
