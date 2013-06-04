#ifndef LOCATIONMESSAGE_H
#define LOCATIONMESSAGE_H

#include "Message/message.h"

class LocationMessage : public AbstractMessage
{
public:
    //Warring: need to realize this method
    explicit LocationMessage(QStringList &list) : AbstractMessage(list) {}
    virtual ~LocationMessage() {}
    const QString &getLatitude() {return this->latitude;}
    const QString &getLontitude() {return this->lontitude;}
    const QString &getSpeed() {return this->speed;}
    const QString &getDirect() {return this->direct;}
    const QString &getLicense() {return this->license;}
    const QString &getOthers() {return this->others;}
    double getLatitudeNumber() {return this->latitudeNumber;}
    double getLontitudeNumber() {return this->lontitudeNumber;}
    double getSpeedNumber() {return this->speedNumber;}
    double getDirectNumber() {return this->directNumber;}
    bool isSelfMessage() {return this->isSlef;}
    void changeMessageType(Message::Type type) {this->setMessageType(type);}

private:
    QString latitude;
    QString lontitude;
    QString speed;
    QString direct;
    QString license;
    QString others;
    double latitudeNumber;
    double lontitudeNumber;
    double speedNumber;
    double directNumber;
    bool isSlef;

protected:
    void setLatitude(const QString &latitude) {
        this->latitude = latitude;
        this->latitudeNumber = this->latitude.toDouble();
    }
    void setLontitude(const QString &lontitude) {
        this->lontitude = lontitude;
        this->lontitudeNumber = this->lontitude.toDouble();
    }
    void setSpeed(const QString &speed) {
        this->speed = speed;
        this->speedNumber = this->speed.toDouble();
    }
    void setDirect(const QString &direct) {
        this->direct = direct;
        this->directNumber = this->direct.toDouble();
    }
    void setLicense(const QString &license) { this->license = license;}
    void setOthers(const QString &others) {this->others = others;}
    void setIsSelf(bool self = true) {this->isSlef = self;}
};


#endif // LOCATIONMESSAGE_H
