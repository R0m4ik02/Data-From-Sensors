#ifndef PRIBOR_H
#define PRIBOR_H

#include <QtCore>
#include <QtCharts>
#include <QLineSeries>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtDebug>

enum class FOpenFile{
    CSV,
    JSON,
};

class Sensor{
public:

    Sensor(QString name);
    bool isActive;  // Есть ли график по этому датчику
    QString name;   // Имя датчика
    QVector<QDateTime> times;   // времена измерений
    QVector<double> value;      // измерения
    QXYSeries* series;
    //QLineSeries* series;        // указатель на кривую на графике
};

class Pribor
{
public:

    Pribor(QString name);

    QString name;               // Имя прибора
    QVector<Sensor> sensors;    // Вектор датчиков

    // Временные промежуток на который загружены
    // данные по прибору
    QDateTime begin, end;


    // Функция считает кол-во датчиков по
    // которым построены графики
    int CouASeries();

};

#endif // PRIBOR_H
