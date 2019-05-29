#include "ratedtabtenn0.h"
#include "tabtenn0.h"

#include <iostream>

/**
 * 子类构造之前首先要创建基类对象，可以指定调用的基类构造函数，如果不指定，则使用默认的基类构造函数
 */ 
RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) 
    : TableTennisPlayer(fn, ln, ht){

    rating = r;
}

/**
 * 这个不是复制构造函数,但是调用了基类的复制构造函数
 * 虽然基类没有定义复制构造函数，采用的是编译器默认生成的
 */ 
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) 
    :TableTennisPlayer(tp) {
    rating =r;
}

