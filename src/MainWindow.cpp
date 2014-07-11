#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  m_Ui(new Ui::MainWindow)
{
  m_Ui->setupUi(this);
  setWindowTitle("Pixel Misurement");
}

MainWindow::~MainWindow()
{
  delete m_Ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
  m_Ui->m_QLcdNumber_Width->display(width());
  m_Ui->m_QLcdNumber_Height->display(height());
}
