
// Files includes --------------------------
#include "RulerGraphicsView.h"

// Project includes ------------------------
#include "Ruler.h"

#include <QGraphicsProxyWidget>

//-----------------------------------------------------------------------------------------------------------------------------

RulerGraphicsView::RulerGraphicsView(QWidget *parent) :
  QGraphicsView(parent),
  m_QGraphicsScene(),
  m_Ruler(NULL),
  m_QGraphicsProxyWidget_Ruler(NULL),
  m_RotationAngle(0)
{
  m_Ruler = new Ruler();
  m_Ruler->setStyleSheet("background-color: transparent;");
  m_QGraphicsProxyWidget_Ruler = new QGraphicsProxyWidget(0,
                                                          Qt::FramelessWindowHint);
  m_QGraphicsProxyWidget_Ruler->setWidget(m_Ruler);
  m_QGraphicsProxyWidget_Ruler->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
  m_QGraphicsProxyWidget_Ruler->resize(QSize(m_Ruler->width(),
                                             m_Ruler->height()));

  // Graphic scene properties
  m_QGraphicsScene.setStickyFocus(true);
  m_QGraphicsScene.addItem(m_QGraphicsProxyWidget_Ruler);

  // GraphicsView properties
  QGraphicsView::setStyleSheet("background-color: transparent;");
  QGraphicsView::setFrameStyle(QFrame::NoFrame);
  QGraphicsView::setScene(&m_QGraphicsScene);
  QGraphicsView::setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  QGraphicsView::setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  QGraphicsView::setRenderHints(renderHints() | QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
 // QGraphicsView::setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
  QGraphicsView::setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

  // Conntections
  connect(m_Ruler,
          SIGNAL(signal_Rotate()),
          SLOT(slot_Ruler_Rotate()));
}

//-----------------------------------------------------------------------------------------------------------------------------

RulerGraphicsView::~RulerGraphicsView()
{

}

//-----------------------------------------------------------------------------------------------------------------------------

void RulerGraphicsView::slot_Ruler_Rotate()
{
  m_RotationAngle = m_RotationAngle + 90;
  if(m_RotationAngle == 360)
    m_RotationAngle = 0;


  QTransform qTransform_Rotate;
//  qTransform_Rotate.translate(m_Ruler->height(),
//                              0.0);
  qTransform_Rotate.rotate(m_RotationAngle);
  m_QGraphicsProxyWidget_Ruler->setTransformOriginPoint(0.0, 0.0);
  m_QGraphicsProxyWidget_Ruler->setTransform(qTransform_Rotate);

  m_Ruler->move(20.0, 20.0);
}
