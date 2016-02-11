#include "Ruler.h"
#include "ui_Ruler.h"

#include <QMouseEvent>

Ruler::Ruler(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Ruler)
{
  ui->setupUi(this);
}

Ruler::~Ruler()
{
  delete ui;
}

void Ruler::mousePressEvent(QMouseEvent *event)
{
  m_QPoint_LastMousePosition = event->pos();
}

void Ruler::mouseMoveEvent(QMouseEvent *event)
{
  emit moveWindow(event->globalPos() - m_QPoint_LastMousePosition);
}

