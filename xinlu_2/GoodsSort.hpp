//
//  GoodsSort.hpp
//  xinlu
//
//  Created by 黄启明 on 2017/5/31.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#ifndef GoodsSort_hpp
#define GoodsSort_hpp

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int price;
    int score;
    double discountRate;
}Goods;

//默认比较：按折扣率的升序排序，然后按评分的降序，价格的升序
bool cmpDefault(const Goods &a, const Goods &b);
//默认排序：折扣率 discountRate
void sortDefault(vector<Goods> &vec);

//根据价格比较：按价格的降序排序，然后按评分的降序，折扣率的升序排序
bool cmpByPrice(const Goods &a, const Goods &b);
//根据价格排序
void sortByPrice(vector<Goods> &vec);

#endif /* GoodsSort_hpp */

//设计一个综合排序模块，要求：
//
//商品有价格、评分、折扣率属性；
//默认排序为：折扣率，相同折扣的按评分、价格依次排序；
//指定一个属性作为优先排序，其他顺序参考默认排序，输出排序后的结果。
