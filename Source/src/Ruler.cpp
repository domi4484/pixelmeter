
// Files includes --------------------------
#include "Ruler.h"
#include "ui_Ruler.h"

// Qt includes -----------------------------
#include <QMouseEvent>

//-----------------------------------------------------------------------------------------------------------------------------

Ruler::Ruler(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Ruler)
{
  ui->setupUi(this);
}

//-----------------------------------------------------------------------------------------------------------------------------

Ruler::~Ruler()
{
  delete ui;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Ruler::mousePressEvent(QMouseEvent *event)
{
  m_QPoint_LastMousePosition = event->pos();
}

//-----------------------------------------------------------------------------------------------------------------------------

void Ruler::mouseMoveEvent(QMouseEvent *event)
{
  emit signal_MoveWindow(event->globalPos() - m_QPoint_LastMousePosition);
}

//-----------------------------------------------------------------------------------------------------------------------------

void Ruler::on_m_QToolButton_Rotate_clicked()
{
  emit signal_Rotate();
}
