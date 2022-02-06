/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *addFile;
    QAction *Clear;
    QAction *NetRequest;
    QAction *ExportTabe;
    QAction *Menu_export_server_report;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter_2;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QDateTimeEdit *dateTime_end;
    QLabel *label;
    QLabel *label_3;
    QDateTimeEdit *dateTime_begin;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *ChB_Wout_Av;
    QCheckBox *ChB_H_Av;
    QCheckBox *ChB_4H_Av;
    QCheckBox *ChB_24H_Av;
    QCheckBox *ChB_Another_Av;
    QLineEdit *lineEdit_Athoter_Averange;
    QSplitter *splitter;
    QChartView *graphicsView;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *MaxY_ValueLine;
    QLabel *label_5;
    QLineEdit *MinY_ValueLine;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *ChB_TypeGraph_Line;
    QCheckBox *ChB_TypeGraph_Point;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1101, 802);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        addFile = new QAction(MainWindow);
        addFile->setObjectName(QString::fromUtf8("addFile"));
        Clear = new QAction(MainWindow);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        NetRequest = new QAction(MainWindow);
        NetRequest->setObjectName(QString::fromUtf8("NetRequest"));
        NetRequest->setCheckable(true);
        NetRequest->setEnabled(false);
        ExportTabe = new QAction(MainWindow);
        ExportTabe->setObjectName(QString::fromUtf8("ExportTabe"));
        Menu_export_server_report = new QAction(MainWindow);
        Menu_export_server_report->setObjectName(QString::fromUtf8("Menu_export_server_report"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        groupBox->setChecked(false);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(14);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font;
        font.setPointSize(12);
        comboBox->setFont(font);
        comboBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBox->setEditable(false);
        comboBox->setFrame(true);
        comboBox->setModelColumn(0);

        horizontalLayout->addWidget(comboBox);

        horizontalLayout->setStretch(0, 3);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 5, 0, 0);
        splitter_2 = new QSplitter(groupBox_2);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        dateTime_end = new QDateTimeEdit(frame);
        dateTime_end->setObjectName(QString::fromUtf8("dateTime_end"));
        dateTime_end->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dateTime_end->sizePolicy().hasHeightForWidth());
        dateTime_end->setSizePolicy(sizePolicy2);
        dateTime_end->setFont(font);

        gridLayout_2->addWidget(dateTime_end, 2, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_3->setFont(font1);
        label_3->setContextMenuPolicy(Qt::NoContextMenu);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setLineWidth(1);
        label_3->setMidLineWidth(0);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 2);

        dateTime_begin = new QDateTimeEdit(frame);
        dateTime_begin->setObjectName(QString::fromUtf8("dateTime_begin"));
        dateTime_begin->setEnabled(false);
        sizePolicy2.setHeightForWidth(dateTime_begin->sizePolicy().hasHeightForWidth());
        dateTime_begin->setSizePolicy(sizePolicy2);
        dateTime_begin->setFont(font);
        dateTime_begin->setWrapping(false);

        gridLayout_2->addWidget(dateTime_begin, 2, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);

        verticalLayout_2->addLayout(gridLayout_2);

        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setFont(font1);
        groupBox_3->setMouseTracking(true);
        groupBox_3->setAlignment(Qt::AlignCenter);
        groupBox_3->setFlat(true);
        groupBox_3->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(groupBox_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 375, 187));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 6, 6, 6);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(10);
        gridLayout_4->setVerticalSpacing(12);

        gridLayout_3->addLayout(gridLayout_4, 1, 0, 1, 1);

        scrollArea->setWidget(widget);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(frame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy4);
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ChB_Wout_Av = new QCheckBox(groupBox_5);
        ChB_Wout_Av->setObjectName(QString::fromUtf8("ChB_Wout_Av"));
        sizePolicy4.setHeightForWidth(ChB_Wout_Av->sizePolicy().hasHeightForWidth());
        ChB_Wout_Av->setSizePolicy(sizePolicy4);
        ChB_Wout_Av->setCheckable(false);
        ChB_Wout_Av->setChecked(false);
        ChB_Wout_Av->setAutoExclusive(true);
        ChB_Wout_Av->setTristate(false);

        verticalLayout_3->addWidget(ChB_Wout_Av);

        ChB_H_Av = new QCheckBox(groupBox_5);
        ChB_H_Av->setObjectName(QString::fromUtf8("ChB_H_Av"));
        sizePolicy4.setHeightForWidth(ChB_H_Av->sizePolicy().hasHeightForWidth());
        ChB_H_Av->setSizePolicy(sizePolicy4);
        ChB_H_Av->setCheckable(false);
        ChB_H_Av->setAutoExclusive(true);
        ChB_H_Av->setTristate(false);

        verticalLayout_3->addWidget(ChB_H_Av);

        ChB_4H_Av = new QCheckBox(groupBox_5);
        ChB_4H_Av->setObjectName(QString::fromUtf8("ChB_4H_Av"));
        sizePolicy4.setHeightForWidth(ChB_4H_Av->sizePolicy().hasHeightForWidth());
        ChB_4H_Av->setSizePolicy(sizePolicy4);
        ChB_4H_Av->setCheckable(false);
        ChB_4H_Av->setAutoExclusive(true);

        verticalLayout_3->addWidget(ChB_4H_Av);

        ChB_24H_Av = new QCheckBox(groupBox_5);
        ChB_24H_Av->setObjectName(QString::fromUtf8("ChB_24H_Av"));
        sizePolicy4.setHeightForWidth(ChB_24H_Av->sizePolicy().hasHeightForWidth());
        ChB_24H_Av->setSizePolicy(sizePolicy4);
        ChB_24H_Av->setCheckable(false);
        ChB_24H_Av->setAutoExclusive(true);

        verticalLayout_3->addWidget(ChB_24H_Av);

        ChB_Another_Av = new QCheckBox(groupBox_5);
        ChB_Another_Av->setObjectName(QString::fromUtf8("ChB_Another_Av"));
        ChB_Another_Av->setAutoExclusive(true);

        verticalLayout_3->addWidget(ChB_Another_Av);

        lineEdit_Athoter_Averange = new QLineEdit(groupBox_5);
        lineEdit_Athoter_Averange->setObjectName(QString::fromUtf8("lineEdit_Athoter_Averange"));

        verticalLayout_3->addWidget(lineEdit_Athoter_Averange);


        verticalLayout_2->addWidget(groupBox_5);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);

        splitter_2->addWidget(frame);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy5);
        splitter->setOrientation(Qt::Vertical);
        graphicsView = new QChartView(splitter);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(1);
        sizePolicy6.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy6);
        graphicsView->setDragMode(QGraphicsView::NoDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        splitter->addWidget(graphicsView);
        groupBox_4 = new QGroupBox(splitter);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy4.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setPointSize(10);
        groupBox_4->setFont(font2);
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        formLayout = new QFormLayout(groupBox_6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        MaxY_ValueLine = new QLineEdit(groupBox_6);
        MaxY_ValueLine->setObjectName(QString::fromUtf8("MaxY_ValueLine"));

        formLayout->setWidget(0, QFormLayout::FieldRole, MaxY_ValueLine);

        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        MinY_ValueLine = new QLineEdit(groupBox_6);
        MinY_ValueLine->setObjectName(QString::fromUtf8("MinY_ValueLine"));

        formLayout->setWidget(1, QFormLayout::FieldRole, MinY_ValueLine);


        horizontalLayout_3->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_4 = new QVBoxLayout(groupBox_7);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ChB_TypeGraph_Line = new QCheckBox(groupBox_7);
        ChB_TypeGraph_Line->setObjectName(QString::fromUtf8("ChB_TypeGraph_Line"));
        ChB_TypeGraph_Line->setChecked(true);
        ChB_TypeGraph_Line->setAutoExclusive(true);

        verticalLayout_4->addWidget(ChB_TypeGraph_Line);

        ChB_TypeGraph_Point = new QCheckBox(groupBox_7);
        ChB_TypeGraph_Point->setObjectName(QString::fromUtf8("ChB_TypeGraph_Point"));
        ChB_TypeGraph_Point->setAutoExclusive(true);

        verticalLayout_4->addWidget(ChB_TypeGraph_Point);


        horizontalLayout_3->addWidget(groupBox_7);

        splitter->addWidget(groupBox_4);
        splitter_2->addWidget(splitter);

        horizontalLayout_2->addWidget(splitter_2);


        verticalLayout->addWidget(groupBox_2);

        verticalLayout->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1101, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(addFile);
        menuFile->addAction(ExportTabe);
        menuFile->addAction(Menu_export_server_report);
        menu->addAction(Clear);
        menu_2->addAction(NetRequest);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        addFile->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        NetRequest->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201", nullptr));
        ExportTabe->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        Menu_export_server_report->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202 \320\276\321\202\321\207\321\221\321\202 \320\277\320\276 \321\201\320\265\321\200\320\262\320\265\321\200\320\260\320\274", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\320\276\321\200", nullptr));
        comboBox->setCurrentText(QString());
        comboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\320\276\320\271\321\202\320\265 \321\204\320\260\320\271\320\273", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\271 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\321\207\320\270\320\272\320\270", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\320\265", nullptr));
        ChB_Wout_Av->setText(QCoreApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\276\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\321\217", nullptr));
        ChB_H_Av->setText(QCoreApplication::translate("MainWindow", " \320\227\320\260 \321\207\320\260\321\201", nullptr));
        ChB_4H_Av->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260 4 \321\207\320\260\321\201\320\260", nullptr));
        ChB_24H_Av->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260 \321\201\321\203\321\202\320\272\320\270", nullptr));
        ChB_Another_Av->setText(QCoreApplication::translate("MainWindow", "\320\224\321\200\321\203\320\263\320\276\320\265 \320\276\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\270\320\265", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\320\272\320\270 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\320\275\320\270\321\206\321\213 \320\222\320\265\321\200\321\202-\320\276\320\271 \320\276\321\201\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        ChB_TypeGraph_Line->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\265\320\271\320\275\321\213\320\271", nullptr));
        ChB_TypeGraph_Point->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\321\207\320\265\321\207\320\275\321\213\320\271", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
