#ifndef SPINBOXDECORATOR_H
#define SPINBOXDECORATOR_H

#include <boost/utility.hpp>
#include <QObject>

class QSpinBox;

class SpinBoxDecorator : public QObject, boost::noncopyable
{
  Q_OBJECT;
  QSpinBox* mSpinBox;
  int mOldValue;
  const int mRow;

public:
  SpinBoxDecorator( QSpinBox* spinBox, const int row );
  ~SpinBoxDecorator();

  QSpinBox* getSpinBox() { return mSpinBox; }
  const QSpinBox* getSpinBox() const { return mSpinBox; }
  const int getPreviewValue() const { return mOldValue; }
  const int getRow() const { return mRow; }

  void setPreviewValue( const int value );

  void changeValueWthOutSignal( int value );
signals:
  void valueChanged();

private slots:
  void serviceValueChanged( int value );
};

#endif // SPINBOXDECORATOR_H
