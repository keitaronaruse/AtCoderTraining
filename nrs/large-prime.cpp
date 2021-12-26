/*
    nrs::Large_Prime
        1e9 + 7 as long long
        Author: Keitaro Naruse
        Date:   2021-12-26
        MIT License
*/

namespace nrs {
    //  Very large prime number
    const long long Large_Prime = 1000000007LL;
}

//  Test driver
#include <iostream>

int main()
{
    std::cout << "Large_Prime: "<< nrs::Large_Prime << std::endl;

    return( 0 ); 
}
