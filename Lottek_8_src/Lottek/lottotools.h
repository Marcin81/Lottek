#ifndef LOTTOTOOLS_H
#define LOTTOTOOLS_H
#include <QSpinBox>
#include <QStringList>
#include <QDateTime>
#include "dayofweek.h"
#include <map>

class Ui_drawingform;
class QCheckBox;
class QGroupBox;
class QTimeEdit;

class LottoTools
{
public:
  LottoTools();
  ~LottoTools();

  static const QStringList getLottoNumbers( const QString& pageHtlmText );
  static QDate getLottoDateFromWWW( const QString& pageHtlmText );

  static QDateTime getNextLottoDate( const std::multimap< DayOfWeek, QTime >& lottoDaysWithHours );

  static QDateTime getLastLottoDate( const QDate& lastLottoDate,
         const std::multimap< DayOfWeek, QTime >& lottoDaysWithHours );

  static int randomNumber( const unsigned& number );

  static const int compareNumbers( const QStringList& list,
    QSpinBox* spinBox_1, QSpinBox* spinBox_2, QSpinBox* spinBox_3,
    QSpinBox* spinBox_4, QSpinBox* spinBox_5, QSpinBox* spinBox_6 );

  static void fillLottoDaysIfChecked( Qt::DayOfWeek day, QCheckBox* checkbox,
    QTimeEdit* timeEd, std::multimap< DayOfWeek, QTime >& lottoDaysWithHours );

  static void fillLottoDaysIfChecked( QGroupBox* group, Qt::DayOfWeek day,
    QTimeEdit* timeBase, QTimeEdit* timeFirst, QTimeEdit* timeSecond,
    QCheckBox* checkboxFirst, QCheckBox* checkboxSecond,
    std::multimap< DayOfWeek, QTime >& lottoDaysWithHours );

  static void fillLottoDaysWithHours( Ui_drawingform* drawingForm,
    std::multimap< DayOfWeek, QTime >& lottoDaysWithHours );

  static void sortLottoDays( std::multimap< DayOfWeek, QTime >& lottoDays );
};

#endif // LOTTOTOOLS_H
