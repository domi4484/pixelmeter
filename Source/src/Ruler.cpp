
// Files includes --------------------------
#include "Ruler.h"
#include "ui_Ruler.h"

// Qt includes -----------------------------
#include <QDebug>
#include <QMouseEvent>

//-----------------------------------------------------------------------------------------------------------------------------

Ruler::Ruler(QWidget *parent) :
  QWidget(parent),
  m_Ui(new Ui::Ruler),
  m_QPixmap(":/images/ruler/Ruler.png")
{
  m_Ui->setupUi(this);

  m_Ui->m_QLabel_Ruler->setPixmap(m_QPixmap);


  QWidget::setMinimumSize(m_QPixmap.size());
  QWidget::resize(m_QPixmap.size());
}

//-----------------------------------------------------------------------------------------------------------------------------

Ruler::~Ruler()
{
  delete m_Ui;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Ruler::mousePressEvent(QMouseEvent *event)
{
  m_QPoint_PressEventRelativePosition = event->pos();
}

//-----------------------------------------------------------------------------------------------------------------------------

void Ruler::mouseMoveEvent(QMouseEvent *)
{
  emit signal_MoveWindow(QCursor::pos() - m_QPoint_PressEventRelativePosition);
}

//-----------------------------------------------------------------------------------------------------------------------------

void Ruler::on_m_QToolButton_Rotate_clicked()
{
  emit signal_Rotate();
}
