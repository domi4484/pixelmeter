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

    explicit Body(QWidget *parent = 0);
    virtual ~Body();

  protected:

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *);

  signals:

    void signal_moveRequest(const QPoint &pos);

  public:

    QPoint m_ClickPos;

};

#endif // BODY_H
