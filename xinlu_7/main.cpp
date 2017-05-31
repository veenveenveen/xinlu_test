//
//  main.cpp
//  xinlu_7
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include <iostream>
#include "GoodsOrder.hpp"
#include "Seller.hpp"

int main(int argc, const char * argv[]) {
    
    //卖家
    Seller oneSeller = Seller();

    //创建一个订单
    GoodsOrder oneOrder = GoodsOrder("红色", 3, "陕西省西安市 联系方式 618888");
    
    //查询订单状态
    oneOrder.queryOrderStatus();
    
    //支付
    oneOrder.payForGoods();
    
    //查询订单状态
    oneOrder.queryOrderStatus();
    
    //卖家发货
    oneSeller.deliverGoods(oneOrder);
    
    //查询订单状态
    oneOrder.queryOrderStatus();
    
    return 0;
}
