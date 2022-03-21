/**
* @file abc229-b.cpp
* @brief ABC229 Problem B - Hard Calculation
* @author Keitaro Naruse
* @date 2022-03-21
* @copyright MIT License
* @details https://atcoder.jp/contests/abc229/tasks/abc229_b
*/

// # Solution

#include <iostream>

int main()
{
    //  Read A, B = [ 1, 10^18 ]
    long long A, B;
    std::cin >> A >> B;

    //  Main
    const int N = 18;
    long long a = A, b = B;
    bool isHard = false;
    for( int i = 0; i < N; i ++ ) {
        long long ai = a % 10L;
        long long bi = b % 10L;
        if( ai + bi >= 10L ) {
            isHard = true;
            break;
        }
        a = a / 10L;
        b = b / 10L;
    }

    if( isHard ) {
        std::cout << "Hard" << std::endl;
    }
    else {
        std::cout << "Easy" << std::endl;
    }
    //  Finalize
    return( 0 );
}
