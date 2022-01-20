/**
* @file C-Vacation.cpp
* @brief C - Vacation
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read ai, bi, ci = [ 1, 10^4 ]
    std::vector< int > a( N, 0 ), b( N, 0 ), c( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> a.at( i ) >> b.at( i ) >> c.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << a.at( i ) << " " << b.at( i ) << " " << c.at( i ) << std::endl;
        }
    }

    //  Main
    //  Main::Initialize
    const int K = 3;
    //  dp table: 
    //  - size: K * N = 3 * 10^5 < 10^4
    //  - value: { A, B, C } * N = 10^4 * 10^5 = 10^9 -> int 
    //  - ki, kj = { A, B, C }
    //  - dp_happiness.at( A ).at( i ) is the maximum of 
    //    - dp_happiness.at( B ).at( i - 1 ) + happiness( A ) and 
    //    - dp_happiness.at( C ).at( i - 1 ) + happiness( A )
    //  - dp_happiness.at( B ).at( i ) is the maximum of 
    //    - dp_happiness.at( C ).at( i - 1 ) + happiness( B ) and 
    //    - dp_happiness.at( A ).at( i - 1 ) + happiness( B )
    //  - dp_happiness.at( C ).at( i ) is the maximum of 
    //    - dp_happiness.at( A ).at( i - 1 ) + happiness( C ) and 
    //    - dp_happiness.at( B ).at( i - 1 ) + happiness( C )
    std::vector< std::vector< int > > dp_happiness( K, std::vector< int >( N, 0 ) );

    //  Initail boundary condition
    //  - dp_happiness.at( a, b, c ).at( 0 ) = a1, b1, c1
    dp_happiness.at( 0 ).at( 0 ) = a.at( 0 );
    dp_happiness.at( 1 ).at( 0 ) = b.at( 0 );
    dp_happiness.at( 2 ).at( 0 ) = c.at( 0 );
    //  Main::Loop
    for( int i = 1; i < N; i ++ ) {
        //  by a from b, c
        dp_happiness.at( 0 ).at( i ) = std::max(
            dp_happiness.at( 1 ).at( i - 1 ), 
            dp_happiness.at( 2 ).at( i - 1 )            
        ) + a.at( i );
        //  by b from c, a
        dp_happiness.at( 1 ).at( i ) = std::max(
            dp_happiness.at( 2 ).at( i - 1 ), 
            dp_happiness.at( 0 ).at( i - 1 )             
        ) + b.at( i );
        //  by c from a, b
        dp_happiness.at( 2 ).at( i ) = std::max(
            dp_happiness.at( 0 ).at( i - 1 ), 
            dp_happiness.at( 1 ).at( i - 1 )             
        ) + c.at( i );
    }
    //  Main::Finalize
    //  Display the result
    std::cout << std::max( 
        std::max( dp_happiness.at( 0 ).at( N - 1 ), dp_happiness.at( 1 ).at( N - 1 ) ),
        dp_happiness.at( 2 ).at( N - 1 ) 
    ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
