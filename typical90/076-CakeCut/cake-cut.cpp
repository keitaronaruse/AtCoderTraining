/*
    076 - Cake Cut（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bx
        Author: Keitaro Naruse
        Date:   2021-12-23, 2021-12-24
        MIT License
*/

// # Solution
// - Read Ai and culculate the sum of Ai
// - if Ai > sum/10 Ai = 0
// - blocks are separated by 0

#include <iostream>
#include <vector>
#include <string>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Debug
    // std::cerr << N << std::endl;

    //  Read Ai and culculate the sum of them
    long long sum = 0LL;
    std::vector< long long > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        sum += A.at( i );
        //  Debug
        std::cerr << A.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Preprocess
    //  Mask a values larger than the tenth of the sum
    const long long sum_tenth = sum / 10LL;
    for( int i = 0; i < N; i ++ ) {
        if( A.at( i ) > sum_tenth ) {
            A.at( i ) = 0LL;
        }
        //  Debug
        std::cerr << A.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Make a partial sum table 
    std::vector< long long > sum_table( N, 0LL );
    //  Float over case
    sum = 0LL;
    for( int i = 0; i < N; i ++ ) {
        if( A.at( i ) == 0LL ) {
            sum = 0LL;
        }
        else {
            sum += A.at( i );
            sum_table.at( i ) = sum;
        }
        //  Debug
        std::cerr << sum_table.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Main
    int isYes = false;
    for( int i = 0; i <= N; i ++ ) {
        ;
    }

    //  Display result
    std::string result;
    if( isYes ) {
        result = "Yes";
    }
    else {
        result = "No";
    }
    std::cout << result << std::endl;
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
