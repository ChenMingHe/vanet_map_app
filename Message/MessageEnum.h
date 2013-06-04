#ifndef MESSAGEENUM_H
#define MESSAGEENUM_H
namespace Message {
enum Type {
    UNKNOW = 0,
    SELF_LOCATION,
    DISTANCE_LOCATION,
    WARRING,
    DANGER,
    TEXT,
    PICTURE,
    VOICE,
    NOLOCATION,
    BANDWIDTH,
    RTT,
    HOP,
    EMERGENCY_VEHICLE,
    PICTURE_REQUEST
};
}
#endif // MESSAGEENUM_H
