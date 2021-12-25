/*
    082 - Counting Numbers（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_cd
        Author: Keitaro Naruse
        Date:   2021-12-25
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>

//  Debug switch
const bool Debug = true;

//  Very large prime number
const long long Large_Prime = 1000000007LL;

int main()
{
    //  Constant

    //  Read L and R
    long long L = 0LL, R = 0LL;
    std::cin >> L >> R;
    if( Debug ) {
        std::cerr << L << " " << R << std::endl;
    }

    //  Main
    long long count = 0LL;
    for( long long i = L; i <= R; i ++ ) {
        std::string digits = std::to_string( i );
        if( Debug ) {
            std::cerr << digits << std::endl;
        }
    }
    //  Display result
    std::cout << count << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
