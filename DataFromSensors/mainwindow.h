#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QMainWindow>
#include <QSslSocket>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "pribor.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Read: public QThread {

public:

    Read( QFile& in_, QVector<Pribor> &B, FOpenFile fof = FOpenFile::CSV): in{in_}, B{B}, fof{fof} {};

    QFile& in;
    QVector<Pribor> &B;
    FOpenFile fof;

    // Функция заполняет переданный вектор приборов по строке JSON формата
    bool ReadJson(QString str );

    void run();
};

enum class AverangeMod{
    NoAverange,
    HAverange,
    H4Averange,
    H24Averange,
    AnotherAverange
};

enum class TypeGraph{
    Line, Point
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    // Слот связан с сигналом нажатия на кнопку "Открыть" в меню
    // Заносит данные из файла в программу и выполняет настройку форм
    void on_actionOpen_triggered();

    // Слот связан с сигналами всех ЧБ относящимся к датчикам
    // Строит/удаляет кривую на графике по датчику
    void on_change(bool change);

    void on_change_allChB(bool change);

    // Проверяет корректность введёной даты в формах DateTimeEdit
    void on_dateTime_end_editingFinished();
    void on_dateTime_begin_editingFinished();

    // Слот связан с изменением выбранного прибора в комбобоксе
    void on_comboBox_activated(int index);

    // Слот связанный с получением ответа от запроса по url
    void onResult(QNetworkReply *reply);

    // Слот отчищает данные о приборах
    void on_Clear_triggered();

    //Слот добавляет данные о приборах из выбранного пользователем файла
    void on_addFile_triggered();

    // Слоты устанавливающие режим осреднения значений
    void on_ChB_Wout_Av_clicked(bool checked);
    void on_ChB_H_Av_clicked(bool checked);
    void on_ChB_4H_Av_clicked(bool checked);
    void on_ChB_24H_Av_clicked(bool checked);

    //Слот формирует запрос на сервер для получения данных
    void on_NetRequest_triggered();

    void Fileisreaded();

    void on_MaxY_ValueLine_editingFinished();

    void on_MinY_ValueLine_editingFinished();

    void on_ExportTabe_triggered();

    void on_Menu_export_server_report_triggered();

    void on_ChB_Another_Av_clicked(bool checked);


    void on_ChB_TypeGraph_Line_clicked();

    void on_ChB_TypeGraph_Point_clicked();

private:

    Ui::MainWindow *ui;

    QList<QCheckBox*> sensorsChBs; // Лист чекбоксов
    QVector<Pribor> Pribors;  // Вектор загруженных приборов
    int A_pribor;             // Инкдекс Активного прибора
    AverangeMod avMod;        // Режим осреднения данных
    TypeGraph typeGraph;
    QChart* Chart;            // График
    QDateTimeAxis *xAxis;     // Ось с датами
    QValueAxis *yAxis;        // Ось с величинами
    QNetworkAccessManager *manager; // Менеджер Запросов
    Read* clRead;
    QFile file;

    QImage* brush;


    void Clear();  // Функция отчистки приборов
    void AddSeries(int num_sensor); // Добавление серии на график по номеру датчика
    void ReDraw();                  // Обновление графика
    void AddCheckBox();             // Добавление ЧБ для датчиков прибора
    void SettingPribors();          // Настройка виджетов после открытия файла
    void Set_Enabled(bool b);
    QDateTime SetCorrectDate(QDateTime dt, int num_sens);   // Получение даты по которой есть измерение на датчике



};
#endif // MAINWINDOW_H
