#ifndef DAYOFWEEK_H
#define DAYOFWEEK_H
#include <Qt>

class DayOfWeek
{
public:
    DayOfWeek( Qt::DayOfWeek day );
    DayOfWeek( const DayOfWeek& day);
    ~DayOfWeek();

    DayOfWeek& operator=( const DayOfWeek& day );

    void setDay( const int day );
    void setDay( Qt::DayOfWeek day );

    Qt::DayOfWeek getDayOfWeek() const { return mDay; }
    const int getDay() const { return static_cast< const int >( mDay ); }

    friend bool operator<( const DayOfWeek& leftDay, const DayOfWeek& rightDay );
    friend bool operator==( const DayOfWeek& leftDay, const DayOfWeek& rightDay );

private:
    Qt::DayOfWeek mDay;
};

#endif // DAYOFWEEK_H
