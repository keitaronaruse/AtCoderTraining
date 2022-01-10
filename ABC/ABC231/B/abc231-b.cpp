/*
    ABC231 Problem B - Election
        https://atcoder.jp/contests/abc231/tasks/abc231_b
        Author: Keitaro Naruse
        Date:   2021-12-11, 2022-01-10
        MIT License
*/

// # Solution
// - Use name as key and the number of votes as value

#include <iostream>
#include <string>
#include <map>

const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read Si and store in map
    std::map< std::string, int > votes;
    for( int i = 0; i < N; i++ ) {
        std::string S;
        std::cin >> S;
        if( Debug ) {
            std::cerr << S << std::endl;
        }
        votes[ S ] ++;
    }
    //  Find max vote
    int max_vote = 0;
    std::string max_name;
    for( const auto& v : votes ) {
        if( v.second > max_vote ) {
            max_name = v.first;
            max_vote = v.second;
        }
    }
    //  Display result
    std::cout << max_name << std::endl;
    
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
