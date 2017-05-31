//
//  main.cpp
//  xinlu
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "jsoncpp/include/json/json.h"

using namespace std;

int openJsonFile();

//json文件路径
const char *filename = "/Users/himin/Desktop/我的项目/xinlu/xinlu/中国省市区.json";



int main(int argc, const char * argv[]) {
    
    openJsonFile();
    
    return 0;
}

int openJsonFile() {
    
    //从硬盘读取数据到内存
    ifstream ifs;
    
    ifs.open(filename);
    
    if (!ifs.is_open()) {
        cout << "open file fail" << endl;
        return 0;
    }
    
    Json::Reader reader;
    Json::Value root;
    
    if (!reader.parse(ifs, root)) {
        cout << "fail!" << endl;
        return 0;
    }
    
    //定义三个字符串 保存用户选择的省 市 县/区
    string provinceName;
    string cityName;
    string countyName;
    
    ///获取城市数组的个数,打印出所有的省份和直辖市
    int provinceCount = root.size();
    for (int i = 0; i < provinceCount; i++) {
        string name = root[i]["name"].asString();
        if (i == 0) {
            cout << name << endl;
        }
        else {
            cout << i << "." << name << "\t";
        }
    }
    
    cout << endl << "请选择所在地区编号：" << endl;
    
    int province_number = 0;
    while (1) {
        cin >> province_number;
        if (province_number <=0 || province_number >= provinceCount) {
            cout << "输入编号不合法，请重新输入：" << endl;
        }
        else {
            break;
        }
    }
    provinceName = root[province_number]["name"].asString();
    
    if (root[province_number]["type"].asInt() == -1) {//满足条件说明没有下级列表 地区为海外
        cout << "您选择的地区为：";
        cout << provinceName << endl;
        return 1;
    }
    
    ///根据用户选择的省份获取市数组的个数
    int cityCount = root[province_number]["sub"].size();
    for (int i = 0; i < cityCount; i++) {
        string name = root[province_number]["sub"][i]["name"].asString();
        if (i == 0) {
            cout << name << endl;
        }
        else {
            cout << i << "." << name << "\t";
        }
    }
    
    cout << endl << "请选择地区编号：" << endl;
    
    int city_number = 0;
    while (1) {
        cin >> city_number;
        if (city_number <=0 || city_number >= cityCount) {
            cout << "输入编号不合法，请重新输入：" << endl;
        }
        else {
            break;
        }
    }
    cityName = root[province_number]["sub"][city_number]["name"].asString();
    
    if (root[province_number]["type"].asInt() == 0) {//满足条件说明一开始选择的是直辖市
        cout << "您选择的地区为：";
        cout << provinceName << " " << cityName << " " << endl;
        return 1;
    }
    
    ///根据市获取县/区的个数
    int countyCount = root[province_number]["sub"][city_number]["sub"].size();
    for (int i = 0; i < countyCount; i++) {
        string name = root[province_number]["sub"][city_number]["sub"][i]["name"].asString();
        if (i == 0) {
            cout << name << endl;
        }
        else {
            cout << i << "." << name << "\t";
        }
    }
    
    cout << endl << "请选择地区编号：" << endl;
    
    int county_number = 0;
    while (1) {
        cin >> county_number;
        if (county_number <=0 || county_number > countyCount) {
            cout << "输入编号不合法，请重新输入：" << endl;
        }
        else {
            break;
        }
    }
    countyName = root[province_number]["sub"][city_number]["sub"][county_number]["name"].asString();
    
    cout << "您选择的地区为：";
    cout << provinceName << " " << cityName << " " << countyName << " " << endl;
    
    return 1;
}
