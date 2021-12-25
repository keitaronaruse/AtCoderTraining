/*
    ABC233 Problem C - Product
        https://atcoder.jp/contests/abc233/tasks/abc233_c
        Author: Keitaro Naruse
        Date:   2021-12-25
        MIT License
*/

// # Solution
// - Greedy, try all combinations

#include <iostream>
#include <vector>

int main()
{
    //  Read N and X
    int N = 0;
    long long X = 0LL;
    std::cin >> N >> X;
    //  Debug
    // std::cerr << N << " " << X << std::endl;

    //  Read Li and Aij
    std::vector< std::vector< int > > A( N );
    std::vector< int > L( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> L.at( i );
        //  Debug
        // std::cerr << L.at( i ) << " ";
        A.at( i ) = std::vector< int >( L.at( i ) );
        for( int j = 0; j < L.at( i ); j ++ ) {
            std::cin >> A.at( i ).at( j );
            //  Debug
            // std::cerr << A.at( i ).at( j ) << " ";
        }
        //  Debug
        // std::cerr << std::endl;
    }

    //  Main
    std::vector< int > combination( N, 0 );
    bool loop_flag = true;
    long long count = 0LL;
    do {
        //  Main
        //  Debug
        // for( auto d : digits ) {
        //     std::cout << d << " ";
        // }
        // std::cout << std::endl;

        //  Find product
        bool valid = true; 
        long long prod = 1LL;
        for( int i = 0; i < N; i ++ ) {
            prod *= ( (long long) A.at( i ).at( combination.at( i ) ) );
            if( prod > X ) {
                valid = false;
                break;
            }
        } 
        if( ( prod == X ) && valid ) {
            count ++;
        }

        //  Find next
        for( int i = 0; i < N; i ++ ) {
            combination.at( i ) ++;
            if( combination.at( i ) < L.at( i ) ) {
                break;
            }
            else {
                //  Carry out
                combination.at( i ) = 0;
            }
        }

        loop_flag = false;
        for( int i = 0; i < N; i ++ ) {
            if( combination.at( i ) != 0 ) {
                loop_flag = true;
                break;
            }
        }
    } while( loop_flag );

    //  Display result
    std::cout << count << std::endl;
    
    return( 0 );
}
