#include<iostream>
#include<random>
#include<GA.h>
#include<algorithm>
#include<array>
#include<utility>

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
void crossover(Genom &ga[2]){
    Genom child_genom();
    //二点交叉を行う
    std::mu19937 mt{std::random_device{}()};
    std::array<std::uniform_int_distribution<int>, 2> dist(0, 100);
    int range_first = dist[0](mt), range_second = dist[1](mt);
    range_first > range_second ? std::swap(range_first, range_second) : range_first = range_first;
    std::array<std::array<int, range_second - range_first>, 2> crossover_body{};
    std::array<std::array<int, 100>, 2> genom_list = ga.getGenom();
    //二点間のの遺伝子を抽出
    for(int i = 0; i < 2; ++i){
        for(int k = 0; k < (range_second - range_first), ++k){
            crossover_body[i][k] = ga[i][k]; 
        }
    }
    //交叉
    for(int k = 0; k < (range_second - range_first), ++k){
        ga[0][k] = crossover_body[1][k];
        ga[1][k] = crossover_body[0][k];
    }
}

Genom& nextGeneration(Genom &ga, const Genom &ga_elite, const Genom &ga_progeny){
    //エリート主義
    //現行世代個体集団の評価を低い順にソートする
    std::sort(ga.begin(), ga.end(), [](const Genom& lGenom, const Genom& rGenom){return lGenom > rGenom;})
    std::array<Genom next_generation, ga.size()> = ga;
    //追加するエリート集団と子孫集団の合計分を取り除く
    int count{}
    for(count = 0; count < ga_elite.size(); ++count){
        next_generation[i].setGenom(ga_elite[count].getGenom());
    }
    for(; count < (ga_elite.size() + ga_progeny.size()); ++count){
        next_generation[i].setGenom(ga_progeny[count - ga_elite.size().getGenom()]);
    }
    //このままでは返せないstd::unique_ptrを使う
    return next_generation;
}

//突然変異関数(未実装)
void mutation(Genom &ga, double individual_mutation, double genom_mutation){}

int main(){
    
}