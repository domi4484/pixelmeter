
// Files includes --------------------------
#include "MainWindow.h"
#include "ui_MainWindow.h"

// Project includes ------------------------
#include "Body.h"
#include "Ruler.h"

// Qt includes -----------------------------
#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent,
              Qt::FramelessWindowHint),
  m_Ui(new Ui::MainWindow),
  m_Body(NULL),
  m_Ruler(NULL)
{
  // Qt ui setup
  m_Ui->setupUi(this);

  // Make transparent
//  setAttribute(Qt::WA_TranslucentBackground);

  m_Ruler = new Ruler;

  QMainWindow::setCentralWidget(m_Ruler);
  QMainWindow::resize(800, 70);

  connect(m_Ruler,
          SIGNAL(moveWindow(QPoint)),
          SLOT(slot_MoveWindow(QPoint)));

}

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
  delete m_Ruler;

  delete m_Ui;
}

//-----------------------------------------------------------------------------------------------------------------------------

void MainWindow::resizeEvent(QResizeEvent *)
{
  m_Ui->m_QLcdNumber_Width  ->display(QMainWindow::width());
  m_Ui->m_QLcdNumber_Height ->display(QMainWindow::height());

  qDebug() << QMainWindow::size();
}

//-----------------------------------------------------------------------------------------------------------------------------

void MainWindow::slot_MoveWindow(const QPoint &point)
{
  QMainWindow::move(point);
}

//-----------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_m_QPushButton_1_clicked()
{

}

//-----------------------------------------------------------------------------------------------------------------------------

