/********************************************************************
 *                                                                 *
 * Created:      29.10.2014                                        *
 *                                                                 *
********************************************************************/

#ifndef SLIDER_H
#define SLIDER_H

// Qt includes -----------------------------
#include <QWidget>

class Slider : public QWidget
{
    Q_OBJECT

  public:
    explicit Slider(QWidget *parent = 0);
    virtual ~Slider();

  signals:

  public slots:

};

#endif // SLIDER_H
