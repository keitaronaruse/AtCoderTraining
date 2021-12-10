/*
    032 - AtCoder Ekiden（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_af
        Author: Keitaro Naruse
        Date:   2021-12-10
        MIT License
*/

// # Solution
// - Couting up all the combinations

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Max cost
    const int max_time = 1000000;
    int min_time = max_time;

    //  Read N and Aij
    int N = 0;
    std::cin >> N;
    //  Debug
    // std::cerr << N << std::endl;
    //  Read Aij
    std::vector< std::vector<int> > A( N + 1, std::vector<int>( N + 1 ) );
    for( int i = 1; i <= N; i ++ ) {
        for( int j = 1; j <= N; j ++ ) {
            std::cin >> A.at( i ).at( j );
            //  Debug
            // std::cerr << A.at( i ).at( j ) << " ";
        }
        //  Debug
        // std::cerr << std::endl;
    } 

    //  Read M and Xi Yi
    int M = 0;
    std::cin >> M;
    //  Debug
    // std::cerr << M << std::endl;
    //  Read Xi, Yi
    std::vector<int> X( M ), Y( M );
    for( int j = 0; j < M; j ++ ) {
        std::cin >> X.at( j ) >> Y.at( j );
        //  Debug
        // std::cerr << X.at( j ) << " " << Y.at( j ) << std::endl;
    }

    //  Main
    std::vector< int > assign( N + 1 );
    for( int i = 1; i <= N; i ++) {
        assign.at( i ) = i;
    }

    bool loop_flag = true;
    while( loop_flag ) {
        int time = 0;
        bool isSatisfied = true;
        for( int i = 1; i < N; i ++ ) {
            for( int j = 0; j < M; j ++ ) {
                if( ( ( X.at( j ) == assign.at( i ) ) && ( Y.at( j ) == assign.at( i + 1 ) ) )
                 || ( ( Y.at( j ) == assign.at( i ) ) && ( X.at( j ) == assign.at( i + 1 ) ) )
                ) {
                    isSatisfied = false;
                    break;
                }
            }
            if( isSatisfied ) {
                time += A.at( assign.at( i ) ).at( i );
            }
        }
        if( isSatisfied ) {
            time += A.at( assign.at( N ) ).at( N );
            if( time < min_time ) {
                min_time = time;
            }
        }
        //  Debug
        // for( int i = 1; i <= N; i ++ ) {
        //     std::cerr << assign.at( i ) << " ";
        // }
        // std::cerr << isSatisfied << " " << time << std::endl;
        loop_flag = std::next_permutation( assign.begin() + 1, assign.end() );
    }

    //  Display result
    if( min_time == max_time ) {
        min_time = -1;
    }
    std::cout << min_time << std::endl;
    
    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
