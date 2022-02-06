#include "pribor.h"

Sensor::Sensor(QString n){
    isActive = false;
    name = n;
    series = nullptr;
}

int Pribor::CouASeries(){
    int ret = 0;
    for(auto i: sensors){
        if(i.isActive) ret++;
    }
    return ret;
}

Pribor::Pribor(QString name): name{name} {};

