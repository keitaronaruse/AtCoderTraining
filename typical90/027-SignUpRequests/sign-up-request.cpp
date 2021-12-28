/*
    027 - Sign Up Requests （★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_x
        Author: Keitaro Naruse
        Date:   2021-11-27, 2021-12-29
        MIT License
*/

//  # Solution
//    - Put a word in a set, which does not allow us dupicated elements
//    - Display if a word has been already in the set when we read it

#include <iostream>
#include <set>
#include <string>

const bool Debug = false;

int main()
{
    //  Initialize
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    //  Read Si and store it in set
    std::set< std::string > user_list;
    for( int i = 0; i < N; i ++ ) {
        std::string account;
        std::cin >> account;
        if( Debug ) {
            std::cerr << account << std::endl;
        }

        //  Investigateif account is new in D 
        if( user_list.count( account ) == 0 ) {
            std::cout << i + 1 << std::endl;
        }
        //  Insert it in the set
        user_list.insert( account );
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
