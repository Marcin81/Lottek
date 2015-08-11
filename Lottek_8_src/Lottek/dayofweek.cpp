#include "dayofweek.h"

DayOfWeek::DayOfWeek( Qt::DayOfWeek day )
  : mDay( day )
{

}

DayOfWeek::DayOfWeek( const DayOfWeek& day)
{
  mDay = day.mDay;
}

DayOfWeek::~DayOfWeek()
{

}

DayOfWeek& DayOfWeek::operator=( const DayOfWeek& day )
{
  if( this == &day )
    return *this;
  mDay = day.mDay;
  return *this;
}

void DayOfWeek::setDay( const int day )
{
  mDay = static_cast< Qt::DayOfWeek > ( day );
}

void DayOfWeek::setDay( Qt::DayOfWeek day )
{
    mDay = day;
}

/*friend*/ bool operator<( const DayOfWeek& leftDay, const DayOfWeek& rightDay )
{
      return leftDay.mDay < rightDay.mDay;
}

/*friend*/ bool operator==( const DayOfWeek& leftDay, const DayOfWeek& rightDay )
{
      return leftDay.mDay == rightDay.mDay;
}
