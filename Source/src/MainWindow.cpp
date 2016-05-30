
// Files includes --------------------------
#include "MainWindow.h"
#include "ui_MainWindow.h"

// Project includes ------------------------
#include "RulerDialog.h"

// Qt includes -----------------------------
#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  m_Ui(new Ui::MainWindow),
  m_RulerDialog(NULL)
{
  // Qt ui setup
  m_Ui->setupUi(this);

  m_RulerDialog = new RulerDialog(this);
  m_RulerDialog->hide();
}

//-----------------------------------------------------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
  delete m_Ui;
}

//-----------------------------------------------------------------------------------------------------------------------------


void MainWindow::on_m_QToolButton_Ruler_toggled(bool checked)
{
  if(checked)
  {
    m_RulerDialog->show();
  }
  else
  {
    m_RulerDialog->hide();
  }
}
