//
//  GoodsOrder.hpp
//  xinlu
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#ifndef GoodsOrder_hpp
#define GoodsOrder_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//订单状态
typedef enum : int {
    NewOrder = 0,//新建状态 （待支付状态），订单可修改
    HavePaid,//已支付状态 （待发货状态），订单可发货
    Shipped,//已发货状态
} OrderStatus;

//订单内容
typedef struct {
    //如：商品颜色，商品个数，收货地址（包括联系方式）
    string color;
    int count;
    string address;
    
}OrderDetail;


class GoodsOrder {
    
public:
    //构造函数 ----新建一个订单
    GoodsOrder(string color, int count, string address);
    //析构函数 ----订单销毁
    ~GoodsOrder();
    
    //友元类 卖家
    friend class Seller;
    
protected:
    //订单状态
    OrderStatus status;
    //订单详情
    OrderDetail detail;
    
    
public:
    ///订单操作 (买家的操作)
    //修改
    void modifyOrder(string color, int count, string address);
    //付款
    void payForGoods();
    
    //查询订单状态
    void queryOrderStatus();
    
    
    
};

#endif /* GoodsOrder_hpp */

