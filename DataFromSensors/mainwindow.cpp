#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

#include <QTextStream>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Chart = new QChart();
    xAxis = new QDateTimeAxis;
    yAxis = new QValueAxis;

    xAxis->setTitleText("Time");
    xAxis->show();
    xAxis->setTickCount(5);

    yAxis->setTitleText("Values");
    yAxis->setLabelFormat("%.2f");

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this,SLOT(onResult(QNetworkReply*)));

    //Chart->legend()->show();
    Chart->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);
    ui->graphicsView->setChart(Chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    ui->statusBar->hide();

    brush = new QImage(5, 5, QImage::Format_ARGB32);
    brush->fill(Qt::transparent);

    QPainter painter(brush);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QRgb(0xf6a625));
    painter.setBrush(painter.pen().color());
    painter.drawEllipse(0,0,5,5);

    //painter.drawPath(starPath);

    typeGraph = TypeGraph::Line;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Clear(){

    Pribors.clear();
    ui->comboBox->clear();
    Chart->removeAllSeries();
    QLayoutItem *child;
    while ((child = ui->gridLayout_4->takeAt(0)) != nullptr){
        delete child->widget();     // delete the widget
        delete child;               // delete the layout item
    }

    ui->dateTime_begin->setEnabled(false);
    ui->dateTime_end->setEnabled(false);

}

void MainWindow::on_change(bool change){

    QString str_tmp = dynamic_cast<QCheckBox*>(sender())->objectName();

    int c = str_tmp.split('_')[1].toInt();

    if (change){

         AddSeries(c);

    }
    else{
        Chart->removeSeries(Pribors[A_pribor].sensors[c].series);
        Pribors[A_pribor].sensors[c].isActive = false;
        delete Pribors[A_pribor].sensors[c].series;
        Pribors[A_pribor].sensors[c].series = nullptr;
        ReDraw();
    }
}

void MainWindow::on_change_allChB(bool change){

    QCheckBox *tmp;

    for (auto i = sensorsChBs.begin(); i != sensorsChBs.end();i++) {
        tmp = dynamic_cast<QCheckBox*>(*i);
        tmp->setChecked(change);
    }
}

void MainWindow::AddSeries(int num_sensor){

    // Код ниже меняет линейный график на точечный



    //----------------

    // Код ниже делает линейный граффик



    //-------------
    QXYSeries *Series;

    switch (typeGraph) {
    case TypeGraph::Line:{
        QLineSeries *Series_ = new QLineSeries();
        Series = Series_;
        break;
    }
    case TypeGraph::Point:{
        QScatterSeries *Series_ = new QScatterSeries();
        Series_->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
        Series_->setMarkerSize(5);
        Series_->setBrush(*brush);
        Series_->setPen(QColor(Qt::transparent));
        Series = Series_;
        break;
    }
    }

    QString SerName = Pribors[A_pribor].sensors[num_sensor].name;
    Series->setName(SerName);

    double y_tmp , y_max, y_min, aver;
    int steep_secs, c_dates;
    QDateTime x_tmp,
            x_max,
            x_min,
            correct_dt_begin,
            correct_dt_end,
            discret_date;

    discret_date.setDate(ui->dateTime_begin->dateTime().date());
    switch (avMod) {
    case AverangeMod::NoAverange:{
        steep_secs = 0;
        break;
    }
    case AverangeMod::HAverange:{
        steep_secs = 3600;
        break;
    }
    case AverangeMod::H4Averange:{
        steep_secs = 14400;
        break;
    }
    case AverangeMod::H24Averange:{
        steep_secs = 86400;
        break;
    }

    case AverangeMod::AnotherAverange:{
        int i = ui->lineEdit_Athoter_Averange->text().toInt();
        steep_secs = i*60;
        break;
    }
    }
    correct_dt_begin = SetCorrectDate(ui->dateTime_begin->dateTime(), num_sensor);
    correct_dt_end = SetCorrectDate(ui->dateTime_end->dateTime(), num_sensor);
    c_dates = 0;
    aver = 0;

    for (int i = 0; i < Pribors[A_pribor].sensors[num_sensor].times.length(); i++ ) {

        y_tmp = Pribors[A_pribor].sensors[num_sensor].value[i];
        x_tmp = Pribors[A_pribor].sensors[num_sensor].times[i];

        if(steep_secs == 0){
            Series->append(x_tmp.toMSecsSinceEpoch(), y_tmp); // если нет осреднения
        }
        else{
            // случай когда рассматриваемое время больше промежутка осреднения
            if(discret_date.addSecs(steep_secs) <= x_tmp){
                // если в промежутке нет данных средннее зн неопределенно
                if(c_dates != 0)aver /=c_dates;
                Series->append(discret_date.toMSecsSinceEpoch(), aver);
                Series->append(discret_date.addSecs(steep_secs).toMSecsSinceEpoch(), aver);
                // Новая т.о для участка осреднения
                discret_date = discret_date.addSecs(steep_secs);
                aver = y_tmp;
                c_dates = 1;
            }
            else{
                aver += y_tmp;
                c_dates++;
            }
            // последние данные если не попали в целое кол-во промежутков
            // тоже добавятся на график
            if(Pribors[A_pribor].sensors[num_sensor].times.length()-i == 1){
                if (c_dates!=0)aver /=c_dates;
                Series->append(discret_date.toMSecsSinceEpoch(), aver);
                Series->append(discret_date.addSecs(steep_secs).toMSecsSinceEpoch(), aver);
            }
        }
        // На указанном промежутке времени ищем границы измерений (max, min)
        if(x_tmp >= correct_dt_begin && x_tmp <= correct_dt_end){
            if (x_tmp == correct_dt_begin){
                x_max = x_min = Pribors[A_pribor].sensors[num_sensor].times[i];
                y_max = y_min = Pribors[A_pribor].sensors[num_sensor].value[i];
            }
            x_min = (x_min > x_tmp) ? x_tmp : x_min;
            x_max = (x_max < x_tmp) ? x_tmp : x_max;
            y_min = (y_min > y_tmp) ? y_tmp : y_min;
            y_max = (y_max < y_tmp) ? y_tmp : y_max;
        }

    }

    double d;
    int CouASeries = Pribors[A_pribor].CouASeries();

    if (CouASeries != 0){
        //x_min = (x_min > xAxis->min()) ? xAxis->min() : x_min;
        //x_max = (x_max < xAxis->max()) ? xAxis->max() : x_max;
        d = yAxis->max()-yAxis->min();
        y_min = (y_min > yAxis->min()) ? yAxis->min() : y_min - (0.05 * d);
        y_max = (y_max < yAxis->max()) ? yAxis->max() : y_max + (0.05 * d);

         yAxis->setRange(y_min, y_max);
    }
    else{
        if ( y_min == y_max){
            y_min -=0.01;
            y_max +=0.01;
        }
        d = y_max-y_min;
        yAxis->setRange(y_min-(d*0.05), y_max+(d*0.05));
        //xAxis->setRange(x_min, x_max);
    }

    Pribors[A_pribor].sensors[num_sensor].isActive = true;
    Pribors[A_pribor].sensors[num_sensor].series = Series;

    Chart->addSeries(Series);

    Series->attachAxis(xAxis);
    Series->attachAxis(yAxis);
}

void MainWindow::AddCheckBox(){

    sensorsChBs.clear();
    QCheckBox* tmp_ch;
    QLabel* tmp_l;
    QFont tmp_font;
    tmp_font.setPointSize(12);
    tmp_font.setBold(false);
    for( int i = 0; i < Pribors[A_pribor].sensors.length(); i++){

        // Чекбокс с порядковым номером в имени
        tmp_ch = new QCheckBox();
        sensorsChBs.append(tmp_ch);
        tmp_ch->setObjectName("ChekB_" + QString::number(i));
        tmp_ch->sizePolicy().setVerticalPolicy(QSizePolicy::Policy::Maximum);
        tmp_ch->sizePolicy().setHorizontalPolicy(QSizePolicy::Policy::Minimum);
        if(Pribors[A_pribor].sensors[i].isActive) tmp_ch->setChecked(true);

        // Соединяем новый Ч.Б с сигналом переключения и соответствующим слотом
        connect(tmp_ch, SIGNAL(toggled(bool)), this, SLOT(on_change(bool)));

        // Подпись к чекбоксу
        tmp_l = new QLabel();
        tmp_l->sizePolicy().setVerticalPolicy(QSizePolicy::Policy::Maximum);
        tmp_l->sizePolicy().setHorizontalPolicy(QSizePolicy::Policy::Maximum);
        tmp_l->setFont(tmp_font);
        tmp_l->setText(Pribors[A_pribor].sensors[i].name);

        // Добавляем в лейаут
        ui->gridLayout_4->addWidget(tmp_l,i,0);
        ui->gridLayout_4->addWidget(tmp_ch,i,1);
    }

    //чекбоксдля для всех приборов

        tmp_ch = new QCheckBox();
        tmp_ch->setObjectName("ChekB_All");
        tmp_ch->sizePolicy().setVerticalPolicy(QSizePolicy::Policy::Maximum);
        tmp_ch->sizePolicy().setHorizontalPolicy(QSizePolicy::Policy::Minimum);

        // Соединяем новый Ч.Б с сигналом переключения и соответствующим слотом
        connect(tmp_ch, SIGNAL(toggled(bool)), this, SLOT(on_change_allChB(bool)));

        // Подпись к чекбоксу
        tmp_l = new QLabel();
        tmp_l->sizePolicy().setVerticalPolicy(QSizePolicy::Policy::Maximum);
        tmp_l->sizePolicy().setHorizontalPolicy(QSizePolicy::Policy::Maximum);
        tmp_l->setFont(tmp_font);
        tmp_l->setText("Все датчики");

        // Добавляем в лейаут
        ui->gridLayout_4->addWidget(tmp_l, Pribors[A_pribor].sensors.length(),0);
        ui->gridLayout_4->addWidget(tmp_ch, Pribors[A_pribor].sensors.length(),1);

    //----------------------------

    // Распорка чтоб прижать сторочки вверх
    QSpacerItem *tmp_spacer = new QSpacerItem(20,200,QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->gridLayout_4->addItem(tmp_spacer,Pribors[A_pribor].sensors.length(),0);

}

void MainWindow::ReDraw(){
    QVector<bool> B_tmp(Pribors[A_pribor].sensors.length(), false);

    for (int i = 0; i < Pribors[A_pribor].sensors.length() ; i++) {
        if(Pribors[A_pribor].sensors[i].isActive){
            B_tmp[i] = true;
            Pribors[A_pribor].sensors[i].isActive = false;
            Chart->removeSeries(Pribors[A_pribor].sensors[i].series);
            delete Pribors[A_pribor].sensors[i].series;
            Pribors[A_pribor].sensors[i].series = nullptr;
        }
    }

    for (int i = 0; i < Pribors[A_pribor].sensors.length() ; i++) {
        if (B_tmp[i]){
             AddSeries(i);
        }
    }
}

QDateTime MainWindow::SetCorrectDate(QDateTime dt, int num_sens){

    double l_delta, r_delta , d_dt_tmp;
    d_dt_tmp = dt.toMSecsSinceEpoch();
    Sensor sens = Pribors[A_pribor].sensors[num_sens];
    for (int i = 1 ;i < sens.times.length(); i++ ) {
        if(sens.times[i] > dt){

            r_delta = sens.times[i].toMSecsSinceEpoch() - d_dt_tmp;
            l_delta = d_dt_tmp - sens.times[i-1].toMSecsSinceEpoch();
            if (r_delta < l_delta){
                return sens.times[i];
            }
            else{
                return sens.times[i-1];
            }
        }
    }
    return Pribors[A_pribor].end;
}

void MainWindow::on_actionOpen_triggered()
{

    QString filters("JSON/CSV(*.json , *.csv) ;; JSON(*.json) ;; CSV (*.csv) ");
    QString selected_filters;

    // Получаем имя файла который хотел открыть пользователь.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"C:/",filters ,&selected_filters);
    FOpenFile fof;
    if(selected_filters == "CSV (*.csv)") fof = FOpenFile::CSV;
    else fof = FOpenFile::JSON;

    if (!fileName.isEmpty()){

        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);

        Clear();

        clRead = new Read(file,Pribors,fof);
        connect(clRead, SIGNAL(finished()), this,SLOT(Fileisreaded()));
        ui->statusBar->show();
        ui->statusBar->showMessage("Подождите файл открывается ...");
        clRead->start();
        Set_Enabled(false);
    }
}

void MainWindow::Fileisreaded(){


    file.close();
    if(Pribors.length() > 0) SettingPribors();
    Set_Enabled(true);
    ui->statusBar->hide();
    delete clRead;
}

void MainWindow::SettingPribors(){

    // Добавляем в комбобокс приборы
    for(auto i: Pribors){
        bool isadd = false;
        for(int j = 0 ; j < ui->comboBox->count(); j++){
            if (i.name == ui->comboBox->itemText(j)) isadd = true;
        }
        if(!isadd){
            ui->comboBox->addItem(i.name);
        }
    }

    ui->comboBox->setCurrentIndex(0);
    A_pribor = 0;

    // Устанавливаем максимальный временной промяжуток

    ui->dateTime_begin->setDateTime(Pribors[A_pribor].begin);
    ui->dateTime_end->setDateTime(Pribors[A_pribor].end);
    ui->dateTime_begin->setEnabled(true);
    ui->dateTime_end->setEnabled(true);

    // Устанавливаем оси граффика

    xAxis->setRange(Pribors[A_pribor].begin,Pribors[A_pribor].end);
    Chart->addAxis(yAxis, Qt::AlignLeft);
    Chart->addAxis(xAxis, Qt::AlignBottom);

    // Добавляем чекбоксы с датчиками

    AddCheckBox();
}

void MainWindow::on_dateTime_end_editingFinished()
{
    QDateTimeEdit* Dt_tmp = ui->dateTime_end;

    if(Dt_tmp->dateTime()> Pribors[A_pribor].end){
        Dt_tmp->setDateTime(Pribors[A_pribor].end);
    }
    else if (Dt_tmp->dateTime() <= ui->dateTime_begin->dateTime()) {
        Dt_tmp->setDateTime(ui->dateTime_begin->dateTime().addSecs(3600));
    }
    xAxis->setMax(Dt_tmp->dateTime());
    ReDraw();
}

void MainWindow::on_dateTime_begin_editingFinished()
{
    QDateTimeEdit* Dt_tmp = ui->dateTime_begin;

    if(Dt_tmp->dateTime()< Pribors[A_pribor].begin){
        Dt_tmp->setDateTime(Pribors[A_pribor].begin);
    }
    else if (Dt_tmp->dateTime() >= ui->dateTime_end->dateTime()) {
        Dt_tmp->setDateTime(ui->dateTime_end->dateTime().addSecs(-3600));
    }
    xAxis->setMin(Dt_tmp->dateTime());

    ReDraw();
}

void MainWindow::on_comboBox_activated(int index)
{
    A_pribor = index;

    QLayoutItem *child;
    while ((child = ui->gridLayout_4->takeAt(0)) != nullptr){
        // ...
        delete child->widget();     // delete the widget
        delete child;               // delete the layout item
    }

    xAxis->setRange(Pribors[A_pribor].begin,Pribors[A_pribor].end);
    ui->dateTime_begin->setDateTime(Pribors[A_pribor].begin);
    ui->dateTime_end->setDateTime(Pribors[A_pribor].end);

    AddCheckBox();
}

void MainWindow::on_Clear_triggered() {Clear();}

void MainWindow::on_addFile_triggered()
{
    QString filters("JSON/CSV(*.json , *.csv) ;; JSON(*.json) ;; CSV (*.csv) ");
    QString selected_filters;

    // Получаем имя файла который хотел открыть пользователь.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"C:\\",filters ,&selected_filters);
    FOpenFile fof;
    if(selected_filters == "CSV (*.csv)") fof = FOpenFile::CSV;
    else fof = FOpenFile::JSON;

    if (!fileName.isEmpty()){
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);

        clRead = new Read(file,Pribors,fof);
        connect(clRead, SIGNAL(finished()), this,SLOT(Fileisreaded()));
        ui->statusBar->show();
        ui->statusBar->showMessage("Подождите файл открывается ...");
        clRead->start();
        ui->addFile->setEnabled(false);
        ui->actionOpen->setEnabled(false);

     }
}

void MainWindow::onResult(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        reply->ignoreSslErrors();
    }
    else{
        QString res = reply->readAll();
        //ui->plainTextEdit->document()->setPlainText(res);
        qDebug() << res;
        //SettingPribors();

        QFile file;
        QString filters("JSON(*.json)");
        QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"),"C:/Project_Visual/practice/Склейка",filters);


        file.setFileName(fileName);
        file.open(QIODevice::WriteOnly | QIODevice::Text);

        QTextStream stream( &file );
        stream << res;
        file.close();
    }
    reply->deleteLater();
}

void MainWindow::Set_Enabled(bool b){
    ui->addFile->setEnabled(b);
    ui->actionOpen->setEnabled(b);
    ui->ChB_24H_Av->setCheckable(b);
    ui->ChB_4H_Av->setCheckable(b);
    ui->ChB_H_Av->setCheckable(b);
    ui->ChB_Wout_Av->setCheckable(b);
}

void MainWindow::on_ChB_Wout_Av_clicked(bool checked)
{
    if(checked) {avMod = AverangeMod::NoAverange; if (Pribors.length()>0) ReDraw();}
}
void MainWindow::on_ChB_H_Av_clicked(bool checked)
{
    if(checked) {avMod = AverangeMod::HAverange; if (Pribors.length()>0) ReDraw();}
}
void MainWindow::on_ChB_4H_Av_clicked(bool checked)
{
    if(checked) {avMod = AverangeMod::H4Averange; if (Pribors.length()>0) ReDraw();}
}
void MainWindow::on_ChB_24H_Av_clicked(bool checked)
{
    if(checked) {avMod = AverangeMod::H24Averange; if (Pribors.length()>0) ReDraw();}
}


void MainWindow::on_NetRequest_triggered()
{

    QString url =   "https://www.gismeteo.ru/diary/11441/2021/1/";

    QSslConfiguration ssl = QSslConfiguration::defaultConfiguration();
    ssl.setProtocol(QSsl::AnyProtocol);
    QSslConfiguration::setDefaultConfiguration(ssl);

    QNetworkRequest req;
    req.setUrl(QUrl(url));
    req.setSslConfiguration(ssl);
    manager->get(req);
}


void Read::run(){

    QString str;

    switch (fof) {
    case FOpenFile::CSV:{


        str = QString::fromLocal8Bit(in.readLine());
        // Читаем первую строчку - берём от туда имя прибора
        Pribor *A = new Pribor(str.split(QChar(';'))[1]);
        bool new_pribor = true;
        for(auto &pr: B){
            if(pr.name == A->name){
                delete A;
                A = &pr;
                new_pribor = false;
            }
        }

        // Вторую строчку читаем чтоб забрать датчики
        str = in.readLine();
        QStringList sensors;

        if(new_pribor)
        {
            QStringList sensors = str.split(QChar(';'));
            int couSens = sensors.length() - 2;

            for (int i = 1 ; i <= couSens ; i++){
                A->sensors.push_back(Sensor(sensors[i]));
            }
        }

        // Считываем время и данные с датчиков.
        QString Format("yyyy-MM-dd hh:mm:ss");
        QDateTime max,min;
        while (!in.atEnd()){
            str = in.readLine();
            sensors = str.split(QChar(';'));
            QDateTime dt_tmp = QDateTime::fromString(sensors[0],Format);
            for (int i = 1 ; i <= A->sensors.length() ; i++){
                A->sensors[i-1].times.push_back(dt_tmp);
                A->sensors[i-1].value.push_back(sensors[i].toDouble());
            }
            if(min == QDateTime() && max == QDateTime()){
                min = dt_tmp;
                max = dt_tmp;
            }
            else{
                if(dt_tmp < min) min = dt_tmp;
                if(dt_tmp > max) max = dt_tmp;
            }
        }

        if(new_pribor){
            A->begin = min;
            A->end = max;
        }
        else{
            if(min < A->begin) A->begin = min;
            if(max > A->end) A->end = max;
        }

        if (new_pribor){
            B.append(*A);
        }
        break;
    }

    case FOpenFile::JSON: {

        str = QString::fromUtf8(in.readAll());
        ReadJson(str);
        break;
    }
    }
}

bool Read::ReadJson(QString str){

    QJsonDocument json = QJsonDocument::fromJson(str.toUtf8());
    if (!json.isObject()){
        return false;
    }
    QJsonObject jsonObj = json.object();

    QJsonObject pribor_j;

    QVector<QString> keys = jsonObj.keys();
    int imin =keys[0].toInt(), imax =keys[0].toInt();

    for(const auto& i : keys){
        int ii = i.toInt();
        if (ii > imax) imax = ii;
        if (ii < imin) imin = ii;
    }

    for(int ii = imin; ii <=imax; ii++ ){
        QString i = QString::number(ii);
        pribor_j = jsonObj[i].toObject();
        QString name_j = pribor_j["uName"].toString() + "_" + pribor_j["serial"].toString();
        QDateTime dt_j = QDateTime::fromString(pribor_j["Date"].toString(),"yyyy-MM-dd hh:mm:ss");

        bool isAdded = false;

        QJsonObject sensors_j = pribor_j["data"].toObject();

        QVector<QString> names_sensor_j = sensors_j.keys();
        QString val_s;
        for (auto &j : B){
            if(j.name == name_j){
                for(auto x: names_sensor_j){
                    bool adsens = false;
                    val_s = sensors_j.value(x).toString();
                    bool ok = false;
                    double val_d = val_s.toDouble(&ok);

                    for(auto &y: j.sensors){
                        if(y.name == x){
                            adsens = true;
                            if(ok){
                                y.times.push_back(dt_j);
                                y.value.push_back(val_d);
                                if(j.begin > dt_j) j.begin = dt_j;
                                if(j.end < dt_j) j.end = dt_j;
                            }
                            break;
                        }
                    }
                    if(!adsens && ok){
                        Sensor sens_tmp(x);
                        sens_tmp.times.push_back(dt_j);
                        sens_tmp.value.push_back(val_d);
                        j.sensors.push_back(sens_tmp);

                        if(j.begin > dt_j) j.begin = dt_j;
                        if(j.end < dt_j) j.end = dt_j;
                    }
                }
            isAdded = true;
            break;
            }
        }

        if(!isAdded){
            Pribor A(name_j);
            for(auto j: names_sensor_j){
                val_s = sensors_j.value(j).toString();
                bool ok = false;
                double val_d = val_s.toDouble(&ok);

                if(ok){
                    Sensor sens_tmp(j);
                    sens_tmp.times.push_back(dt_j);
                    sens_tmp.value.push_back(val_d);
                    A.sensors.push_back(sens_tmp);

                    A.begin = dt_j;
                    A.end = dt_j;
                }
            }
            B.append(A);
        }
    }
    return false;
}

void MainWindow::on_MaxY_ValueLine_editingFinished()
{
    yAxis->setMax(ui->MaxY_ValueLine->text().toDouble());
}

void MainWindow::on_MinY_ValueLine_editingFinished()
{
    yAxis->setMin(ui->MinY_ValueLine->text().toDouble());
}

void MainWindow::on_ExportTabe_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export Tabe"),"C:\\","Text(*.txt)");

    QFile file(fileName);

      // Открываем файл в режиме "Только для записи"
      if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file); // поток записываемых данных направляем в файл
        out << Pribors[A_pribor].name << '\n';
        out << "Date" << '\t';
        QList<QPointF> points;
        for (int i = 0;i < Pribors[A_pribor].sensors.length(); i++ ) {
            Sensor tmp_sens = Pribors[A_pribor].sensors[i];
            if (tmp_sens.isActive){
                out << tmp_sens.name << '\t';
                points = Pribors[A_pribor].sensors[i].series->points();
            }
        }
        out <<'\n';

        for (int i = 0; i < points.length() ;i+=2 ) {
            QDateTime now = QDateTime::fromMSecsSinceEpoch(points[i].rx());

            if (now >= xAxis->min() &&  now <= xAxis->max()){
                out << now.toString() << '\t';
                for (auto sens: Pribors[A_pribor].sensors){
                    if(sens.isActive){
                        out << sens.series->at(i).y() << '\t';
                    }
                }
                out <<'\n';
            }
        }

      } else {

         qWarning("Could not open file");
      }
    file.close();

    qDebug() << fileName;


}

void MainWindow::on_Menu_export_server_report_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export Tabe"),"C:\\","Text(*.txt)");

    QFile file(fileName);

      // Открываем файл в режиме "Только для записи"
      if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file); // поток записываемых данных направляем в файл
        out << Pribors[A_pribor].name << '\n';
        QList<QPointF> points;

        for (int i = 0;i < Pribors[A_pribor].sensors.length(); i++ ) {
            Sensor tmp_sens = Pribors[A_pribor].sensors[i];
            if (tmp_sens.isActive){
                out << tmp_sens.name << '\t';
                points = Pribors[A_pribor].sensors[i].series->points();

                for (int i = 0; i < points.length() ;i+=2 ) {
                    QDateTime now = QDateTime::fromMSecsSinceEpoch(points[i].rx());

                    if (now >= xAxis->min() &&  now <= xAxis->max()){
                        //out << now.toString() << '\t';
                        out << points[i].y() << '\t';
                        }
                    }
                out <<'\n';
            }
        }

      } else {

         qWarning("Could not open file");
      }
    file.close();

    qDebug() << fileName;
}

void MainWindow::on_ChB_Another_Av_clicked(bool checked)
{
    if(checked) {avMod = AverangeMod::AnotherAverange; if (Pribors.length()>0) ReDraw();}
}

void MainWindow::on_ChB_TypeGraph_Line_clicked()
{
    typeGraph = TypeGraph::Line;
}

void MainWindow::on_ChB_TypeGraph_Point_clicked()
{
    typeGraph = TypeGraph::Point;
}

