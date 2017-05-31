//
//  GoodsOrder.cpp
//  xinlu
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include "GoodsOrder.hpp"
//新建
GoodsOrder::GoodsOrder(string color, int count, string address) {
    //新建一个订单后 订单状态为 "新建",颜色，个数和地址在创建时指定，此时，用户可以修改订单
    status = NewOrder;
    detail.color = color;
    detail.count = count;
    detail.address = address;
    cout << "您购买的商品颜色为:" << detail.color << ",个数:" << detail.count << ",收货地址为:" << detail.address << endl ;
}

GoodsOrder::~GoodsOrder() {
    
}
//修改
void GoodsOrder::modifyOrder(string color, int count, string address) {
    if (status == NewOrder) {
        detail.color = color;
        detail.count = count;
        detail.address = address;
        cout << "订单修改完成！" << endl;
    }
    else if (status == HavePaid || status == Shipped) {
        cout << "提醒：订单已经付款，不可修改！" << endl;
    }
    
}
//支付
void GoodsOrder::payForGoods() {
    if (status == NewOrder) {
        //支付操作 。。。。。买家支付
        
        //订单支付后 订单状态变为 "已支付"
        status = HavePaid;
        cout << "支付完成" << endl;
    }
    else if (status == HavePaid || status == Shipped) {
        cout << "提醒：您已支付过了，无需再支付！" << endl;
    }
    
}
//查询
void GoodsOrder::queryOrderStatus() {
    switch (status) {
        case NewOrder:
            cout << "您已下单，请付款！" << endl;
            break;
        case HavePaid:
            cout << "订单已付款，卖家准备发货！" << endl;
            break;
        case Shipped:
            cout << "您的商品已发货！" << endl;
            break;
        
        default:
            break;
    }
}
