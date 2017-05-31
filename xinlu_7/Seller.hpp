//
//  Seller.hpp
//  xinlu
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#ifndef Seller_hpp
#define Seller_hpp

#include <stdio.h>
#include "GoodsOrder.hpp"

class Seller {

public:
    Seller();
    ~Seller();
    
    //发货
    void deliverGoods(GoodsOrder &order);
};

#endif /* Seller_hpp */
