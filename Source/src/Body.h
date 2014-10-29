/********************************************************************
 *                                                                 *
 * Created:      29.10.2014                                        *
 *                                                                 *
********************************************************************/

#ifndef BODY_H
#define BODY_H

// Qt includes -----------------------------
#include <QWidget>

class Body : public QWidget
{
    Q_OBJECT

  public:

    Body(QWidget *parent = 0);
    virtual ~Body();

  protected:

    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *);

};

#endif // BODY_H
