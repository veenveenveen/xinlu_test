//
//  main.cpp
//  xinlu_2
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include <iostream>
#include "GoodsSort.hpp"

//输出排序后的结果
void printResult(vector<Goods> &vec);

int main(int argc, const char * argv[]) {

//    int price; 50~100
//    int score; 0~10
//    int discountRate; 0.0~0.9
    
    Goods g1 = {60,4,0.5};
    Goods g2 = {50,5,0.4};
    Goods g3 = {60,5,0.6};
    Goods g4 = {60,4,0.2};
    Goods g5 = {50,4,0.6};
    Goods g6 = {60,6,0.5};
    Goods g7 = {50,6,0.5};
    Goods g8 = {60,4,0.3};
    Goods g9 = {70,3,0.3};
    Goods g10 = {80,7,0.5};
    
    vector<Goods> vec = {g1,g2,g3,g4,g5,g6,g7,g8,g9,g10};
    
    sortDefault(vec);
    printResult(vec);
    
    cout << "-------------------" << endl;
    
    sortByPrice(vec);
    printResult(vec);
    
    
    return 0;
}

void printResult(vector<Goods> &vec) {
    cout << "折扣率" << "\t" << "评分" << " " << "价格" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].discountRate << "\t\t" << vec[i].score << "\t" << vec[i].price << endl;
    }
}
