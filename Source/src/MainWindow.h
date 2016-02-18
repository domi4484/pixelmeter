#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt includes -----------------------------
#include <QMainWindow>

// Forward declarations --------------------
namespace Ui { class MainWindow; }
class Body;
class RulerGraphicsView;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
    
protected:
  virtual void resizeEvent(QResizeEvent *);

private slots:

  void slot_MoveWindow(const QPoint &point);

  void on_m_QPushButton_1_clicked();

private:
  Ui::MainWindow *m_Ui;

  Body *m_Body;

  RulerGraphicsView *m_RulerGraphicsView;

};

#endif // MAINWINDOW_H
