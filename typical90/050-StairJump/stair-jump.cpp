/*
    050 - Stair Jump（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ax
        Author: Keitaro Naruse
        Date:   2021-12-1
        MIT License
*/

// # Solution
// - K = N / L
// - k = [ K::-1::0 ]
//   - i = N - k*L
//   - Find the combination number of putting i among k+1
// - Calulate the combination modulo of m by the inverse element

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

//  Very large Prime
const long long Large_Prime = 1000000007LL;

//  Tables for combination calculation
std::vector< long long > Mod_Factorial;
std::vector< long long > Mod_Inv_Factorial;

/*
    mod_inv()
        returns an inverse element of a in modulo of m
*/
long long mod_inv( long long a, long long m )
{
    long long b = m, u = 1LL, v = 0LL;

    //  Find an inverse element by the extended Euclidean algorithm     
    while( b ) {
        long long t = a / b;
        a -= t * b;
        std::swap( a, b );
        u -= t * v;
        std::swap( u, v );
    }

    //  Taking modulo of m
    u %= m;
    //  Make it a positive number if it is a negative one
    if( u < 0LL ) {
        u += m;
    }

    return( u );
}

/*
    make_factorial_tables()
        makes tables for calculating a combination number
*/
void make_factorial_tables( int N )
{
    //  Make a modulo factorial table and a modulo inverse factorial table  
    Mod_Factorial = std::vector< long long > ( N, 0LL );
    Mod_Inv_Factorial = std::vector< long long > ( N, 0LL );
    
    //  Calculate the tables
    Mod_Factorial.at( 0 ) = 1LL;
    Mod_Inv_Factorial.at( 0 ) =  mod_inv( 1LL, Large_Prime );
    for( int i = 1; i < N; i ++ ) {
        Mod_Factorial.at( i ) 
        = Mod_Factorial.at( i - 1 ) * ( long long ) ( i + 1 ) % Large_Prime;
        Mod_Inv_Factorial.at( i ) 
        = Mod_Inv_Factorial.at( i - 1 ) * mod_inv( i + 1, Large_Prime ) % Large_Prime;
    }
}

/*
    mod_combination()
        returns modulo by the large prime      
*/
long long mod_combination( int n, int k )
{
    long long c = 0LL;
    
    //  Boundary
    if( ( k < 0 ) || ( k > n ) ) {
        c = 0LL;
        return( c );
    }
    else if( ( k == 0 ) || ( k == n ) ) {
        c = 1LL;
        return( c );
    }

    //  Combination number
    c = Mod_Factorial.at( n - 1 );
    c = ( c * Mod_Inv_Factorial.at( k - 1 ) ) % Large_Prime;
    c = ( c * Mod_Inv_Factorial.at( n - k - 1) ) % Large_Prime;
    
    return( c );
}

int main()
{
    //  Initialize
    //  Read N and K
    int N = 0, L = 0; 
    std::cin >> N >> L;
    // std::cerr << N << " " << L << std::endl;
    //  Make a modulo factorial table and a modulo inverse factorial table  
    make_factorial_tables( N );

    //  Main
    long long count = 0LL;
    
    std::cout << count << std::endl;
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
