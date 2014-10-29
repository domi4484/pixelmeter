
// Files includes --------------------------
#include "MainWindow.h"
#include "ui_MainWindow.h"

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent,
              Qt::FramelessWindowHint),
  m_Ui(new Ui::MainWindow)
{
  // Qt ui setup
  m_Ui->setupUi(this);

  // Make transparent
  setAttribute(Qt::WA_TranslucentBackground);
}

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
  delete m_Ui;
}

//-----------------------------------------------------------------------------------------------------------------------------

void MainWindow::resizeEvent(QResizeEvent *)
{
  m_Ui->m_QLcdNumber_Width->display(width());
  m_Ui->m_QLcdNumber_Height->display(height());
}

//-----------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_m_QPushButton_1_clicked()
{

}

//-----------------------------------------------------------------------------------------------------------------------------

