/**
 * @file abc258-a.cpp
 * @brief ABC258 Problem A - When?
 * @author Keitaro Naruse
 * @date 2022-07-02
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc258/tasks/abc258_a
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read N = [ 0, 100 ]
    int K;
    std::cin >> K;

    //  Main
    std::string answer;
    int k = K;
    if( K < 60 ) {
        answer = "21:";
        k = K;
    }
    else {
        answer = "22:";
        k = K - 60;
    }

    if( k < 10 ) {
        answer += "0";
    }
    answer += std::to_string( k );
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
