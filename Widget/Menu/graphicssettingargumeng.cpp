#include "graphicssettingargumeng.h"

GraphicsSettingArgument *GraphicsSettingArgument::instance = NULL;
GraphicsSettingArgument::GraphicsSettingArgument()
{
    if (QFile::exists("GraphicsSetting.xml")) {
        QDomDocument doc("GraphicsSetting");
        QFile file("GraphicsSetting.xml");

        if (!file.open(QIODevice::ReadOnly))
            return;

        if (!doc.setContent(&file)) {
            file.close();
            return;
        }

        QDomElement root = doc.firstChildElement("VANET");
        if (root.isNull())
            return;

        QDomElement perDegreeElement = root.firstChildElement("DistancePerDegreed");
        if (!perDegreeElement.isNull()) {
            QDomElement xper = perDegreeElement.firstChildElement("xPerDegreed");
            QDomElement yper = perDegreeElement.firstChildElement("yPerDegreed");
            if (!xper.isNull()) {
                xPerDegreed = xper.text().toInt();
            }
            if (!yper.isNull()) {
                yPerDegreed = yper.text().toInt();
            }
        }
        QDomElement raudioElement = root.firstChildElement("WarringRaudio");
        if (!raudioElement.isNull()) {
            QDomElement raudio = raudioElement.firstChildElement("Raudio");
            if (!raudio.isNull()) {
                warringRaudio = raudio.text().toInt();
            }
        }        
        QDomElement mapInfo = root.firstChildElement("MapInfomation");
        if (!raudioElement.isNull()) {
            QDomElement toplat = mapInfo.firstChildElement("TopLatidute");
            QDomElement toplon = mapInfo.firstChildElement("TopLontidute");
            QDomElement botmlat = mapInfo.firstChildElement("ButtomLatidute");
            QDomElement botmlon = mapInfo.firstChildElement("ButtomLontidute");
            if (!toplat.isNull()) {
                lat_top = toplat.text().toDouble();
            }
            if (!toplon.isNull()) {
                lon_top = toplon.text().toDouble();
            }
            if (!botmlat.isNull()) {
                lat_buttom = botmlat.text().toDouble();
            }
            if (!botmlon.isNull()) {
                lon_buttom = botmlon.text().toDouble();
            }
        }
        QDomElement viewElement = root.firstChildElement("ViewWidth");
        if (!viewElement.isNull()) {
            QDomElement lv1 = viewElement.firstChildElement("Level1");
            QDomElement lv2 = viewElement.firstChildElement("Level2");
            QDomElement lv3 = viewElement.firstChildElement("Level3");
            QDomElement lv4 = viewElement.firstChildElement("Level4");
            QDomElement lv5 = viewElement.firstChildElement("Level5");
            if (!lv1.isNull()) {
                viewLv1 = lv1.text().toInt();
            }
            if (!lv2.isNull()) {
                viewLv2 = lv2.text().toInt();
            }
            if (!lv3.isNull()) {
                viewLv3 = lv3.text().toInt();
            }
            if (!lv4.isNull()) {
                viewLv4 = lv4.text().toInt();
            }
            if (!lv5.isNull()) {
                viewLv5 = lv5.text().toInt();
            }
        }
        QDomElement deadTimeElement = root.firstChildElement("DeadTime");
        if (!deadTimeElement.isNull()) {
            deadTime = deadTimeElement.text().toInt();
        }
    }
}

void GraphicsSettingArgument::setPerDegree(qreal xper, qreal yper)
{
    xPerDegreed = xper; yPerDegreed = yper;
}

void GraphicsSettingArgument::setWarringRaudio(qreal raudio)
{
    warringRaudio = raudio;
}

void GraphicsSettingArgument::setTopPos(double x, double y)
{
    lat_top = x; lon_top = y;
}

void GraphicsSettingArgument::setButtomPos(double x, double y)
{
    lat_buttom = x; lon_buttom = y;
}

void GraphicsSettingArgument::setViewRectWidth(qreal lv1, qreal lv2, qreal lv3, qreal lv4, qreal lv5)
{
    viewLv1 = lv1;
    viewLv2 = lv2;
    viewLv3 = lv3;
    viewLv4 = lv4;
    viewLv5 = lv5;
}

qreal GraphicsSettingArgument::getViewWidth(int lv) {
    switch (lv) {
    case 1: { return viewLv1; break;}
    case 2: { return viewLv2; break;}
    case 3: { return viewLv3; break; }
    case 4: { return viewLv4; break; }
    case 5: { return viewLv5; break; }
    default: return 50; break;
    }
}

GraphicsSettingArgument &GraphicsSettingArgument::Setting()
{
    if (instance == NULL)
        instance = new GraphicsSettingArgument;
    return *instance;
}

void GraphicsSettingArgument::saveSetting()
{
    QFile file("GraphicsSetting.xml");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;

    QDomDocument doc;
    QDomElement element;


    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml", "version = \"1.0\" encoding=\"GB2312\"");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement("VANET");
    doc.appendChild(root);

    //保存PerDegree
    QDomElement perDegreed = doc.createElement("DistancePerDegreed");
    element = doc.createElement("xPerDegreed");
    element.appendChild(doc.createTextNode(QString::number(xPerDegreed)));
    perDegreed.appendChild(element);
    element = doc.createElement("yPerDegreed");
    element.appendChild(doc.createTextNode(QString::number(yPerDegreed)));
    perDegreed.appendChild(element);
    root.appendChild(perDegreed);

    //保存warringRaudio
    QDomElement warring = doc.createElement("WarringRaudio");
    element = doc.createElement("Raudio");
    element.appendChild(doc.createTextNode(QString::number(warringRaudio)));
    warring.appendChild(element);
    root.appendChild(warring);

    //保存图片信息
    QDomElement mapInfo = doc.createElement("MapInfomation");
    {
        int decpt, sign;
        char *c = ecvt(lat_top, 10, &decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        element = doc.createElement("TopLatidute");
        element.appendChild(doc.createTextNode(s));
        mapInfo.appendChild(element);
//        free(c);
    } {
        int decpt, sign;
        char *c = ecvt(lon_top, 10,&decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        element = doc.createElement("TopLontidute");
        element.appendChild(doc.createTextNode(s));
        mapInfo.appendChild(element);
//        free(c);
    } {
        int decpt, sign;
        char *c = ecvt(lat_buttom, 10, &decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        element = doc.createElement("ButtomLatidute");
        element.appendChild(doc.createTextNode(s));
        mapInfo.appendChild(element);
//        free(c);
    } {
        int decpt, sign;
        char *c = ecvt(lon_buttom, 10, &decpt, &sign);
        QString s(c);
        s.insert(decpt, ".");
        element = doc.createElement("ButtomLontidute");
        element.appendChild(doc.createTextNode(s));
        mapInfo.appendChild(element);
//        free(c);
    }
    root.appendChild(mapInfo);

    //保存视图宽度设置
    QDomElement viewRect = doc.createElement("ViewWidth");
    element = doc.createElement("Level1");
    element.appendChild(doc.createTextNode(QString::number(viewLv1)));
    viewRect.appendChild(element);
    element = doc.createElement("Level2");
    element.appendChild(doc.createTextNode(QString::number(viewLv2)));
    viewRect.appendChild(element);
    element = doc.createElement("Level3");
    element.appendChild(doc.createTextNode(QString::number(viewLv3)));
    viewRect.appendChild(element);
    element = doc.createElement("Level4");
    element.appendChild(doc.createTextNode(QString::number(viewLv4)));
    viewRect.appendChild(element);
    element = doc.createElement("Level5");
    element.appendChild(doc.createTextNode(QString::number(viewLv5)));
    viewRect.appendChild(element);
    root.appendChild(viewRect);

    //DeadTime
    QDomElement deadTimeElement = doc.createElement("DeadTime");
    deadTimeElement.appendChild(doc.createTextNode(QString::number(deadTime)));
    root.appendChild(deadTimeElement);

    QTextStream out( &file );
    doc.save( out, 4 );
}
