#include<iostream>
#include<random>
#include<GA.h>
#include<algorithm>
#include<array>

constexpr int GENOM_LENGTH = 100;
constexpr int MAX_GENOM_LIST = 100;
constexpr int MAX_GENERATION = 40;
constexpr int SELECT_GENOM = 20;
constexpr double INDIVIDUAL_MUTATION = 0.01;
constexpr double GENOM_MUTATION = 0.01;

Genom& createGenom(length){
    std::array<int, length> genom_list;
    for(const auto& genom : genom_list){
        //0, 1をランダムで生成
        std::mt19937 mt(std::random_device{}());
        //一様分布関数
        std::uniform_int_distribution<int> dist(0, 1);
        genom = (dist(mt));
    }
    return Genom(genom_list);
}

//評価関数
double evaluation(Genom &ga){
    std::array<int, length> genom_list = ga.getGenom();
    double genom_total = static_cast<double>(std::accumulate(genom_list, genom_list + genom_list.size(), 0));
    return genom_total / genom_list.size();
}

//選択関数
Genom& select(Genom(&ga)[num], elite_length){
    std::sort(ga.begin(), ga.end(), [](const Genom& lGenom, const Genom& rGenom){return lGenom > rGenom;})
    std::array<Genom, elite_length> resultGenom;
    for(int i = 0; i < elite_length; ++i){
        resultGenom[i] = ga[i];
    }
    return result;
}

//交叉関数
Genom& crossover(ga_first, ga_second){
    Genom child_genom();
    //二点交叉を行う
}

