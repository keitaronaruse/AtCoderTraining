/*
    082 - Counting Numbers（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_cd
        Author: Keitaro Naruse
        Date:   2021-12-25, 2021-12-26
        MIT License
*/

// # Solution
// - Represent a number as string
// - Use the formula of sum for speeding up the calculation by the digits

#include <iostream>
#include <string>

//  Debug switch
const bool Debug = false;

//  Very large prime number
const long long Large_Prime = 1000000007LL;

long long mod_sum( long long l, long long r, int num_digits )
{
    long long a = 0LL, b = 0LL;
    
    if( ( l + r ) % 2LL == 0 ) {
        a = ( ( l + r ) / 2LL ) % Large_Prime;
        b = ( r - l + 1LL ) % Large_Prime;
    }
    else {
        a = ( l + r ) % Large_Prime;
        b = ( r - l + 1LL ) / 2LL % Large_Prime;
    }    
    long long sum = ( a * b ) % Large_Prime;
    sum = ( sum * ( long long ) num_digits ) % Large_Prime;
    
    return( sum );
}

int main()
{
    //  Read L and R
    long long L = 0LL, R = 0LL;
    std::cin >> L >> R;
    if( Debug ) {
        std::cerr << L << " " << R << std::endl;
    }

    //  Main
    long long count = 0LL;

    //  Inspect the size of L and R
    std::string digits_L = std::to_string( L );
    int num_digits_L = digits_L.size(); 
    std::string digits_R = std::to_string( R );
    int num_digits_R = digits_R.size(); 

    for( int k = num_digits_L; k <= num_digits_R; k++ ) {
        long long l = 0LL, r = 0LL;
        //  Both L and R boundary case
        if( ( k == num_digits_L ) && ( k == num_digits_R ) ) {
            l = L;
            r = R;
        }
        //  Only L boundary case
        else if( ( k == num_digits_L ) && ( k != num_digits_R ) ) {
            l = L;
            r = 1LL;
            for( int i = 0; i < k; i ++ ) {
                r *= 10LL;
            }
            r -= 1LL;
        }
        //  Only R boundary case
        else if( ( k != num_digits_L ) && ( k == num_digits_R ) ) {
            l = 1LL;
            for( int i = 0; i < k - 1; i ++ ) {
                l *= 10LL;
            }
            r = R;
        }
        //  Neither L and R are boundary
        else {
            l = 1LL;
            for( int i = 0; i < k - 1; i ++ ) {
                l *= 10LL;
            }
            r = 1LL;
            for( int i = 0; i < k; i ++ ) {
                r *= 10LL;
            }
            r -= 1LL;
        }
        count += mod_sum( l, r, k );
        count %= Large_Prime; 
        if( Debug ) {
            std::cerr << "l: " << l << ", r: " << r << ", sum: " << mod_sum( l, r, k ) << std::endl;
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
