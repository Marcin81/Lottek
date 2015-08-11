/********************************************************************************
** Form generated from reading ui file 'drawingform.ui'
**
** Created: Sun Nov 8 11:45:32 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
** License: GPL 
** Owner: Marcin Brysz
** Contact: unemployed81@gmail.com / bryszmarcin@gmail.com

********************************************************************************/

#ifndef UI_DRAWINGFORM_H
#define UI_DRAWINGFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drawingform
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *mMondayGroupBox;
    QTimeEdit *baseTimeMonday;
    QTimeEdit *firstTimeMonday;
    QTimeEdit *secondTimeMonday;
    QCheckBox *firstCheckBoxMonday;
    QCheckBox *secondCheckBoxMonday;
    QGroupBox *mTuesdayGroupBox;
    QTimeEdit *baseTimeTuesday;
    QTimeEdit *firstTimeTuesday;
    QTimeEdit *secondTimeTuesday;
    QCheckBox *firstCheckBoxTuesday;
    QCheckBox *secondCheckBoxTuesday;
    QGroupBox *mWednesdayGroupBox;
    QTimeEdit *baseTimeWednesday;
    QTimeEdit *firstTimeWednesday;
    QTimeEdit *secondTimeWednesday;
    QCheckBox *firstCheckBoxWednesday;
    QCheckBox *secondCheckBoxWednesday;
    QGroupBox *groupBoxDelay;
    QPushButton *pushButtonHidden;
    QLabel *delayLabel;
    QSpinBox *spinBoxDelay;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *mThursdayGroupBox;
    QTimeEdit *baseTimeThursday;
    QTimeEdit *firstTimeThursday;
    QTimeEdit *secondTimeThursday;
    QCheckBox *firstCheckBoxThursday;
    QCheckBox *secondCheckBoxThursday;
    QGroupBox *mFridayGroupBox;
    QTimeEdit *baseTimeFriday;
    QTimeEdit *firstTimeFriday;
    QTimeEdit *secondTimeFriday;
    QCheckBox *firstCheckBoxFriday;
    QCheckBox *secondCheckBoxFriday;
    QGroupBox *mSaturdayGroupBox;
    QTimeEdit *baseTimeSaturday;
    QTimeEdit *firstTimeSaturday;
    QTimeEdit *secondTimeSaturday;
    QCheckBox *firstCheckBoxSaturday;
    QCheckBox *secondCheckBoxSaturday;
    QGroupBox *mSundayGroupBox;
    QTimeEdit *baseTimeSunday;
    QTimeEdit *firstTimeSunday;
    QTimeEdit *secondTimeSunday;
    QCheckBox *firstCheckBoxSunday;
    QCheckBox *secondCheckBoxSunday;

    void setupUi(QWidget *drawingform)
    {
        if (drawingform->objectName().isEmpty())
            drawingform->setObjectName(QString::fromUtf8("drawingform"));
        drawingform->resize(632, 322);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(drawingform->sizePolicy().hasHeightForWidth());
        drawingform->setSizePolicy(sizePolicy);
        drawingform->setMinimumSize(QSize(632, 322));
        drawingform->setMaximumSize(QSize(632, 322));
        drawingform->setSizeIncrement(QSize(0, 0));
        drawingform->setBaseSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ball.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawingform->setWindowIcon(icon);
        gridLayout = new QGridLayout(drawingform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setMargin(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mMondayGroupBox = new QGroupBox(drawingform);
        mMondayGroupBox->setObjectName(QString::fromUtf8("mMondayGroupBox"));
        mMondayGroupBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mMondayGroupBox->sizePolicy().hasHeightForWidth());
        mMondayGroupBox->setSizePolicy(sizePolicy1);
        mMondayGroupBox->setFlat(false);
        mMondayGroupBox->setCheckable(true);
        mMondayGroupBox->setChecked(false);
        baseTimeMonday = new QTimeEdit(mMondayGroupBox);
        baseTimeMonday->setObjectName(QString::fromUtf8("baseTimeMonday"));
        baseTimeMonday->setGeometry(QRect(10, 30, 81, 25));
        sizePolicy1.setHeightForWidth(baseTimeMonday->sizePolicy().hasHeightForWidth());
        baseTimeMonday->setSizePolicy(sizePolicy1);
        baseTimeMonday->setCalendarPopup(false);
        baseTimeMonday->setTime(QTime(22, 0, 0));
        firstTimeMonday = new QTimeEdit(mMondayGroupBox);
        firstTimeMonday->setObjectName(QString::fromUtf8("firstTimeMonday"));
        firstTimeMonday->setEnabled(false);
        firstTimeMonday->setGeometry(QRect(10, 60, 81, 25));
        sizePolicy1.setHeightForWidth(firstTimeMonday->sizePolicy().hasHeightForWidth());
        firstTimeMonday->setSizePolicy(sizePolicy1);
        secondTimeMonday = new QTimeEdit(mMondayGroupBox);
        secondTimeMonday->setObjectName(QString::fromUtf8("secondTimeMonday"));
        secondTimeMonday->setEnabled(false);
        secondTimeMonday->setGeometry(QRect(10, 90, 81, 25));
        sizePolicy1.setHeightForWidth(secondTimeMonday->sizePolicy().hasHeightForWidth());
        secondTimeMonday->setSizePolicy(sizePolicy1);
        firstCheckBoxMonday = new QCheckBox(mMondayGroupBox);
        firstCheckBoxMonday->setObjectName(QString::fromUtf8("firstCheckBoxMonday"));
        firstCheckBoxMonday->setGeometry(QRect(100, 63, 21, 21));
        sizePolicy1.setHeightForWidth(firstCheckBoxMonday->sizePolicy().hasHeightForWidth());
        firstCheckBoxMonday->setSizePolicy(sizePolicy1);
        secondCheckBoxMonday = new QCheckBox(mMondayGroupBox);
        secondCheckBoxMonday->setObjectName(QString::fromUtf8("secondCheckBoxMonday"));
        secondCheckBoxMonday->setGeometry(QRect(100, 93, 21, 21));
        sizePolicy1.setHeightForWidth(secondCheckBoxMonday->sizePolicy().hasHeightForWidth());
        secondCheckBoxMonday->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(mMondayGroupBox);

        mTuesdayGroupBox = new QGroupBox(drawingform);
        mTuesdayGroupBox->setObjectName(QString::fromUtf8("mTuesdayGroupBox"));
        sizePolicy1.setHeightForWidth(mTuesdayGroupBox->sizePolicy().hasHeightForWidth());
        mTuesdayGroupBox->setSizePolicy(sizePolicy1);
        mTuesdayGroupBox->setFlat(false);
        mTuesdayGroupBox->setCheckable(true);
        baseTimeTuesday = new QTimeEdit(mTuesdayGroupBox);
        baseTimeTuesday->setObjectName(QString::fromUtf8("baseTimeTuesday"));
        baseTimeTuesday->setGeometry(QRect(10, 30, 81, 25));
        sizePolicy1.setHeightForWidth(baseTimeTuesday->sizePolicy().hasHeightForWidth());
        baseTimeTuesday->setSizePolicy(sizePolicy1);
        baseTimeTuesday->setTime(QTime(22, 0, 0));
        firstTimeTuesday = new QTimeEdit(mTuesdayGroupBox);
        firstTimeTuesday->setObjectName(QString::fromUtf8("firstTimeTuesday"));
        firstTimeTuesday->setEnabled(false);
        firstTimeTuesday->setGeometry(QRect(10, 60, 81, 25));
        sizePolicy1.setHeightForWidth(firstTimeTuesday->sizePolicy().hasHeightForWidth());
        firstTimeTuesday->setSizePolicy(sizePolicy1);
        secondTimeTuesday = new QTimeEdit(mTuesdayGroupBox);
        secondTimeTuesday->setObjectName(QString::fromUtf8("secondTimeTuesday"));
        secondTimeTuesday->setEnabled(false);
        secondTimeTuesday->setGeometry(QRect(10, 90, 81, 25));
        sizePolicy1.setHeightForWidth(secondTimeTuesday->sizePolicy().hasHeightForWidth());
        secondTimeTuesday->setSizePolicy(sizePolicy1);
        firstCheckBoxTuesday = new QCheckBox(mTuesdayGroupBox);
        firstCheckBoxTuesday->setObjectName(QString::fromUtf8("firstCheckBoxTuesday"));
        firstCheckBoxTuesday->setGeometry(QRect(100, 63, 21, 21));
        sizePolicy1.setHeightForWidth(firstCheckBoxTuesday->sizePolicy().hasHeightForWidth());
        firstCheckBoxTuesday->setSizePolicy(sizePolicy1);
        secondCheckBoxTuesday = new QCheckBox(mTuesdayGroupBox);
        secondCheckBoxTuesday->setObjectName(QString::fromUtf8("secondCheckBoxTuesday"));
        secondCheckBoxTuesday->setGeometry(QRect(100, 93, 21, 21));
        sizePolicy1.setHeightForWidth(secondCheckBoxTuesday->sizePolicy().hasHeightForWidth());
        secondCheckBoxTuesday->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(mTuesdayGroupBox);

        mWednesdayGroupBox = new QGroupBox(drawingform);
        mWednesdayGroupBox->setObjectName(QString::fromUtf8("mWednesdayGroupBox"));
        mWednesdayGroupBox->setEnabled(true);
        sizePolicy1.setHeightForWidth(mWednesdayGroupBox->sizePolicy().hasHeightForWidth());
        mWednesdayGroupBox->setSizePolicy(sizePolicy1);
        mWednesdayGroupBox->setFlat(false);
        mWednesdayGroupBox->setCheckable(true);
        mWednesdayGroupBox->setChecked(false);
        baseTimeWednesday = new QTimeEdit(mWednesdayGroupBox);
        baseTimeWednesday->setObjectName(QString::fromUtf8("baseTimeWednesday"));
        baseTimeWednesday->setGeometry(QRect(10, 30, 81, 25));
        sizePolicy1.setHeightForWidth(baseTimeWednesday->sizePolicy().hasHeightForWidth());
        baseTimeWednesday->setSizePolicy(sizePolicy1);
        baseTimeWednesday->setTime(QTime(22, 0, 0));
        firstTimeWednesday = new QTimeEdit(mWednesdayGroupBox);
        firstTimeWednesday->setObjectName(QString::fromUtf8("firstTimeWednesday"));
        firstTimeWednesday->setEnabled(false);
        firstTimeWednesday->setGeometry(QRect(10, 60, 81, 25));
        sizePolicy1.setHeightForWidth(firstTimeWednesday->sizePolicy().hasHeightForWidth());
        firstTimeWednesday->setSizePolicy(sizePolicy1);
        secondTimeWednesday = new QTimeEdit(mWednesdayGroupBox);
        secondTimeWednesday->setObjectName(QString::fromUtf8("secondTimeWednesday"));
        secondTimeWednesday->setEnabled(false);
        secondTimeWednesday->setGeometry(QRect(10, 90, 81, 25));
        sizePolicy1.setHeightForWidth(secondTimeWednesday->sizePolicy().hasHeightForWidth());
        secondTimeWednesday->setSizePolicy(sizePolicy1);
        firstCheckBoxWednesday = new QCheckBox(mWednesdayGroupBox);
        firstCheckBoxWednesday->setObjectName(QString::fromUtf8("firstCheckBoxWednesday"));
        firstCheckBoxWednesday->setGeometry(QRect(100, 63, 21, 21));
        sizePolicy1.setHeightForWidth(firstCheckBoxWednesday->sizePolicy().hasHeightForWidth());
        firstCheckBoxWednesday->setSizePolicy(sizePolicy1);
        secondCheckBoxWednesday = new QCheckBox(mWednesdayGroupBox);
        secondCheckBoxWednesday->setObjectName(QString::fromUtf8("secondCheckBoxWednesday"));
        secondCheckBoxWednesday->setGeometry(QRect(100, 93, 21, 21));
        sizePolicy1.setHeightForWidth(secondCheckBoxWednesday->sizePolicy().hasHeightForWidth());
        secondCheckBoxWednesday->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(mWednesdayGroupBox);

        groupBoxDelay = new QGroupBox(drawingform);
        groupBoxDelay->setObjectName(QString::fromUtf8("groupBoxDelay"));
        sizePolicy1.setHeightForWidth(groupBoxDelay->sizePolicy().hasHeightForWidth());
        groupBoxDelay->setSizePolicy(sizePolicy1);
        groupBoxDelay->setCheckable(false);
        pushButtonHidden = new QPushButton(groupBoxDelay);
        pushButtonHidden->setObjectName(QString::fromUtf8("pushButtonHidden"));
        pushButtonHidden->setGeometry(QRect(5, 75, 111, 41));
        sizePolicy1.setHeightForWidth(pushButtonHidden->sizePolicy().hasHeightForWidth());
        pushButtonHidden->setSizePolicy(sizePolicy1);
        delayLabel = new QLabel(groupBoxDelay);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));
        delayLabel->setGeometry(QRect(10, 5, 81, 31));
        sizePolicy1.setHeightForWidth(delayLabel->sizePolicy().hasHeightForWidth());
        delayLabel->setSizePolicy(sizePolicy1);
        delayLabel->setLayoutDirection(Qt::LeftToRight);
        spinBoxDelay = new QSpinBox(groupBoxDelay);
        spinBoxDelay->setObjectName(QString::fromUtf8("spinBoxDelay"));
        spinBoxDelay->setGeometry(QRect(10, 45, 100, 25));
        sizePolicy1.setHeightForWidth(spinBoxDelay->sizePolicy().hasHeightForWidth());
        spinBoxDelay->setSizePolicy(sizePolicy1);
        spinBoxDelay->setMinimum(5);
        spinBoxDelay->setMaximum(20);
        spinBoxDelay->setSingleStep(5);
        spinBoxDelay->setValue(15);

        horizontalLayout->addWidget(groupBoxDelay);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setMargin(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mThursdayGroupBox = new QGroupBox(drawingform);
        mThursdayGroupBox->setObjectName(QString::fromUtf8("mThursdayGroupBox"));
        sizePolicy1.setHeightForWidth(mThursdayGroupBox->sizePolicy().hasHeightForWidth());
        mThursdayGroupBox->setSizePolicy(sizePolicy1);
        mThursdayGroupBox->setFlat(false);
        mThursdayGroupBox->setCheckable(true);
        baseTimeThursday = new QTimeEdit(mThursdayGroupBox);
        baseTimeThursday->setObjectName(QString::fromUtf8("baseTimeThursday"));
        baseTimeThursday->setGeometry(QRect(10, 30, 81, 25));
        sizePolicy1.setHeightForWidth(baseTimeThursday->sizePolicy().hasHeightForWidth());
        baseTimeThursday->setSizePolicy(sizePolicy1);
        baseTimeThursday->setTime(QTime(22, 0, 0));
        firstTimeThursday = new QTimeEdit(mThursdayGroupBox);
        firstTimeThursday->setObjectName(QString::fromUtf8("firstTimeThursday"));
        firstTimeThursday->setEnabled(false);
        firstTimeThursday->setGeometry(QRect(10, 60, 81, 25));
        sizePolicy1.setHeightForWidth(firstTimeThursday->sizePolicy().hasHeightForWidth());
        firstTimeThursday->setSizePolicy(sizePolicy1);
        secondTimeThursday = new QTimeEdit(mThursdayGroupBox);
        secondTimeThursday->setObjectName(QString::fromUtf8("secondTimeThursday"));
        secondTimeThursday->setEnabled(false);
        secondTimeThursday->setGeometry(QRect(10, 90, 81, 25));
        sizePolicy1.setHeightForWidth(secondTimeThursday->sizePolicy().hasHeightForWidth());
        secondTimeThursday->setSizePolicy(sizePolicy1);
        firstCheckBoxThursday = new QCheckBox(mThursdayGroupBox);
        firstCheckBoxThursday->setObjectName(QString::fromUtf8("firstCheckBoxThursday"));
        firstCheckBoxThursday->setGeometry(QRect(100, 63, 21, 21));
        sizePolicy1.setHeightForWidth(firstCheckBoxThursday->sizePolicy().hasHeightForWidth());
        firstCheckBoxThursday->setSizePolicy(sizePolicy1);
        secondCheckBoxThursday = new QCheckBox(mThursdayGroupBox);
        secondCheckBoxThursday->setObjectName(QString::fromUtf8("secondCheckBoxThursday"));
        secondCheckBoxThursday->setGeometry(QRect(100, 93, 21, 21));
        sizePolicy1.setHeightForWidth(secondCheckBoxThursday->sizePolicy().hasHeightForWidth());
        secondCheckBoxThursday->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(mThursdayGroupBox);

        mFridayGroupBox = new QGroupBox(drawingform);
        mFridayGroupBox->setObjectName(QString::fromUtf8("mFridayGroupBox"));
        mFridayGroupBox->setEnabled(true);
        sizePolicy1.setHeightForWidth(mFridayGroupBox->sizePolicy().hasHeightForWidth());
        mFridayGroupBox->setSizePolicy(sizePolicy1);
        mFridayGroupBox->setFlat(false);
        mFridayGroupBox->setCheckable(true);
        mFridayGroupBox->setChecked(false);
        baseTimeFriday = new QTimeEdit(mFridayGroupBox);
        baseTimeFriday->setObjectName(QString::fromUtf8("baseTimeFriday"));
        baseTimeFriday->setGeometry(QRect(10, 30, 81, 25));
        sizePolicy1.setHeightForWidth(baseTimeFriday->sizePolicy().hasHeightForWidth());
        baseTimeFriday->setSizePolicy(sizePolicy1);
        baseTimeFriday->setTime(QTime(22, 0, 0));
        firstTimeFriday = new QTimeEdit(mFridayGroupBox);
        firstTimeFriday->setObjectName(QString::fromUtf8("firstTimeFriday"));
        firstTimeFriday->setEnabled(false);
        firstTimeFriday->setGeometry(QRect(10, 60, 81, 25));
        sizePolicy1.setHeightForWidth(firstTimeFriday->sizePolicy().hasHeightForWidth());
        firstTimeFriday->setSizePolicy(sizePolicy1);
        secondTimeFriday = new QTimeEdit(mFridayGroupBox);
        secondTimeFriday->setObjectName(QString::fromUtf8("secondTimeFriday"));
        secondTimeFriday->setEnabled(false);
        secondTimeFriday->setGeometry(QRect(10, 90, 81, 25));
        sizePolicy1.setHeightForWidth(secondTimeFriday->sizePolicy().hasHeightForWidth());
        secondTimeFriday->setSizePolicy(sizePolicy1);
        firstCheckBoxFriday = new QCheckBox(mFridayGroupBox);
        firstCheckBoxFriday->setObjectName(QString::fromUtf8("firstCheckBoxFriday"));
        firstCheckBoxFriday->setGeometry(QRect(100, 63, 21, 21));
        sizePolicy1.setHeightForWidth(firstCheckBoxFriday->sizePolicy().hasHeightForWidth());
        firstCheckBoxFriday->setSizePolicy(sizePolicy1);
        secondCheckBoxFriday = new QCheckBox(mFridayGroupBox);
        secondCheckBoxFriday->setObjectName(QString::fromUtf8("secondCheckBoxFriday"));
        secondCheckBoxFriday->setGeometry(QRect(100, 93, 21, 21));
        sizePolicy1.setHeightForWidth(secondCheckBoxFriday->sizePolicy().hasHeightForWidth());
        secondCheckBoxFriday->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(mFridayGroupBox);

        mSaturdayGroupBox = new QGroupBox(drawingform);
        mSaturdayGroupBox->setObjectName(QString::fromUtf8("mSaturdayGroupBox"));
        sizePolicy1.setHeightForWidth(mSaturdayGroupBox->sizePolicy().hasHeightForWidth());
        mSaturdayGroupBox->setSizePolicy(sizePolicy1);
        mSaturdayGroupBox->setFlat(false);
        mSaturdayGroupBox->setCheckable(true);
        baseTimeSaturday = new QTimeEdit(mSaturdayGroupBox);
        baseTimeSaturday->setObjectName(QString::fromUtf8("baseTimeSaturday"));
        baseTimeSaturday->setGeometry(QRect(10, 30, 81, 25));
        sizePolicy1.setHeightForWidth(baseTimeSaturday->sizePolicy().hasHeightForWidth());
        baseTimeSaturday->setSizePolicy(sizePolicy1);
        baseTimeSaturday->setTime(QTime(22, 0, 0));
        firstTimeSaturday = new QTimeEdit(mSaturdayGroupBox);
        firstTimeSaturday->setObjectName(QString::fromUtf8("firstTimeSaturday"));
        firstTimeSaturday->setEnabled(false);
        firstTimeSaturday->setGeometry(QRect(10, 60, 81, 25));
        sizePolicy1.setHeightForWidth(firstTimeSaturday->sizePolicy().hasHeightForWidth());
        firstTimeSaturday->setSizePolicy(sizePolicy1);
        secondTimeSaturday = new QTimeEdit(mSaturdayGroupBox);
        secondTimeSaturday->setObjectName(QString::fromUtf8("secondTimeSaturday"));
        secondTimeSaturday->setEnabled(false);
        secondTimeSaturday->setGeometry(QRect(10, 90, 81, 25));
        sizePolicy1.setHeightForWidth(secondTimeSaturday->sizePolicy().hasHeightForWidth());
        secondTimeSaturday->setSizePolicy(sizePolicy1);
        firstCheckBoxSaturday = new QCheckBox(mSaturdayGroupBox);
        firstCheckBoxSaturday->setObjectName(QString::fromUtf8("firstCheckBoxSaturday"));
        firstCheckBoxSaturday->setGeometry(QRect(100, 63, 21, 21));
        sizePolicy1.setHeightForWidth(firstCheckBoxSaturday->sizePolicy().hasHeightForWidth());
        firstCheckBoxSaturday->setSizePolicy(sizePolicy1);
        secondCheckBoxSaturday = new QCheckBox(mSaturdayGroupBox);
        secondCheckBoxSaturday->setObjectName(QString::fromUtf8("secondCheckBoxSaturday"));
        secondCheckBoxSaturday->setGeometry(QRect(100, 93, 21, 21));
        sizePolicy1.setHeightForWidth(secondCheckBoxSaturday->sizePolicy().hasHeightForWidth());
        secondCheckBoxSaturday->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(mSaturdayGroupBox);

        mSundayGroupBox = new QGroupBox(drawingform);
        mSundayGroupBox->setObjectName(QString::fromUtf8("mSundayGroupBox"));
        mSundayGroupBox->setEnabled(true);
        sizePolicy1.setHeightForWidth(mSundayGroupBox->sizePolicy().hasHeightForWidth());
        mSundayGroupBox->setSizePolicy(sizePolicy1);
        mSundayGroupBox->setFlat(false);
        mSundayGroupBox->setCheckable(true);
        mSundayGroupBox->setChecked(false);
        baseTimeSunday = new QTimeEdit(mSundayGroupBox);
        baseTimeSunday->setObjectName(QString::fromUtf8("baseTimeSunday"));
        baseTimeSunday->setGeometry(QRect(10, 30, 81, 25));
        sizePolicy1.setHeightForWidth(baseTimeSunday->sizePolicy().hasHeightForWidth());
        baseTimeSunday->setSizePolicy(sizePolicy1);
        baseTimeSunday->setTime(QTime(22, 0, 0));
        firstTimeSunday = new QTimeEdit(mSundayGroupBox);
        firstTimeSunday->setObjectName(QString::fromUtf8("firstTimeSunday"));
        firstTimeSunday->setEnabled(false);
        firstTimeSunday->setGeometry(QRect(10, 60, 81, 25));
        sizePolicy1.setHeightForWidth(firstTimeSunday->sizePolicy().hasHeightForWidth());
        firstTimeSunday->setSizePolicy(sizePolicy1);
        secondTimeSunday = new QTimeEdit(mSundayGroupBox);
        secondTimeSunday->setObjectName(QString::fromUtf8("secondTimeSunday"));
        secondTimeSunday->setEnabled(false);
        secondTimeSunday->setGeometry(QRect(10, 90, 81, 25));
        sizePolicy1.setHeightForWidth(secondTimeSunday->sizePolicy().hasHeightForWidth());
        secondTimeSunday->setSizePolicy(sizePolicy1);
        firstCheckBoxSunday = new QCheckBox(mSundayGroupBox);
        firstCheckBoxSunday->setObjectName(QString::fromUtf8("firstCheckBoxSunday"));
        firstCheckBoxSunday->setGeometry(QRect(100, 63, 21, 21));
        sizePolicy1.setHeightForWidth(firstCheckBoxSunday->sizePolicy().hasHeightForWidth());
        firstCheckBoxSunday->setSizePolicy(sizePolicy1);
        secondCheckBoxSunday = new QCheckBox(mSundayGroupBox);
        secondCheckBoxSunday->setObjectName(QString::fromUtf8("secondCheckBoxSunday"));
        secondCheckBoxSunday->setGeometry(QRect(100, 93, 21, 21));
        sizePolicy1.setHeightForWidth(secondCheckBoxSunday->sizePolicy().hasHeightForWidth());
        secondCheckBoxSunday->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(mSundayGroupBox);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        QWidget::setTabOrder(mMondayGroupBox, baseTimeMonday);
        QWidget::setTabOrder(baseTimeMonday, firstTimeMonday);
        QWidget::setTabOrder(firstTimeMonday, firstCheckBoxMonday);
        QWidget::setTabOrder(firstCheckBoxMonday, secondTimeMonday);
        QWidget::setTabOrder(secondTimeMonday, secondCheckBoxMonday);
        QWidget::setTabOrder(secondCheckBoxMonday, mTuesdayGroupBox);
        QWidget::setTabOrder(mTuesdayGroupBox, baseTimeTuesday);
        QWidget::setTabOrder(baseTimeTuesday, firstTimeTuesday);
        QWidget::setTabOrder(firstTimeTuesday, firstCheckBoxTuesday);
        QWidget::setTabOrder(firstCheckBoxTuesday, secondTimeTuesday);
        QWidget::setTabOrder(secondTimeTuesday, secondCheckBoxTuesday);
        QWidget::setTabOrder(secondCheckBoxTuesday, mWednesdayGroupBox);
        QWidget::setTabOrder(mWednesdayGroupBox, baseTimeWednesday);
        QWidget::setTabOrder(baseTimeWednesday, firstTimeWednesday);
        QWidget::setTabOrder(firstTimeWednesday, firstCheckBoxWednesday);
        QWidget::setTabOrder(firstCheckBoxWednesday, secondTimeWednesday);
        QWidget::setTabOrder(secondTimeWednesday, secondCheckBoxWednesday);
        QWidget::setTabOrder(secondCheckBoxWednesday, mThursdayGroupBox);
        QWidget::setTabOrder(mThursdayGroupBox, baseTimeThursday);
        QWidget::setTabOrder(baseTimeThursday, firstTimeThursday);
        QWidget::setTabOrder(firstTimeThursday, firstCheckBoxThursday);
        QWidget::setTabOrder(firstCheckBoxThursday, secondTimeThursday);
        QWidget::setTabOrder(secondTimeThursday, secondCheckBoxThursday);
        QWidget::setTabOrder(secondCheckBoxThursday, mFridayGroupBox);
        QWidget::setTabOrder(mFridayGroupBox, baseTimeFriday);
        QWidget::setTabOrder(baseTimeFriday, firstTimeFriday);
        QWidget::setTabOrder(firstTimeFriday, firstCheckBoxFriday);
        QWidget::setTabOrder(firstCheckBoxFriday, secondTimeFriday);
        QWidget::setTabOrder(secondTimeFriday, secondCheckBoxFriday);
        QWidget::setTabOrder(secondCheckBoxFriday, mSaturdayGroupBox);
        QWidget::setTabOrder(mSaturdayGroupBox, baseTimeSaturday);
        QWidget::setTabOrder(baseTimeSaturday, firstTimeSaturday);
        QWidget::setTabOrder(firstTimeSaturday, firstCheckBoxSaturday);
        QWidget::setTabOrder(firstCheckBoxSaturday, secondTimeSaturday);
        QWidget::setTabOrder(secondTimeSaturday, secondCheckBoxSaturday);
        QWidget::setTabOrder(secondCheckBoxSaturday, mSundayGroupBox);
        QWidget::setTabOrder(mSundayGroupBox, baseTimeSunday);
        QWidget::setTabOrder(baseTimeSunday, firstTimeSunday);
        QWidget::setTabOrder(firstTimeSunday, firstCheckBoxSunday);
        QWidget::setTabOrder(firstCheckBoxSunday, secondTimeSunday);
        QWidget::setTabOrder(secondTimeSunday, secondCheckBoxSunday);
        QWidget::setTabOrder(secondCheckBoxSunday, spinBoxDelay);
        QWidget::setTabOrder(spinBoxDelay, pushButtonHidden);

        retranslateUi(drawingform);
        QObject::connect(firstCheckBoxMonday, SIGNAL(toggled(bool)), firstTimeMonday, SLOT(setEnabled(bool)));
        QObject::connect(secondCheckBoxMonday, SIGNAL(toggled(bool)), secondTimeMonday, SLOT(setEnabled(bool)));
        QObject::connect(firstCheckBoxTuesday, SIGNAL(toggled(bool)), firstTimeTuesday, SLOT(setEnabled(bool)));
        QObject::connect(secondCheckBoxTuesday, SIGNAL(toggled(bool)), secondTimeTuesday, SLOT(setEnabled(bool)));
        QObject::connect(firstCheckBoxWednesday, SIGNAL(toggled(bool)), firstTimeWednesday, SLOT(setEnabled(bool)));
        QObject::connect(secondCheckBoxWednesday, SIGNAL(toggled(bool)), secondTimeWednesday, SLOT(setEnabled(bool)));
        QObject::connect(firstCheckBoxThursday, SIGNAL(toggled(bool)), firstTimeThursday, SLOT(setEnabled(bool)));
        QObject::connect(secondCheckBoxThursday, SIGNAL(toggled(bool)), secondTimeThursday, SLOT(setEnabled(bool)));
        QObject::connect(firstCheckBoxFriday, SIGNAL(toggled(bool)), firstTimeFriday, SLOT(setEnabled(bool)));
        QObject::connect(secondCheckBoxFriday, SIGNAL(toggled(bool)), secondTimeFriday, SLOT(setEnabled(bool)));
        QObject::connect(firstCheckBoxSaturday, SIGNAL(toggled(bool)), firstTimeSaturday, SLOT(setEnabled(bool)));
        QObject::connect(secondCheckBoxSaturday, SIGNAL(toggled(bool)), secondTimeSaturday, SLOT(setEnabled(bool)));
        QObject::connect(firstCheckBoxSunday, SIGNAL(toggled(bool)), firstTimeSunday, SLOT(setEnabled(bool)));
        QObject::connect(secondCheckBoxSunday, SIGNAL(toggled(bool)), secondTimeSunday, SLOT(setEnabled(bool)));
        QObject::connect(pushButtonHidden, SIGNAL(clicked()), drawingform, SLOT(hide()));

        QMetaObject::connectSlotsByName(drawingform);
    } // setupUi

    void retranslateUi(QWidget *drawingform)
    {
        drawingform->setWindowTitle(QApplication::translate("drawingform", "Ustawienia losowania", 0, QApplication::UnicodeUTF8));
        mMondayGroupBox->setTitle(QApplication::translate("drawingform", "Poniedzia\305\202ek", 0, QApplication::UnicodeUTF8));
        firstCheckBoxMonday->setText(QString());
        secondCheckBoxMonday->setText(QString());
        mTuesdayGroupBox->setTitle(QApplication::translate("drawingform", "Wtorek", 0, QApplication::UnicodeUTF8));
        firstCheckBoxTuesday->setText(QString());
        secondCheckBoxTuesday->setText(QString());
        mWednesdayGroupBox->setTitle(QApplication::translate("drawingform", "\305\232roda", 0, QApplication::UnicodeUTF8));
        firstCheckBoxWednesday->setText(QString());
        secondCheckBoxWednesday->setText(QString());
        groupBoxDelay->setTitle(QString());
        pushButtonHidden->setText(QApplication::translate("drawingform", "Ukryj", 0, QApplication::UnicodeUTF8));
        delayLabel->setText(QApplication::translate("drawingform", "Op\303\263\305\272nienie\n"
"losowania:", 0, QApplication::UnicodeUTF8));
        spinBoxDelay->setSuffix(QApplication::translate("drawingform", " minut", 0, QApplication::UnicodeUTF8));
        spinBoxDelay->setPrefix(QApplication::translate("drawingform", "o ", 0, QApplication::UnicodeUTF8));
        mThursdayGroupBox->setTitle(QApplication::translate("drawingform", "Czwartek", 0, QApplication::UnicodeUTF8));
        firstCheckBoxThursday->setText(QString());
        secondCheckBoxThursday->setText(QString());
        mFridayGroupBox->setTitle(QApplication::translate("drawingform", "Pi\304\205tek", 0, QApplication::UnicodeUTF8));
        firstCheckBoxFriday->setText(QString());
        secondCheckBoxFriday->setText(QString());
        mSaturdayGroupBox->setTitle(QApplication::translate("drawingform", "Sobota", 0, QApplication::UnicodeUTF8));
        firstCheckBoxSaturday->setText(QString());
        secondCheckBoxSaturday->setText(QString());
        mSundayGroupBox->setTitle(QApplication::translate("drawingform", "Niedziela", 0, QApplication::UnicodeUTF8));
        firstCheckBoxSunday->setText(QString());
        secondCheckBoxSunday->setText(QString());
        Q_UNUSED(drawingform);
    } // retranslateUi

};

namespace Ui {
    class drawingform: public Ui_drawingform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWINGFORM_H
