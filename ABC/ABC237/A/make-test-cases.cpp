/*    
* @file make-test-cases.cpp
* @file make test cases for abc237-a.cpp
* @brief ABC237 Problem A - Not Overflow
* @author Keitaro Naruse
* @date 2022-01-30, 2022-02-02
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_a
*/

#include <iostream>
#include <random>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< long long > dist; 
    const long long max_value = 1LL << 63LL - 1LL; 
    const signed long long min_value = - max_value - 1LL;
    dist = std::uniform_int_distribution< long long >( min_value, max_value );
    const long long N = dist( engine );
    std::cout << N << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
