/**
 * @file abc218-a.cpp
 * @brief ABC218 Problem A - Weather Forecast
 * @author Keitaro Naruse
 * @date 2022-04-20
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc218/tasks/abc218_a
 */

// # Solution

#include <iostream>
#include <string>

int main( ) {
    //  Read N = [ 1, 7 ]
    int N;
    std::cin >> N;
    //  Read S
    std::string S;
    std::cin >> S;

    //  Main
    std::string answer;
    if( S.at( N - 1 ) == 'o' ) {
        answer = "Yes";
    } else {
        answer = "No";
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
