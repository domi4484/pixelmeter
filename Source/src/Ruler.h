#ifndef RULER_H
#define RULER_H

#include <QWidget>

namespace Ui {
  class Ruler;
}

class Ruler : public QWidget
{
  Q_OBJECT

public:
  explicit Ruler(QWidget *parent = 0);
  ~Ruler();

  void rotate();

signals:

  void signal_MoveWindow(QPoint);
  void signal_Rotate();

protected:

  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *);

private slots:
  void on_m_QToolButton_Rotate_clicked();

private:

  Ui::Ruler *m_Ui;

  QPixmap m_QPixmap;

  QPoint m_QPoint_PressEventRelativePosition;

  int m_Angle;

};

#endif // RULER_H
