#ifndef SETTINGARGUMENT_H
#define SETTINGARGUMENT_H
#include <stdio.h>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

class SettingArgument
{
public:
    static SettingArgument &Setting();
    void saveSetting();

    void setUdpPort(int port) {udpPort = port;}
    void setTcpPort(int port) {tcpPort = port;}
    void setBWTestTimes(int times) {bwTestTimes = times;}
    void setBWTimeInterval(int interval) {bwTimeInterval = interval;}
    void setBWLowRange(int low) {bwLowRange = low;}
    void setBWUpRange(int up) {bwUpRange = up;}
    void setBWAverageInterval(int interval) {bwAverageInterval = interval;}
    void setRttTestTimes(int times) {rttTestTimes = times;}
    void setRttTimeInterval(int interval) {rttTimeInterval = interval;}
    void setRttLowRange(int low) {rttLowRange = low;}
    void setRttUpRange(int up) {rttUpRange = up;}
    void setRttAverageInterval(int interval) {rttAverageInterval = interval;}
    void setWarringTimeInterval(int raidus) {warringTimeInterval = raidus;}

    const int getUdpPort() const { return udpPort;}
    const int getTcpPort() const {return tcpPort;}
    const int getBWTestTimes() const {return bwTestTimes;}
    const int getBWTimeInterval() const {return bwTimeInterval;}
    const int getBWLowRange() const {return bwLowRange;}
    const int getBWUpRange() const {return bwUpRange;}
    const int getBWAverageInterval() const {return bwAverageInterval;}
    const int getRttTestTimes() const {return rttTestTimes;}
    const int getRttTimeInterval() const {return rttTimeInterval;}
    const int getRttLowRange() const {return rttLowRange;}
    const int getRttUpRange() const {return rttUpRange;}
    const int getRttAverageInterval() const {return rttAverageInterval;}
    const int getWarringInterval() const {return warringTimeInterval;}

private:
    int udpPort;
    int tcpPort;
    int bwTestTimes;
    int bwLowRange;
    int bwUpRange;
    int bwTimeInterval;
    int bwAverageInterval;
    int rttTestTimes;
    int rttTimeInterval;
    int rttLowRange;
    int rttUpRange;
    int rttAverageInterval;
    int warringTimeInterval;

private:
    static SettingArgument *instance;
    SettingArgument();

};

#endif // SETTINGARGUMENT_H
