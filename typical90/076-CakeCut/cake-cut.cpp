/*
    076 - Cake Cut（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bx
        Author: Keitaro Naruse
        Date:   2021-12-23, 2021-12-23 
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    std::cerr << N << std::endl;

    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        std::cerr << A.at( i ) << " ";
    }
    std::cerr << std::endl;
    
    //  Main

    //  Display result
    std::cout << std::endl;

    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
