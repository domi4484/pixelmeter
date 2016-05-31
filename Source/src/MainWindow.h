#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt includes -----------------------------
#include <QMainWindow>

// Forward declarations --------------------
namespace Ui { class MainWindow; }
class RulerDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
    
private slots:

  void on_m_QToolButton_Ruler_toggled(bool checked);

  void on_m_QToolButton_Ruler_Rotate_clicked();

private:

  Ui::MainWindow *m_Ui;

  RulerDialog *m_RulerDialog;
};

#endif // MAINWINDOW_H
