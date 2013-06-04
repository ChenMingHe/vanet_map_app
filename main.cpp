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

    //初始化图形界面
    MainWindow w;
    w.show();

    //接收模块与分析模块的构建与连接
    UdpServer server(argument.getUdpPort());
    InDataAnalytic ida;
    QObject::connect(&server, SIGNAL(newDataGram(QByteArray&)),
                     &ida, SLOT(doDataAnalytic(QByteArray&)));


    //数据分析模块与过滤器的连接，实现从消息到请求的过滤
    HandleList handle;
    QObject::connect(&ida, SIGNAL(newMessage(AbstractMessage*)),
                     &handle, SLOT(handleMessage(AbstractMessage*)));

    //请求发送到主窗口模块，（注意：主窗口模块的作用是一个拦截器，用于将不同的请求
    //类型拦截下来，然后发送给对应的图形模块进行处理）
    QObject::connect(&handle, SIGNAL(operationRequest(Componet::Name,Operations::Type,AbstractMessage*)),
                     &w, SLOT(doRequest(Componet::Name,Operations::Type,AbstractMessage*)));

    TcpServer tcp;
    return a.exec();
}
