
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
  m_QPixmap(":/images/ruler/Images/Ruler.png"),
  m_QPoint_PressEventRelativePosition(),
  m_Angle(0)
{
  m_Ui->setupUi(this);

  m_Ui->m_QLabel_Ruler->setPixmap(m_QPixmap);

  int width  = m_QPixmap.width();
  int height = m_QPixmap.height();

  QWidget::setMinimumSize(qMax(width, height),
                          qMax(width, height));
  QWidget::resize(qMax(width, height),
                  qMax(width, height));
}

//-----------------------------------------------------------------------------------------------------------------------------

Ruler::~Ruler()
{
  delete m_Ui;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Ruler::rotate()
{
  m_Angle = m_Angle + 90;
  if(m_Angle == 360)
  {
    m_Angle = 0;

    m_Ui->m_QLabel_Ruler->setPixmap(m_QPixmap);

    return;
  }

  QMatrix qMatrix_Rotation;
  qMatrix_Rotation.rotate(m_Angle);
  QPixmap qPixmap_Rotated = m_QPixmap.transformed(qMatrix_Rotation);

  m_Ui->m_QLabel_Ruler->setPixmap(qPixmap_Rotated);
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
