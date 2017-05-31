//
//  Seller.cpp
//  xinlu
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include "Seller.hpp"

void Seller::deliverGoods(GoodsOrder &order) {
    if (order.status == NewOrder ) {
        cout << "提醒：买家还未完成付款，不能发货!" << endl;
    }
    else if (order.status == HavePaid) {
        //卖家发货。。。
        
        //卖家发货后，订单状态变为 "已发货"
        order.status = Shipped;
        cout << "卖家已发货" << endl;
    }
}

Seller::Seller() {
    
}

Seller::~Seller() {
    
}
