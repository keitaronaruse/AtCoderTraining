/*
    ABC232 Problem B
        https://atcoder.jp/contests/abc232
        Author: Keitaro Naruse
        Date:   2021-12-19
        MIT License
*/

// # Solution
// - 

#include <iostream>
#include <string>

int main()
{
    //  Constannt
    const int K = 26;

    //  Read S and T
    std::string S, T; 
    std::cin >> S >> T;
    // std::cerr << S << std::endl << T << std::endl; 

    for( int k = 0; k < K; k++ ) {
        int isYesK = true;
        for( int i = 0; i < S.size(); i ++ ) {
            int s = ( ( S.at( i ) - 'a' ) + k ) % K;
            int t = T.at( i ) - 'a';
            // std::cerr << s << " " << t << std::endl;
            if( s != t ) {
                isYesK = false;
                break;
            }
        }
        if( isYesK ) {
            std::cout << "Yes" << std::endl;
            return( 0 );
        }

    }

    //  Display result
    std::cout << "No" << std::endl;
    
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
