/*
    022 - Cubic Cake（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_v
        Author: Keitaro Naruse
        Date:   2021-11-27
        MIT License
*/

//  Solution: 
//  - Calculate GCD(the greatest common divider) of A, B, C, which is the size of a unit cube
//  - Find the number of cuts by the unit cube

#include <iostream>

/*
    gcd()
        returns the greatest common divider
*/
long long gcd(long long a, long long b)
{
    long long dividend = a;
    long long divisor = b;
    long long residue = a % b;

    while( residue != 0 ) {
        dividend = divisor;
        divisor = residue;
        residue = dividend % divisor;
        //  Debug
        // std::cerr << residue << std::endl;
    }

    return( divisor );
}

int main()
{
    //  Read A, B, C
    long long A = 0LL, B = 0LL, C = 0LL;
    std::cin >> A >> B >> C;
    //  Debug
    std::cerr << A << " " << B << " " << C << std::endl;

    //  Main
    //  Debug
    std::cerr << A << " " << B << " " << gcd( A, B ) << std::endl;
    std::cerr << B << " " << C << " " << gcd( B, C ) << std::endl;
    std::cerr << C << " " << A << " " << gcd( C, A ) << std::endl;

    std::cerr << C << " " << B << " " << gcd( C, B ) << std::endl;
    std::cerr << B << " " << A << " " << gcd( B, A ) << std::endl;
    std::cerr << A << " " << C << " " << gcd( A, C ) << std::endl;

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
