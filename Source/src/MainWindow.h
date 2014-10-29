#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
  protected:
    virtual void resizeEvent(QResizeEvent *);

  private slots:
    void on_m_QPushButton_1_clicked();

  private:
    Ui::MainWindow *m_Ui;

};

#endif // MAINWINDOW_H
