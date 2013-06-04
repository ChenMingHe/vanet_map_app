#ifndef MANAGER_H
#define MANAGER_H

#include <QMap>

template <class T>
class Manager {
public:
    T* get(const QString &name) {
       typename QMap<QString, T*>::iterator itr = iMap.find(name);
        if (itr != iMap.end())
            return itr.value();
        return NULL;
    }

    T* add(const QString &name, T* item) {
        typename QMap<QString, T*>::iterator itr = iMap.find(name);
        if (itr != iMap.end())
            return itr.value();

        iMap.insert(name, item);
        iList.push_back(item);
        return item;
    }

    QList<T*> &getAll() {return iList;}

    bool has(const QString &name) {
        if (iMap.find(name) != iMap.end())
            return true;
        return false;
    }

private:
    QMap<QString, T*> iMap;
    QList<T*> iList;
};


#endif // MANAGER_H
