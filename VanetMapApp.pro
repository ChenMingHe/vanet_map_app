#-------------------------------------------------
#
# Project created by QtCreator 2012-07-26T16:44:29
#
#-------------------------------------------------

QT       += core gui network xml

TARGET = VanetMapApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DataAnalyticSystem/indataanalytic.cpp \
    Infomation/locallocationinfomation.cpp \
    Message/ConcreteMessage/nolocationmessage.cpp \
    Socket/udpserver.cpp \
    Socket/udpsender.cpp \
    Socket/tcpserver.cpp \
    Socket/tcpsender.cpp \
    Widget/testwidget.cpp \
    Widget/ConversationDialog/conversationwidget.cpp \
    Widget/Menu/settingdialog.cpp \
    Widget/Menu/settingargument.cpp \
    Widget/Menu/listenportdialog.cpp \
    Widget/Menu/graphicsviewsetting.cpp \
    Widget/Menu/graphicssettingargumeng.cpp \
    Widget/Menu/connecttionargument.cpp \
    Widget/Menu/connectdialog.cpp \
    Widget/MultiMediaWidget/mudiamediawidget.cpp \
    Widget/PhotoWall/photowall.cpp \
    Widget/TestWidget/vanettestwidget.cpp \
    Widget/TestWidget/testmachine.cpp \
    Widget/TestWidget/rtttestwidget.cpp \
    Widget/TestWidget/bandwidgettestwidget.cpp \
    Widget/VehicleMap/ListWidget/vechiclelistwidget.cpp \
    Widget/VehicleMap/MapWidget/vechiclemapwidget.cpp \
    Widget/VehicleMap/MapWidget/GraphicsArgument.cpp \
    Widget/VehicleMap/MapWidget/VehicleIcon/vechiclemapuser.cpp \
    Widget/VehicleMap/MapWidget/VehicleIcon/vechicleicon.cpp \
    Widget/VehicleMap/MapWidget/VehicleIcon/twinkleicon.cpp \
    Widget/Warring/warringwidget.cpp \
    MessageAnalyticSystem/handlelist.cpp \
    MessageAnalyticSystem/Handle/handletextmessage.cpp \
    MessageAnalyticSystem/Handle/handlerttresponsemessage.cpp \
    MessageAnalyticSystem/Handle/handlenolocationmessage.cpp \
    MessageAnalyticSystem/Handle/handlemediamessage.cpp \
    MessageAnalyticSystem/Handle/handlelocationmessage.cpp \
    MessageAnalyticSystem/Handle/handlehopmessage.cpp \
    MessageAnalyticSystem/Handle/handlebandwidthresponsemessage.cpp \
    MessageAnalyticSystem/Handle/handlepicturerequest.cpp \
    Widget/VehicleMap/MapWidget/Map/mapitem.cpp \
    Test/tcpsendertestunit.cpp \
    Widget/Label/staticlabel.cpp \
    LogSystem/logwriter.cpp \
    Widget/ProgressBar/staticprogressbar.cpp \
    Widget/Statu/statubuttons.cpp \
    Socket/filetrasmitunit.cpp \
    Widget/VehicleMap/ListWidget/Widget/listwidget.cpp \
    Widget/VehicleMap/ListWidget/Widget/stackedwidget.cpp \
    Widget/VehicleMap/ListWidget/vehiclelist.cpp \
    Widget/VehicleMap/MapWidget/Widget/graphicsview.cpp \
    Widget/VehicleMap/MapWidget/Widget/vehicletypemenu.cpp \
    Widget/VehicleMap/MapWidget/Widget/vehiclemap.cpp \
    Widget/VehicleMap/MapWidget/Widget/viewlevel.cpp \
    Widget/VehicleMap/MapWidget/Widget/levelradiobutton.cpp \
    Widget/VehicleMap/ListWidget/timer.cpp

HEADERS  += mainwindow.h \
    DataAnalyticSystem/indataanalytic.h \
    Infomation/locallocationinfomation.h \
    LogSystem/logwriter.h \
    Manager/Manager.h \
    Message/MessageEnum.h \
    Message/message.h \
    Message/ConcreteMessage/textmessage.h \
    Message/ConcreteMessage/selflocationmessage.h \
    Message/ConcreteMessage/rttresponsemessage.h \
    Message/ConcreteMessage/nolocationmessage.h \
    Message/ConcreteMessage/multimediamessage.h \
    Message/ConcreteMessage/locationmessage.h \
    Message/ConcreteMessage/hopmessage.h \
    Message/ConcreteMessage/emergencyvehiclemessage.h \
    Message/ConcreteMessage/distancelocationmessage.h \
    Message/ConcreteMessage/dangermessage.h \
    Message/ConcreteMessage/bandwidthresponsmessage.h \
    Socket/udpserver.h \
    Socket/udpsender.h \
    Socket/tcpserver.h \
    Socket/tcpsender.h \
    Widget/testwidget.h \
    Widget/ConversationDialog/conversationwidget.h \
    Widget/Menu/settingdialog.h \
    Widget/Menu/settingargument.h \
    Widget/Menu/listenportdialog.h \
    Widget/Menu/graphicsviewsetting.h \
    Widget/Menu/graphicssettingargumeng.h \
    Widget/Menu/connecttionargument.h \
    Widget/Menu/connectdialog.h \
    Widget/MultiMediaWidget/mudiamediawidget.h \
    Widget/PhotoWall/photowall.h \
    Widget/TestWidget/vanettestwidget.h \
    Widget/TestWidget/testmachine.h \
    Widget/TestWidget/rtttestwidget.h \
    Widget/TestWidget/bandwidgettestwidget.h \
    Widget/VehicleMap/ListWidget/vechiclelistwidget.h \
    Widget/VehicleMap/MapWidget/vechiclemapwidget.h \
    Widget/VehicleMap/MapWidget/GraphicsArgument.h \
    Widget/VehicleMap/MapWidget/VehicleIcon/vechiclemapuser.h \
    Widget/VehicleMap/MapWidget/VehicleIcon/vechicleicon.h \
    Widget/VehicleMap/MapWidget/VehicleIcon/twinkleicon.h \
    Widget/Warring/warringwidget.h \
    MessageAnalyticSystem/OperationsEnum.h \
    MessageAnalyticSystem/handler.h \
    MessageAnalyticSystem/handlelist.h \
    MessageAnalyticSystem/ComponentEnum.h \
    MessageAnalyticSystem/Handle/handletextmessage.h \
    MessageAnalyticSystem/Handle/handlerttresponsemessage.h \
    MessageAnalyticSystem/Handle/handlenolocationmessage.h \
    MessageAnalyticSystem/Handle/handlemediamessage.h \
    MessageAnalyticSystem/Handle/handlelocationmessage.h \
    MessageAnalyticSystem/Handle/handlehopmessage.h \
    MessageAnalyticSystem/Handle/handlebandwidthresponsemessage.h \
    Message/ConcreteMessage/picturerequestmessage.h \
    MessageAnalyticSystem/Handle/handlepicturerequest.h \
    Widget/VehicleMap/MapWidget/Map/mapitem.h \\
    Test/tcpsendertestunit.h \
    Widget/Label/staticlabel.h \
    Widget/ProgressBar/staticprogressbar.h \
    Widget/Statu/statubuttons.h \
    MessageAnalyticSystem/Handlers.h \
    Message/Messages.h \
    Socket/Sockets.h \
    Widget/Menu/Settings.h \
    Socket/filetrasmitunit.h \
    Widget/VehicleMap/ListWidget/Widget/listwidget.h \
    Widget/VehicleMap/ListWidget/Widget/stackedwidget.h \
    Widget/VehicleMap/ListWidget/vehiclelist.h \
    Widget/VehicleMap/MapWidget/Widget/graphicsview.h \
    Widget/VehicleMap/MapWidget/Widget/vehicletypemenu.h \
    Widget/VehicleMap/MapWidget/Widget/vehiclemap.h \
    Widget/VehicleMap/MapWidget/Widget/viewlevel.h \
    Widget/VehicleMap/MapWidget/Widget/levelradiobutton.h \
    Widget/VehicleMap/ListWidget/timer.h

FORMS    += mainwindow.ui \
    Widget/testwidget.ui \
    Widget/ConversationDialog/conversationwidget.ui \
    Widget/Menu/settingdialog.ui \
    Widget/Menu/listenportdialog.ui \
    Widget/Menu/graphicsviewsetting.ui \
    Widget/Menu/connectdialog.ui \
    Widget/MultiMediaWidget/mudiamediawidget.ui \
    Widget/PhotoWall/photowall.ui \
    Widget/TestWidget/vanettestwidget.ui \
    Widget/TestWidget/rtttestwidget.ui \
    Widget/TestWidget/bandwidgettestwidget.ui \
    Widget/VehicleMap/ListWidget/vechiclelistwidget.ui \
    Widget/VehicleMap/MapWidget/vechiclemapwidget.ui \
    Widget/Warring/warringwidget.ui \
    Widget/Statu/statubuttons.ui \
    Widget/VehicleMap/ListWidget/vehiclelist.ui \
    Widget/VehicleMap/MapWidget/Widget/vehicletypemenu.ui \
    Widget/VehicleMap/MapWidget/Widget/vehiclemap.ui \
    Widget/VehicleMap/MapWidget/Widget/viewlevel.ui

OTHER_FILES += \
    icon/vehicleBroken1.png \
    icon/jiuhuche1.png \
    icon/fangxiangpa1.png \
    icon/daolusigong1.png \
    icon/vehicleBroken1.png \
    icon/vehicleBroken.png \
    icon/single1.png \
    icon/single.png \
    icon/raoxing.png \
    icon/multi.png \
    icon/local.png \
    icon/jiuhuche1.png \
    icon/jiuhuche.png \
    icon/fangxiangpai.png \
    icon/fangxiangpa1.png \
    icon/daolusigong1.png \
    icon/daolusigong.png \
    Pic/12.jpg \
    Pic/11.jpg \
    Pic/10.jpg \
    Pic/9.jpg \
    Pic/8.jpg \
    Pic/7.jpg \
    Pic/6.jpg \
    Pic/5.jpg \
    Pic/4.jpg \
    Pic/3.jpg \
    Pic/2.jpg \
    Pic/1.jpg \
    icon/compass.png
