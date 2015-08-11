#include "spinboxdecorator.h"
#include <QSpinBox>
/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
*/
SpinBoxDecorator::SpinBoxDecorator( QSpinBox* spinBox,
  const int row )
  : mSpinBox( spinBox ),
    mRow( row )
{
  mOldValue = mSpinBox->value();
  mSpinBox->connect( mSpinBox, SIGNAL(valueChanged(int)),
                     this, SLOT(serviceValueChanged(int)) );
}

SpinBoxDecorator::~SpinBoxDecorator()
{

}

void SpinBoxDecorator::serviceValueChanged( int value )
{
  emit valueChanged();
}

void SpinBoxDecorator::changeValueWthOutSignal( int value )
{
  mSpinBox->disconnect( mSpinBox, SIGNAL( valueChanged(int) ),
                     this, SLOT( serviceValueChanged(int) ) );
  mSpinBox->setValue( value );
  mOldValue = value;
  mSpinBox->connect( mSpinBox, SIGNAL(valueChanged(int)),
                     this, SLOT(serviceValueChanged(int)) );
}

void SpinBoxDecorator::setPreviewValue( const int value )
{
  mOldValue = value;
}
