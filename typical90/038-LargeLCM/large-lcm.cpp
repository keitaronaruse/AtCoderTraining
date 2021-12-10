/*
    038 - Large LCM
        https://atcoder.jp/contests/typical90/tasks/typical90_al
        Author: Keitaro Naruse
        Date:   2021-12-10
        MIT License
*/

// # Solution
//  - GCD by Euclid algorithm
//  - A * B = GCD * LCM
//  - LCM = (A / GCD) * B

#include <iostream>
#include <algorithm>

int main()
{
    //  Constant 1e18
    const long long M = 1000000000000000000LL;
    //  Read A and B
    long long A = 0LL, B = 0LL;
    std::cin >> A >> B;
    //  Debug
    // std::cerr << A << " " << B << std::endl;
    
    //  Main
    //  Find GCD
    long long m = std::max( A, B ), n = std::min( A, B ), r = 0LL, gcd = 0LL, lcm = 0LL;
    while( true ) {
        if( ( r = m % n ) == 0LL ) {
            gcd = n;
            break;
        }
        else {
            m = n;
            n = r;
        }
    }
    //  Debug
    // std::cerr << gcd << std::endl;

    //  Find LCM
    lcm = (A / gcd) * B;
    //  Debug
    // std::cerr << lcm << std::endl;

    if( lcm > M ) {
        lcm = 0LL;
    }
    else if( lcm <= 0LL ) {
        lcm = 0LL;
    }
    else if( lcm < A ) {
        lcm = 0LL;
    }
    else if( lcm < B ) {
        lcm = 0LL;
    }
    
    //  Display result
    if( lcm == 0LL ) {
        std::cout << "Large" << std::endl;
    }
    else {
        std::cout << lcm << std::endl;
    }
    
    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
