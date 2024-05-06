#include<iostream>
#include<random>
#include <unistd.h>


int main()
 {
    float from = 0.1, to = 0.3;
    float sum = 0.0;
    int N = 100;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float>dis(from, to);
    for (int i = 0; i < 100; i++)
    {
        std::cout << dis(gen) <<"\n";
        sleep(dis(gen));
        sum = sum + dis(gen);
    }
    std::cout <<"ans:"<< sum << "\n";
    return 0;
  }
