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

signals:

  void signal_MoveWindow(QPoint);
  void signal_Rotate();

protected:

  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseMoveEvent(QMouseEvent *event);

private slots:
  void on_m_QToolButton_Rotate_clicked();

private:

  Ui::Ruler *ui;

  QPoint m_QPoint_LastMousePosition;
};

#endif // RULER_H
