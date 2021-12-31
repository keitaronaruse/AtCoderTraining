/*
    002 - Encyclopedia of Parentheses（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_b
        Author: Keitaro Naruse
        Date:   2021-12-02, 2021-12-31
        MIT License
*/

// # Solution
// - Generate strings by the given rules
// - std::set can store the strings in the dictionay order

#include <iostream>
#include <string>
#include <vector>
#include <set>

const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    //  Make right words
    std::vector< std::set< std::string > > words( N + 1 );

    for( int n = 1; n <= N; n ++ ) {
        if( n == 2 ) {
            //  S2
            words.at( n ).insert( "()" );
        }
        else if( n % 2 == 0 ) {
            //  Sn
            //  ( Sn-2 )
            for( const auto& word : words.at( n - 2 ) ) {
                words.at( n ).insert( "(" + word + ")" );
            }
            //  Sk Sn-k, k = 2, 4, n-2
            for( int k = 0; k <= n - 2; k += 2 ) {
                for( const auto& word_front : words.at( k ) ) {
                    for( const auto& word_back : words.at( n - k ) ) {
                        words.at( n ).insert( word_front + word_back );
                    }
                }
            }
        }
    }

    //  Display result
    for( const auto& e : words.at( N ) ) {
        std::cout << e << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
