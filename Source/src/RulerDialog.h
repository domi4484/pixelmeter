#ifndef RULERDIALOG_H
#define RULERDIALOG_H

// Qt includes -----------------------------
#include <QDialog>

// Forward declarations --------------------
class Ruler;

class RulerDialog : public QDialog
{
  Q_OBJECT

public:

  explicit RulerDialog(QWidget *parent = 0);
  ~RulerDialog();

  void rotate();

private slots:

  void slot_MoveWindow(const QPoint &point);

private:

  Ruler *m_Ruler;
};

#endif // RULERDIALOG_H
