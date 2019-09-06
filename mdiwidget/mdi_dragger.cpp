#include "mdi_dragger.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

MdiDragger::MdiDragger(QWidget *parent) : QWidget(parent) {
  mousePressed = false;
}

void MdiDragger::mousePressEvent(QMouseEvent *event) {
  mousePressed = true;
  mousePos = event->globalPos();

  QWidget *parent = parentWidget();
  if (parent) parent = parent->parentWidget()->parentWidget();

  if (parent) wndPos = parent->pos();
}

void MdiDragger::mouseMoveEvent(QMouseEvent *event) {
  QWidget *parent = parentWidget();
  if (parent) parent = parent->parentWidget()->parentWidget();

  QPoint movePos = wndPos + (event->globalPos() - mousePos);
  QSize size = this->size();
  QSize mdi_size = parent->parentWidget()->size();

  if (parent && mousePressed)
  {
	  if (movePos.x() <= size.width() / 2 * (-1))
	  {
		  movePos.setX(size.width() / 2 * (-1));
	  }
	  if (movePos.x() > mdi_size.width() - size.width() / 2)
	  {
		  movePos.setX(mdi_size.width() - size.width() / 2);
	  }
	  if (movePos.y() < 0)
	  {
		  movePos.setY(0);
	  }
	  if (movePos.y() > mdi_size.height()-50)
	  {
		  movePos.setY(mdi_size.height() - 50);
	  }
	  parent->move(movePos);
  }
}

void MdiDragger::mouseReleaseEvent(QMouseEvent *event) {
  Q_UNUSED(event);
  mousePressed = false;
}

void MdiDragger::enterEvent(QEvent *event)
{
	Q_UNUSED(event);
	setCursor(Qt::ArrowCursor);
}


void MdiDragger::mouseDoubleClickEvent(QMouseEvent *event) {
  Q_UNUSED(event);

    if(parentWidget()!=nullptr)
    {
        if(parentWidget()->isMaximized())
        {
           parentWidget()->showNormal();
        }else {
            parentWidget()->showMaximized();
        }
    }
  emit doubleClicked();
}
