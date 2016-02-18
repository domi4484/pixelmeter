#ifndef RULERGRAPHICSVIEW_H
#define RULERGRAPHICSVIEW_H

// Qt incldues -----------------------------
#include <QGraphicsView>

// Forward declarations --------------------
class Ruler;

class RulerGraphicsView : public QGraphicsView
{
  Q_OBJECT

public:

  explicit RulerGraphicsView(QWidget *parent = 0);
  virtual ~RulerGraphicsView();

  Ruler *ruler() const { return m_Ruler; }

private slots:

  void slot_Ruler_Rotate();

private:

  QGraphicsScene m_QGraphicsScene;

  Ruler *m_Ruler;
  QGraphicsProxyWidget *m_QGraphicsProxyWidget_Ruler;

};

#endif // RULERGRAPHICSVIEW_H
