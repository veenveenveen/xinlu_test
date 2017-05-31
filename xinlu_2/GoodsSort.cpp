//
//  GoodsSort.cpp
//  xinlu
//
//  Created by 黄启明 on 2017/5/31.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include "GoodsSort.hpp"
///
bool cmpDefault(const Goods &a, const Goods &b) {
    if (a.discountRate != b.discountRate) {
        return a.discountRate < b.discountRate;
    }
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.price < b.price;
}

void sortDefault(vector<Goods> &vec) {
    sort(vec.begin(), vec.end(), cmpDefault);
}

///
bool cmpByPrice(const Goods &a, const Goods &b) {
    if (a.price != b.price) {
        return a.price < b.price;
    }
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.discountRate < b.discountRate;
}
void sortByPrice(vector<Goods> &vec) {
    sort(vec.begin(), vec.end(), cmpByPrice);
}

