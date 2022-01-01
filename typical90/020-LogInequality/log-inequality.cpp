/*
    020 - Log Inequality（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_t
        Author: Keitaro Naruse
        Date:   2021-12-09, 2022-01-01
        MIT License
*/

// # Solution
// - a < c^b

#include <iostream>

const bool Debug = false;

int main()
{
    //  Read A, B, C
    long long A = 0LL, B = 0LL, C = 0LL, R = 1LL; 
    std::cin >> A >> B >> C;
    if( Debug ) {
        std::cerr << A << " " << B << " " << C << std::endl;
    }

    //  Main
    for( long long i = 1LL; i <= B; i ++ ) {
        R *= C;
    }
    //  Display result
    if( A < R ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
