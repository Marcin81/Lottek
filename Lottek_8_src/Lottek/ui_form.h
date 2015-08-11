/********************************************************************************
** Form generated from reading ui file 'form.ui'
**
** Created: Sun Nov 8 11:45:32 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
** License: GPL 
** Owner: Marcin Brysz
** Contact: unemployed81@gmail.com / bryszmarcin@gmail.com

********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QSpinBox *spinBox_1;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QLabel *label_3;
    QLineEdit *lineEditLottoNumbers;
    QPushButton *pushButtonRandom;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QPushButton *pushButtonCheck;
    QPushButton *pushButtonHide;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(680, 307);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(680, 307));
        Form->setMaximumSize(QSize(680, 307));
        Form->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 650, 291));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(20);
        sizePolicy1.setVerticalStretch(20);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 129, 17));
        spinBox_1 = new QSpinBox(groupBox);
        spinBox_1->setObjectName(QString::fromUtf8("spinBox_1"));
        spinBox_1->setGeometry(QRect(10, 50, 51, 25));
        spinBox_1->setMinimum(1);
        spinBox_1->setMaximum(49);
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(70, 50, 51, 25));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(49);
        spinBox_2->setValue(2);
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(130, 50, 51, 25));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(49);
        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(190, 50, 51, 25));
        spinBox_4->setMinimum(1);
        spinBox_4->setMaximum(49);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 216, 148, 17));
        lineEditLottoNumbers = new QLineEdit(groupBox);
        lineEditLottoNumbers->setObjectName(QString::fromUtf8("lineEditLottoNumbers"));
        lineEditLottoNumbers->setGeometry(QRect(10, 240, 221, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditLottoNumbers->sizePolicy().hasHeightForWidth());
        lineEditLottoNumbers->setSizePolicy(sizePolicy2);
        lineEditLottoNumbers->setMaxLength(17);
        lineEditLottoNumbers->setEchoMode(QLineEdit::Normal);
        lineEditLottoNumbers->setReadOnly(true);
        pushButtonRandom = new QPushButton(groupBox);
        pushButtonRandom->setObjectName(QString::fromUtf8("pushButtonRandom"));
        pushButtonRandom->setGeometry(QRect(530, 46, 111, 41));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonRandom->sizePolicy().hasHeightForWidth());
        pushButtonRandom->setSizePolicy(sizePolicy3);
        spinBox_5 = new QSpinBox(groupBox);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(250, 50, 51, 25));
        spinBox_5->setMinimum(1);
        spinBox_5->setMaximum(49);
        spinBox_6 = new QSpinBox(groupBox);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(310, 50, 51, 25));
        spinBox_6->setMinimum(1);
        spinBox_6->setMaximum(49);
        pushButtonCheck = new QPushButton(groupBox);
        pushButtonCheck->setObjectName(QString::fromUtf8("pushButtonCheck"));
        pushButtonCheck->setEnabled(true);
        pushButtonCheck->setGeometry(QRect(470, 235, 81, 41));
        sizePolicy3.setHeightForWidth(pushButtonCheck->sizePolicy().hasHeightForWidth());
        pushButtonCheck->setSizePolicy(sizePolicy3);
        pushButtonHide = new QPushButton(groupBox);
        pushButtonHide->setObjectName(QString::fromUtf8("pushButtonHide"));
        pushButtonHide->setGeometry(QRect(550, 235, 81, 41));
        sizePolicy3.setHeightForWidth(pushButtonHide->sizePolicy().hasHeightForWidth());
        pushButtonHide->setSizePolicy(sizePolicy3);
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 90, 500, 121));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 496, 117));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButtonAdd = new QPushButton(groupBox);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(520, 100, 121, 41));
        pushButtonDelete = new QPushButton(groupBox);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setEnabled(false);
        pushButtonDelete->setGeometry(QRect(520, 140, 121, 41));
        QWidget::setTabOrder(spinBox_1, spinBox_2);
        QWidget::setTabOrder(spinBox_2, spinBox_3);
        QWidget::setTabOrder(spinBox_3, spinBox_4);
        QWidget::setTabOrder(spinBox_4, spinBox_5);
        QWidget::setTabOrder(spinBox_5, spinBox_6);
        QWidget::setTabOrder(spinBox_6, scrollArea);
        QWidget::setTabOrder(scrollArea, pushButtonRandom);
        QWidget::setTabOrder(pushButtonRandom, pushButtonAdd);
        QWidget::setTabOrder(pushButtonAdd, pushButtonDelete);
        QWidget::setTabOrder(pushButtonDelete, lineEditLottoNumbers);
        QWidget::setTabOrder(lineEditLottoNumbers, pushButtonCheck);
        QWidget::setTabOrder(pushButtonCheck, pushButtonHide);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Du\305\274y lotek", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Form", "Ustawienia", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Twoje numery totka:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_1->setToolTip(QApplication::translate("Form", "Numer 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_2->setToolTip(QApplication::translate("Form", "Numer 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_3->setToolTip(QApplication::translate("Form", "Numer 3", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_4->setToolTip(QApplication::translate("Form", "Numer 4", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Form", "Aktualne numery totka:", 0, QApplication::UnicodeUTF8));
        pushButtonRandom->setText(QApplication::translate("Form", "Wylosuj", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinBox_5->setToolTip(QApplication::translate("Form", "Numer 5", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        spinBox_6->setToolTip(QApplication::translate("Form", "Numer 6", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButtonCheck->setText(QApplication::translate("Form", "Sprawd\305\272", 0, QApplication::UnicodeUTF8));
        pushButtonHide->setText(QApplication::translate("Form", "Ukryj", 0, QApplication::UnicodeUTF8));
        pushButtonAdd->setText(QApplication::translate("Form", "Dodaj", 0, QApplication::UnicodeUTF8));
        pushButtonDelete->setText(QApplication::translate("Form", "Usu\305\204", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
