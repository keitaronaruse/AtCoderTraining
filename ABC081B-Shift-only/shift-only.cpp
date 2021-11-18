/*
    ABC081B Shift only
        https://atcoder.jp/contests/abs/tasks/abc081_b
        Author: Keitaro Naruse
        Date:   2021-11-08
        MIT License
*/

#include <iostream>
#include <vector>

int main()
{
    //  Read N
    size_t N( 0 );
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;

    //  Read Ai
    std::vector< size_t > A( N, 0 );
    for( size_t i = 0; i != N; ++i ) {
        std::cin >> A.at( i );
        //  Debug
        std::cerr << A.at( i ) << " ";
    }
    //  Debug
    std::cerr << std::endl;

    //  Count the number of divisible by 2 for all Ai 
    size_t count(0);
    bool flag = true;
    while(flag) {
        for( size_t i = 0; i != N; ++i ) {
            if( 0 == A.at(i) % 2) {
                A.at(i) /= 2;
            }
            else {
                flag = false;
                break;
            }
        }
        if(flag) {
            count ++;
        }
    }
    
    //  Print the number
    std::cout << count << std::endl;
    
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
