//
//  main.cpp
//  xinlu_9
//
//  Created by 黄启明 on 2017/5/26.
//  Copyright © 2017年 黄启明. All rights reserved.
//

#include <iostream>
#include <dirent.h>

using namespace std;

void traverseFile(string dirPath);
void traverseDifFile(string dirPath, string str[], int len);

template <class T>

int getArrayLen(T &array){
    return (sizeof(array) / sizeof(array[0]));
}

/*
    运行说明：修改 dirPath 和str[]数组后直接运行程序即可
 */

//要遍历的文件的根目录 运行前检查该目录是否存在
string dirPath = "./";
//文件信息列表 用于检查某目录中与该文件列表中的文件名不同的文件
string str[] = {"aaa.docx","aaa.pdf","aaa.txt"};

int main(int argc, const char * argv[]) {

    
    traverseFile(dirPath);
    
    cout << "与文件信息列表中文件名不同的文件是：" << endl;
    traverseDifFile(dirPath, str, getArrayLen(str));
    return 0;
}

//采用递归的方法输出文件佳下所有的文件名
void traverseFile(string dirPath) {
    struct dirent *dir_p;
    DIR *dir = opendir(dirPath.c_str());
    while ((dir_p = readdir(dir)) != nullptr) {
        if (dir_p->d_type == DT_REG) {
            //文件
            cout << dir_p->d_name << "\t";
        }
        else if (dir_p->d_type == DT_DIR) {
            //文件夹
            string dot = ".";
            string dot_dot = "..";
            string name = dir_p->d_name;
            if (name == dot || name == dot_dot) {
                continue;
            }
            string newDirPath = dirPath + "/" + name;
            traverseFile(newDirPath);
        }
    }
    cout << endl;
    
    closedir(dir);
}

//输出和文件信息列表中文件名不同的文件
void traverseDifFile(string dirPath, string str[], int len) {
    struct dirent *dir_p;
    DIR *dir = opendir(dirPath.c_str());
    int flag = 0;
    while ((dir_p = readdir(dir)) != nullptr) {
        if (dir_p->d_type == DT_REG) {
            //文件
            string name = dir_p->d_name;
            
            for (int i = 0; i < len; i++) {
                if (name == str[i]) {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0) {//说明没有找到
                cout << dir_p->d_name << "\t";
            }
            
            flag = 0;
        
        }
        else if (dir_p->d_type == DT_DIR) {
            //文件夹
            string dot = ".";
            string dot_dot = "..";
            string name = dir_p->d_name;
            if (name == dot || name == dot_dot) {
                continue;
            }
            string newDirPath = dirPath + "/" + name;
            traverseDifFile(newDirPath, str, len);
        }
    }
    cout << endl;
    
    closedir(dir);
}
