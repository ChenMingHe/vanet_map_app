#ifndef OPERATIONSENUM_H
#define OPERATIONSENUM_H

namespace Operations {
enum Type {
    UNKNOW = 0,
    UPDATE_LOCATION,  //更新地图位置信息
    UPDATE_LIST, //更新车辆信息列表
    APPEND_TEXT,    //新的文本到达
    ADD_PICTURE,    //更新多媒体信息
    UPDATE_RTT,  //更新RTT测试信息
    UPDATE_BANDWIDTH, //更新带宽显示信息
    UPDATE_HOP   //更新显示点的单跳多跳信息
};
}
#endif // OPERATIONSENUM_H
