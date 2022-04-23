/**
* @file abc249-x.cpp
* @brief ABC249 Problem A - Jogging
* @author Keitaro Naruse
* @date 2022-04-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc249/tasks/abc249_a
*/

// # Solution

#include <iostream>

int main()
{
    //  Read A, B, C, D, E, F, X = [ 1, 10^2 ]
    int A, B, C, D, E, F, X;
    std::cin >> A >> B >> C >> D >> E >> F >> X;

    //  Main
    int TakaCycle = X / ( A + C ), TakaRemain = X % ( A + C ); 
    int TakaDist = TakaCycle * A * B + ( ( TakaRemain < A ) ? B * TakaRemain: B * A );

    int AokiCycle = X / ( D + F ), AokiRemain = X % ( D + F );  
    int AokiDist = AokiCycle * D * E + ( ( AokiRemain < D ) ? E * AokiRemain: E * D );

    if( TakaDist > AokiDist ) {
        std::cout << "Takahashi" << std::endl;
    }
    else if( TakaDist < AokiDist ) {
        std::cout << "Aoki" << std::endl;
    }
    else {
        std::cout << "Draw" << std::endl;
    }

    //  Finalize
    return( 0 );
}
