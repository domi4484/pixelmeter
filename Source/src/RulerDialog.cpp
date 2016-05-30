
// Files includes --------------------------
#include "RulerDialog.h"

// Project includes ------------------------
#include "Ruler.h"

#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------------------

RulerDialog::RulerDialog(QWidget *parent) :
  QDialog(parent,
          Qt::FramelessWindowHint),
  m_Ruler(NULL)
{
  // Make transparent
  setAttribute(Qt::WA_TranslucentBackground);

  m_Ruler = new Ruler(this);

//  QDialog::resize(m_Ruler->imageSize());

  connect(m_Ruler,
          SIGNAL(signal_MoveWindow(QPoint)),
          SLOT(slot_MoveWindow(QPoint)));
}

//-----------------------------------------------------------------------------------------------------------------------------

RulerDialog::~RulerDialog()
{
  delete m_Ruler;
}

//-----------------------------------------------------------------------------------------------------------------------------

void RulerDialog::slot_MoveWindow(const QPoint &point)
{
  QDialog::move(point);
}
