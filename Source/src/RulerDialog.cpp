
// Files includes --------------------------
#include "RulerDialog.h"

// Project includes ------------------------
#include "Ruler.h"
#include "RulerGraphicsView.h"

//-----------------------------------------------------------------------------------------------------------------------------

RulerDialog::RulerDialog(QWidget *parent) :
  QDialog(parent,
          Qt::FramelessWindowHint),
  m_RulerGraphicsView(NULL)
{
  // Make transparent
  setAttribute(Qt::WA_TranslucentBackground);

  m_RulerGraphicsView = new RulerGraphicsView(this);

  QDialog::resize(2*qMax(m_RulerGraphicsView->ruler()->height(), m_RulerGraphicsView->ruler()->width()),
                      2*qMax(m_RulerGraphicsView->ruler()->height(), m_RulerGraphicsView->ruler()->width()));

  connect(m_RulerGraphicsView->ruler(),
          SIGNAL(signal_MoveWindow(QPoint)),
          SLOT(slot_MoveWindow(QPoint)));
}

//-----------------------------------------------------------------------------------------------------------------------------

RulerDialog::~RulerDialog()
{
  delete m_RulerGraphicsView;
}

//-----------------------------------------------------------------------------------------------------------------------------

void RulerDialog::slot_MoveWindow(const QPoint &point)
{
  QDialog::move(point);
}
