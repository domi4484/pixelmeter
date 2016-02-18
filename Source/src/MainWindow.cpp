
// Files includes --------------------------
#include "MainWindow.h"
#include "ui_MainWindow.h"

// Project includes ------------------------
#include "Body.h"
#include "Ruler.h"
#include "RulerGraphicsView.h"

// Qt includes -----------------------------
#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent,
              Qt::FramelessWindowHint),
  m_Ui(new Ui::MainWindow),
  m_Body(NULL),
  m_RulerGraphicsView(NULL)
{
  // Qt ui setup
  m_Ui->setupUi(this);

  // Make transparent
  setAttribute(Qt::WA_TranslucentBackground);

  m_RulerGraphicsView = new RulerGraphicsView;

  QMainWindow::setCentralWidget(m_RulerGraphicsView);
  QMainWindow::resize(2*qMax(m_RulerGraphicsView->ruler()->height(), m_RulerGraphicsView->ruler()->width()),
                      2*qMax(m_RulerGraphicsView->ruler()->height(), m_RulerGraphicsView->ruler()->width()));

  connect(m_RulerGraphicsView->ruler(),
          SIGNAL(signal_MoveWindow(QPoint)),
          SLOT(slot_MoveWindow(QPoint)));

}

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
  delete m_RulerGraphicsView;

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

