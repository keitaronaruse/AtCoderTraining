/*
    022 - Cubic Cake（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_v
        Author: Keitaro Naruse
        Date:   2021-11-27, 2021-12-28
        MIT License
*/

//  Solution: 
//  - Calculate GCD(the greatest common divider) of A, B, C, which is the size of a unit cube
//  - Find the number of cuts by the unit cube

#include <iostream>
#include <algorithm>

const bool Debug = false;

namespace nrs {
    long long gcd( long long a, long long b )
    {
        long long dividend = ( a > b )? a : b;
        long long divisor  = ( a > b )? b : a;
        long long residue = dividend % divisor;

        while( residue != 0 ) {
            dividend = divisor;
            divisor = residue;
            residue = dividend % divisor;
        }

        return( divisor );
    }
}

int main()
{
    //  Read A, B, C
    long long A = 0LL, B = 0LL, C = 0LL;
    std::cin >> A >> B >> C;
    if( Debug ) {
        std::cerr << A << " " << B << " " << C << std::endl;
    }

    long long gcd_ab = nrs::gcd( A, B );
    long long gcd_bc = nrs::gcd( B, C );
    long long gcd_ca = nrs::gcd( C, A );
    long long gcd_abc = std::min( std::min( gcd_ab, gcd_bc ), gcd_ca );
    if( Debug ) {
        std::cerr << gcd_ab << " " << gcd_bc << " " << gcd_ca << std::endl;
    }

    //  Calculate and display the number of cuts
    std::cout << ( A / gcd_abc - 1 ) + ( B / gcd_abc - 1 ) + ( C / gcd_abc - 1 ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
