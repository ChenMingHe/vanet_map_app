#include <QtGui/QApplication>
#include "mainwindow.h"
#include "Socket/udpserver.h"
#include "DataAnalyticSystem/indataanalytic.h"
#include "MessageAnalyticSystem/handlelist.h"
#include "Widget/Menu/settingargument.h"
#include "Socket/tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SettingArgument &argument = SettingArgument::Setting();

    //��ʼ��ͼ�ν���
    MainWindow w;
    w.show();

    //����ģ�������ģ��Ĺ���������
    UdpServer server(argument.getUdpPort());
    InDataAnalytic ida;
    QObject::connect(&server, SIGNAL(newDataGram(QByteArray&)),
                     &ida, SLOT(doDataAnalytic(QByteArray&)));


    //���ݷ���ģ��������������ӣ�ʵ�ִ���Ϣ������Ĺ���
    HandleList handle;
    QObject::connect(&ida, SIGNAL(newMessage(AbstractMessage*)),
                     &handle, SLOT(handleMessage(AbstractMessage*)));

    //�����͵�������ģ�飬��ע�⣺������ģ���������һ�������������ڽ���ͬ������
    //��������������Ȼ���͸���Ӧ��ͼ��ģ����д���
    QObject::connect(&handle, SIGNAL(operationRequest(Componet::Name,Operations::Type,AbstractMessage*)),
                     &w, SLOT(doRequest(Componet::Name,Operations::Type,AbstractMessage*)));

    TcpServer tcp;
    return a.exec();
}
