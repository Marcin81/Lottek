/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
*/
#include "lottotools.h"
#include <boost/assign/list_of.hpp>
#include <boost/foreach.hpp>
#include <boost/random.hpp>
#include <boost/random/uniform_smallint.hpp>
#include <QRegExp>
#include "ui_drawingform.h"
#include <QCheckBox>
#include <QGroupBox>
#include <QTimeEdit>
#include <ctime>

LottoTools::LottoTools()
{

}

LottoTools::~LottoTools()
{

}

const int LottoTools::compareNumbers( const QStringList& list,
  QSpinBox* spinBox_1, QSpinBox* spinBox_2, QSpinBox* spinBox_3,
  QSpinBox* spinBox_4, QSpinBox* spinBox_5, QSpinBox* spinBox_6 )
{
  std::list< QSpinBox* > values = boost::assign::list_of
    ( spinBox_1 ) ( spinBox_2 )
    ( spinBox_3 ) ( spinBox_4 )
    ( spinBox_5 ) ( spinBox_6 );

  QStringList tempList = list;
  int count = 0;
  BOOST_FOREACH( QSpinBox* spin, values ) {
     const QString number = QString::number( spin->value() );
     if( tempList.contains( number ) ) {
      count++;
      tempList.removeAll( number );// Liczby w totku nie mogą się powtarzac
    }
  }// byl bug -> chyba jak liczba sie powtarza to niepotrzebnie ja zlicza
  return count;
}

const QStringList LottoTools::getLottoNumbers( const QString& pageHtlmText )
{
  QRegExp rx( "dl\\d{1}-->(\\d{1,2})" );
  QStringList list;
  int pos = 0;

  while ((pos = rx.indexIn(pageHtlmText, pos)) != -1) {
    list << ( ( rx.cap(1).isEmpty() ) ? "" : rx.cap(1) );
    pos += rx.matchedLength();
  }

  return list;
}

QDate LottoTools::getLottoDateFromWWW( const QString& pageHtlmText )
{
  QRegExp rx( "<!--data_dl-->(\\d{4}-\\d{2}-\\d{2})" );
  const int pos = rx.indexIn( pageHtlmText );
  QString results;
  if( pos > -1 )
    results = rx.cap( 1 );
  return QDate::fromString( results, "yyyy-MM-dd" );
}

// Kontener musi być posortowany wg. klucza, potem wg. godzin
QDateTime LottoTools::getNextLottoDate( const std::multimap< DayOfWeek, QTime >& lottoDaysWithHours )
{
  QDate searchDate = QDate::currentDate();
  Qt::DayOfWeek today = static_cast< Qt::DayOfWeek > ( searchDate.dayOfWeek() );
  // WYszukiwanie najblizszego dnia losowania
  std::multimap< DayOfWeek, QTime >::const_iterator it = lottoDaysWithHours.find( today );
  while( it == lottoDaysWithHours.end() ) {
    searchDate = searchDate.addDays( 1 );
    today = static_cast< Qt::DayOfWeek > ( searchDate.dayOfWeek() );
    it = lottoDaysWithHours.find( today );
  }
  // Wyszukiwanie najbliższej godziny losowania w tym dniu (jesli jest kilka)
  return QDateTime( searchDate, (*it).second );
}

// Kontener musi być posortowany wg. klucza, potem wg. godzin
QDateTime LottoTools::getLastLottoDate( const QDate& lastLottoDate,
  const std::multimap< DayOfWeek, QTime >& lottoDaysWithHours )
{
  QDate searchDate = lastLottoDate; // Moze data jest zla ?
  Qt::DayOfWeek today = static_cast< Qt::DayOfWeek > ( searchDate.dayOfWeek() );

  std::multimap< DayOfWeek, QTime >::const_iterator it = lottoDaysWithHours.find( today );
  while( it == lottoDaysWithHours.end() ) {
    searchDate = searchDate.addDays( 1 );
    today = static_cast< Qt::DayOfWeek > ( searchDate.dayOfWeek() );
    it = lottoDaysWithHours.find( today );
  }

  return QDateTime( searchDate, (*it).second );
}

int LottoTools::randomNumber( const unsigned& number )
{
  boost::mt19937 rng; // produces randomness out of thin air
  srand( number );
  rng.seed( rand() + time(0) + number );
  boost::uniform_smallint<> fourty_nine(1,49); // distribution that maps to 1..49

  boost::variate_generator<boost::mt19937&, boost::uniform_smallint<> >
          die(rng, fourty_nine);// glues randomness with mapping
  return die(); // simulate rolling a die
}

void LottoTools::fillLottoDaysIfChecked( Qt::DayOfWeek day, QCheckBox* checkbox,
     QTimeEdit* timeEd, std::multimap< DayOfWeek, QTime >& lottoDaysWithHours )
{
  if( checkbox->isChecked() )
    lottoDaysWithHours.insert( std::make_pair( DayOfWeek( day ), timeEd->time() ) );
}

void LottoTools::fillLottoDaysIfChecked( QGroupBox* group, Qt::DayOfWeek day,
  QTimeEdit* timeBase, QTimeEdit* timeFirst, QTimeEdit* timeSecond,
  QCheckBox* checkboxFirst, QCheckBox* checkboxSecond,
  std::multimap< DayOfWeek, QTime >& lottoDaysWithHours )
{
  if( group->isChecked() ) {
    lottoDaysWithHours.insert( std::make_pair( DayOfWeek( day ), timeBase->time() ) );
    fillLottoDaysIfChecked( day, checkboxFirst, timeFirst, lottoDaysWithHours );
    fillLottoDaysIfChecked( day, checkboxSecond, timeSecond, lottoDaysWithHours );
  } //if
}

void LottoTools::fillLottoDaysWithHours( Ui_drawingform* drawingForm,
  std::multimap< DayOfWeek, QTime >& lottoDaysWithHours )
{
  fillLottoDaysIfChecked( drawingForm->mMondayGroupBox,
    Qt::Monday, drawingForm->baseTimeMonday,
    drawingForm->firstTimeMonday, drawingForm->secondTimeMonday,
    drawingForm->firstCheckBoxMonday, drawingForm->secondCheckBoxMonday,
    lottoDaysWithHours );
  //-------------------------------------------------
  fillLottoDaysIfChecked( drawingForm->mTuesdayGroupBox,
    Qt::Tuesday, drawingForm->baseTimeTuesday,
    drawingForm->firstTimeTuesday, drawingForm->secondTimeTuesday,
    drawingForm->firstCheckBoxTuesday, drawingForm->secondCheckBoxTuesday,
    lottoDaysWithHours );
  //-------------------------------------------------
  fillLottoDaysIfChecked( drawingForm->mWednesdayGroupBox,
    Qt::Wednesday, drawingForm->baseTimeWednesday,
    drawingForm->firstTimeWednesday, drawingForm->secondTimeWednesday,
    drawingForm->firstCheckBoxWednesday, drawingForm->secondCheckBoxWednesday,
    lottoDaysWithHours );
  //-------------------------------------------------
  fillLottoDaysIfChecked( drawingForm->mThursdayGroupBox,
    Qt::Thursday, drawingForm->baseTimeThursday,
    drawingForm->firstTimeThursday, drawingForm->secondTimeThursday,
    drawingForm->firstCheckBoxThursday, drawingForm->secondCheckBoxThursday,
    lottoDaysWithHours );
  //-------------------------------------------------
  fillLottoDaysIfChecked( drawingForm->mFridayGroupBox,
    Qt::Friday, drawingForm->baseTimeFriday,
    drawingForm->firstTimeFriday, drawingForm->secondTimeFriday,
    drawingForm->firstCheckBoxFriday, drawingForm->secondCheckBoxFriday,
    lottoDaysWithHours );
  //-------------------------------------------------
  fillLottoDaysIfChecked( drawingForm->mSaturdayGroupBox,
    Qt::Saturday, drawingForm->baseTimeSaturday,
    drawingForm->firstTimeSaturday, drawingForm->secondTimeSaturday,
    drawingForm->firstCheckBoxSaturday, drawingForm->secondCheckBoxSaturday,
    lottoDaysWithHours );
  //-------------------------------------------------
  fillLottoDaysIfChecked( drawingForm->mSundayGroupBox,
    Qt::Sunday, drawingForm->baseTimeSunday,
    drawingForm->firstTimeSunday, drawingForm->secondTimeSunday,
    drawingForm->firstCheckBoxSunday, drawingForm->secondCheckBoxSunday,
    lottoDaysWithHours );
  //-------------------------------------------------
}

void LottoTools::sortLottoDays( std::multimap< DayOfWeek, QTime >& lottoDays )
{
  // Dni sa juz posortowane, trzeba tylko posortowac godziny w danym dniu
  for( std::multimap< DayOfWeek, QTime >::iterator it = lottoDays.begin();
    it != lottoDays.end(); it++ ) {
      std::multimap< DayOfWeek, QTime >::iterator check = it;
      check++;
      if( check != lottoDays.end() ) {
          std::pair< const DayOfWeek, QTime > p1( *it );
          std::pair< const DayOfWeek, QTime > p2( *check );
        if( ( p1.first.getDayOfWeek() == p2.first.getDayOfWeek() )
          && (p1.second > p2.second )
          ) {

          /**DayOfWeek& d1 = const_cast< DayOfWeek& > ( (*it).first );
          d1.setDay( p2.first.getDayOfWeek() );*/
          (*it).second = p2.second;
          
         /* DayOfWeek& d2 = const_cast< DayOfWeek& > ( (*check).first );
          d2.setDay( p1.first.getDayOfWeek() );*/
          (*check).second = p1.second;
        } //if

      } //if
  } //for
  //---------------------------------------
   for( std::multimap< DayOfWeek, QTime >::iterator it = lottoDays.begin();
    it != lottoDays.end(); it++ ) {
      std::multimap< DayOfWeek, QTime >::iterator check = it;
      check++;
      if( check != lottoDays.end() ) {
          std::pair< const DayOfWeek, QTime > p1( *it );
          std::pair< const DayOfWeek, QTime > p2( *check );
        if( ( p1.first.getDayOfWeek() == p2.first.getDayOfWeek() )
          && (p1.second > p2.second )
          ) {
          (*it).second = p2.second;
          (*check).second = p1.second;
        } //if

      } //if
  } //for
}

