/*
    Test case generater 02
        large loop case 
        Author: Keitaro Naruse
        Date:   2021-12-13
        MIT License
*/

#include <iostream>

int main()
{
    //  Initialize
    const int N = 10000;
    const int M = 10000;

    //  Main
    std::cout << N << " " << M << std::endl;
    for( int i = 1; i < N; i ++ ) {
        std::cout << i << " " << i + 1 << std::endl;
    }
    std::cout << 1 << " " << N << std::endl;

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
