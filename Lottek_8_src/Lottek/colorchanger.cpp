/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
*/
#include "colorchanger.h"
#include <QWidget>
#include <QSpinBox>
#include <QPalette>
#include <QBrush>
#include <QFocusEvent>

ColorChanger::ColorChanger( const QFont mainFont, const QFont newFont,
  const QColor mainColor, const QColor newColor )
  : color( newColor ),
    defaultColor( mainColor ),
    defaultFont( mainFont ),
    font( newFont )
{

}

ColorChanger::~ColorChanger()
{

}

void ColorChanger::changeColorsAndFont( QSpinBox* spinBox,
  const QColor& newColor, const QFont& newFont )
{
  QPalette palette;
  QBrush brush( newColor );
  brush.setStyle(Qt::SolidPattern);
  palette.setBrush(QPalette::Active, QPalette::Text, brush);
  palette.setBrush(QPalette::Inactive, QPalette::Text, brush);

  spinBox->setPalette(palette);
  spinBox->setFont(newFont);
  spinBox->update();
}

void ColorChanger::changeColorsAndFont( QSpinBox* spinBox, const bool canChange )
{
  if( spinBox ) {
    QPalette palette = spinBox->palette();// Reference

    if( canChange )
      changeColorsAndFont( spinBox, color, font );
    else
      changeColorsAndFont( spinBox, defaultColor, defaultFont );
  } //if
}
