#ifndef RULERDIALOG_H
#define RULERDIALOG_H

// Qt includes -----------------------------
#include <QDialog>

// Forward declarations --------------------
class RulerGraphicsView;

class RulerDialog : public QDialog
{
  Q_OBJECT

public:

  explicit RulerDialog(QWidget *parent = 0);
  ~RulerDialog();

private slots:

  void slot_MoveWindow(const QPoint &point);

private:

  RulerGraphicsView *m_RulerGraphicsView;
};

#endif // RULERDIALOG_H
