/*
    055 - Select 5（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bc
        Author: Keitaro Naruse
        Date:   2021-11-29
        MIT License
*/

#include <iostream>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;

    //  Make all the patterns of picking up 5 out of N
    int count = 0;
    for( int i = 0; i != N; i ++ ) {
        for( int j = i + 1; j != N; j ++ ) {
            for( int k = j + 1; k != N; k ++ ) {
                for( int l = k + 1; l != N; l ++ ) {
                    for( int m = l + 1; m != N; m ++) {
                        //  Debug
                        // std::cerr << i << " " << j << " " << k << " " << l << " " << m << std::endl;
                        count ++;
                    }
                }

            }
        }
    }

    //  Display 
    //  Debug
    std::cerr << count << std::endl;
    
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
