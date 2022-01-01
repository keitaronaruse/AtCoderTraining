/*
    032 - AtCoder Ekiden（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_af
        Author: Keitaro Naruse
        Date:   2021-12-10, 2022-01-01
        MIT License
*/

// # Solution
// - Couting up all the combinations

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Max cost
    const int max_time = 1000000;
    int min_time = max_time;

    //  Read N and Aij
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Aij
    std::vector< std::vector<int> > A( N, std::vector<int>( N, 0 ) );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            std::cin >> A.at( i ).at( j );
            if( Debug ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
        }
        if( Debug) {
            std::cerr << std::endl;
        }
    } 

    //  Read M and Xi Yi
    int M = 0;
    std::cin >> M;
    if( Debug ) {
        std::cerr << M << std::endl;
    }
    //  Read Xi, Yi
    std::vector< std::vector< bool > > constraints( N, std::vector< bool >( N, true ) );
    for( int j = 0; j < M; j ++ ) {
        int X = 0, Y = 0;
        std::cin >> X >> Y;
        if( Debug ) {
            std::cerr << X << " " << Y << std::endl;
        }
        X --;
        Y --;
        constraints.at( X ).at( Y ) = false;
        constraints.at( Y ).at( X ) = false;
    }

    //  Main
    std::vector< int > assign( N );
    for( int i = 0; i < N; i ++ ) {
        assign.at( i ) = i;
    }

    bool loop_flag = true;
    while( loop_flag ) {
        int time = 0;
        bool isSatisfied = true;
        for( int i = 0; i < N - 1; i ++ ) {
            isSatisfied = constraints.at( assign.at( i ) ).at( assign.at( i + 1 ) );
            if( isSatisfied ) {
                time += A.at( assign.at( i ) ).at( i );
            }
            else {
                break;
            }
        }
        if( isSatisfied ) {
            time += A.at( assign.at( N - 1 ) ).at( N - 1 );
            min_time = std::min( time, min_time ); 
        }
        if( Debug ) {
            for( int i = 0; i < N; i ++ ) {
                std::cerr << assign.at( i ) << " ";
            }
            std::cerr << isSatisfied << " " << time << std::endl;
        }
        loop_flag = std::next_permutation( assign.begin(), assign.end() );
    }

    //  Display result
    if( min_time == max_time ) {
        min_time = -1;
    }
    std::cout << min_time << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
