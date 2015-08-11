#ifndef COLORCHANGER_H
#define COLORCHANGER_H

#include <QStringList>
#include <QColor>
#include <QFont>

class QSpinBox;

class ColorChanger
{

  QColor color;
  QColor defaultColor;
  QFont defaultFont;
  QFont font;

  void changeColorsAndFont( QSpinBox* spinBox, const QColor& newColor,
                            const QFont& font );
public:
  ColorChanger( const QFont mainFont, const QFont newFont,
    const QColor mainColor, const QColor newColor = Qt::darkGreen );

 ~ColorChanger();

 void changeColorsAndFont( QSpinBox* spinBox, const bool canChange );

  QColor getNewColor() const { return color; }
  QColor getDefaultColor() const { return defaultColor; }

  QFont getDefaultFont() const { return defaultFont; }
  QFont getNewFont() const { return font; }
};

#endif // COLORCHANGER_H
