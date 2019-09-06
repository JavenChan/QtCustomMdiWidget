
#ifndef MDI_RAGGER_H
#define MDI_RAGGER_H

#include <QMouseEvent>
#include <QWidget>

class MdiDragger : public QWidget {
  Q_OBJECT

 public:
  explicit MdiDragger(QWidget *parent = Q_NULLPTR);
  virtual ~MdiDragger() {}

 signals:
  void doubleClicked();

 protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void mouseDoubleClickEvent(QMouseEvent *event);
//  void paintEvent(QPaintEvent *event);
  void enterEvent(QEvent *event);

 protected:
  QPoint mousePos;
  QPoint wndPos;
  bool mousePressed;
};

#endif  // WINDOWDRAGGER_H
