#ifndef OPERATIONSENUM_H
#define OPERATIONSENUM_H

namespace Operations {
enum Type {
    UNKNOW = 0,
    UPDATE_LOCATION,  //���µ�ͼλ����Ϣ
    UPDATE_LIST, //���³�����Ϣ�б�
    APPEND_TEXT,    //�µ��ı�����
    ADD_PICTURE,    //���¶�ý����Ϣ
    UPDATE_RTT,  //����RTT������Ϣ
    UPDATE_BANDWIDTH, //���´�����ʾ��Ϣ
    UPDATE_HOP   //������ʾ��ĵ���������Ϣ
};
}
#endif // OPERATIONSENUM_H
