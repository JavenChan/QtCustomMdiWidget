/*************************************************
Copyright:FX110.com
Author:JavenChan
Date:2019-07-23
Description:可伸缩QDockWidget的标题栏控件
**************************************************/

#include "jv_mdi_widget.h"
#include "ui_jv_mdi_widget.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
JVMdiWidget::JVMdiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JVMdiWidget),
	m_bMousePressed(false),
	m_bDragTop(false),
	m_bDragLeft(false),
	m_bDragRight(false),
	m_bDragBottom(false),
	m_bMouseRelease(true)
{
	ui->setupUi(this);

	connect(ui->widget_title, &MdiDragger::doubleClicked, this, [&] {
		if (this->parentWidget()->isMaximized())
		{
			this->parentWidget()->showNormal();
		}
		else
		{
			this->parentWidget()->showMaximized();
		}
	});
	

	connect(ui->closeBtn, &QToolButton::clicked, this, [&] {
		this->parentWidget()->close();
	});
	connect(ui->maxBtn, &QToolButton::clicked, this, [&] {
		if (this->parentWidget()->isMaximized())
		{
			this->parentWidget()->showNormal();
		}
		else
		{
			this->parentWidget()->showMaximized();
		}
	});


	ui->widget_border->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0); ");
	this->setMouseTracking(true);
	installEventFilter(this);
}


JVMdiWidget::~JVMdiWidget()
{
    delete ui;
}

void JVMdiWidget::setContent(QWidget *w)
{
	ui->widget->layout()->addWidget(w);
}

QWidget* JVMdiWidget::getBorder()
{
    return ui->widget_border;
}


void JVMdiWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
	emit sgnClose();
}


void JVMdiWidget::checkBorderDragging(QPoint MousePos)
{
	if (isMaximized()) {
		return;
	}

	if (m_bMousePressed) {
		// top top_right corner
		QPoint globalMousePos = mapToGlobal(MousePos);
		if (m_bMouseRelease == false)
		{
			m_bMouseRelease = true;
			m_PressGlobalPos = globalMousePos;
		}
		if (m_bDragTop && m_bDragRight)
		{
			int diff = globalMousePos.x() - m_PressGlobalPos.x();
			int neww = m_StartGeometry.width() + diff;

			diff = globalMousePos.y() - m_PressGlobalPos.y();
			int newy = m_StartGeometry.y() + diff;
			int newh = m_StartGeometry.height() - diff;

			if (neww < m_MinnumSize.width())
				neww = m_MinnumSize.width();
			if (newh < m_MinnumSize.height())
			{
				newh = m_MinnumSize.height();
				newy = m_StartGeometry.y() + m_StartGeometry.height() - m_MinnumSize.height();
			}

			if (neww > m_MinnumSize.width() || newh > m_MinnumSize.height())
			{
				QRect newg = m_StartGeometry;
				newg.setWidth(neww);
				newg.setX(m_StartGeometry.x());
				newg.setY(newy);
				parentWidget()->setGeometry(newg);
			}
		}
		// top top_left corner
		else if (m_bDragTop && m_bDragLeft)
		{
			int diff = globalMousePos.y() - m_PressGlobalPos.y();
			int newy = m_StartGeometry.y() + diff;
			int newh = m_StartGeometry.height() - diff;
			diff = globalMousePos.x() - m_PressGlobalPos.x();
			int newx = m_StartGeometry.x() + diff;//diff 正
			int neww = m_StartGeometry.width() - diff;

			if (neww < m_MinnumSize.width())
			{
				neww = m_MinnumSize.width();
				newx = m_StartGeometry.x() + m_StartGeometry.width() - m_MinnumSize.width();
			}
			if (newh < m_MinnumSize.height())
			{
				newh = m_MinnumSize.height();
				newy = m_StartGeometry.y() + m_StartGeometry.height() - m_MinnumSize.height();
			}
			if (neww > m_MinnumSize.width() || newh > m_MinnumSize.height()) {
				QRect newg = m_StartGeometry;
				newg.setY(newy);
				newg.setX(newx);
				parentWidget()->setGeometry(newg);
			}
		}
		// bottom buttom_left corner
		else if (m_bDragBottom && m_bDragLeft)
		{
			int diff = globalMousePos.y() - (m_PressGlobalPos.y() );
			int newh = m_StartGeometry.height() + diff;
			diff = globalMousePos.x() - m_PressGlobalPos.x();
			int newx = m_StartGeometry.x() + diff;
			int neww = m_StartGeometry.width() - diff;

			if (neww < m_MinnumSize.width())
			{
				neww = m_MinnumSize.width();
				newx = m_StartGeometry.x() + m_StartGeometry.width() - m_MinnumSize.width();
			}
			if (newh < m_MinnumSize.height())
			{
				newh = m_MinnumSize.height();
			}
			if (neww > m_MinnumSize.width() || newh > m_MinnumSize.height()) {
				QRect newg = m_StartGeometry;
				newg.setX(newx);
				newg.setHeight(newh);
				parentWidget()->setGeometry(newg);
			}
		}
		// bottom buttom_right corner   
		else if (m_bDragRight && m_bDragBottom)
		{
			int diff = globalMousePos.y() - m_PressGlobalPos.y() ;
			int newh = m_StartGeometry.height() + diff;
			diff = globalMousePos.x() - m_PressGlobalPos.x();
			int neww = m_StartGeometry.width() + diff;
			if (neww < m_MinnumSize.width())
			{
				neww = m_MinnumSize.width();
			}
			if (newh < m_MinnumSize.height())
			{
				newh = m_MinnumSize.height();
			}
			if (newh > 0 && neww > 0)
			{
				QRect newg = m_StartGeometry;
				newg.setWidth(neww);
				newg.setX(m_StartGeometry.x());
				newg.setHeight(newh);
				parentWidget()->setGeometry(newg);
			}
		}
		else if (m_bDragTop) {

			int diff = globalMousePos.y() - m_PressGlobalPos.y();
			int newy = m_StartGeometry.y() + diff;
			int newh = m_StartGeometry.height() - diff;
			if (newy < 0)
			{
				newy = 0;
			}
			if (newh < m_MinnumSize.height())
			{
				newh = m_MinnumSize.height();
				newy = m_StartGeometry.y() + m_StartGeometry.height() - m_MinnumSize.height();
			}
			QRect newg = m_StartGeometry;
			newg.setY(newy);
			parentWidget()->setGeometry(newg);
        }
		else if (m_bDragLeft)
		{
			//globalMousePos 输入Pos
			int diff = globalMousePos.x() - m_PressGlobalPos.x();
			int newx = m_StartGeometry.x() + diff;
			int neww = m_StartGeometry.width() - diff;
			if (newx < 0)
			{
				newx = 0;
			}
			QRect newg = m_StartGeometry;
			if (neww < m_MinnumSize.width())
			{
				neww = m_MinnumSize.width();
				newx = m_StartGeometry.x() + m_StartGeometry.width() - m_MinnumSize.width();
			}
			newg.setX(newx);
			parentWidget()->setGeometry(newg);
		}
		else if (m_bDragRight)
		{
			int diff = globalMousePos.x() - m_PressGlobalPos.x();
			int neww = m_StartGeometry.width() + diff;
			if (neww < m_MinnumSize.width())
			{
				neww = m_MinnumSize.width();
			}
			if (neww > 0)
			{
				QRect newg = m_StartGeometry;
				newg.setWidth(neww);
				newg.setX(m_StartGeometry.x());
				parentWidget()->setGeometry(newg);
			}
		}
		else if (m_bDragBottom)
		{
			int diff = globalMousePos.y() - m_PressGlobalPos.y();
			int newh = m_StartGeometry.height() + diff;
			if (newh > 0)
			{
				if (newh < m_MinnumSize.height())
				{
					newh = m_MinnumSize.height();
				}
				QRect newg = m_StartGeometry;
				newg.setHeight(newh);
				newg.setY(m_StartGeometry.y());
				parentWidget()->setGeometry(newg);
			}
		}
	}   
	else {
		// no mouse pressed
		if (leftBorderHit(MousePos) && topBorderHit(MousePos))
		{
			setCursor(Qt::SizeFDiagCursor);   //cjf 左上角
		}
		else if (rightBorderHit(MousePos) && topBorderHit(MousePos))
		{
			setCursor(Qt::SizeBDiagCursor);   //cjf 右上角
		}
		else if (leftBorderHit(MousePos) && bottomBorderHit(MousePos))
		{
			setCursor(Qt::SizeBDiagCursor);
		}
		else if (rightBorderHit(MousePos) && bottomBorderHit(MousePos))
		{
			setCursor(Qt::SizeFDiagCursor);
		}
		else
		{
			if (topBorderHit(MousePos))
			{
				setCursor(Qt::SizeVerCursor);
			}
			else if (leftBorderHit(MousePos))
			{
				setCursor(Qt::SizeHorCursor);
			}
			else if (rightBorderHit(MousePos))
			{
				setCursor(Qt::SizeHorCursor);
			}
			else if (bottomBorderHit(MousePos))
			{
				setCursor(Qt::SizeVerCursor);
			}
			else
			{
				m_bDragTop = false;
				m_bDragLeft = false;
				m_bDragRight = false;
				m_bDragBottom = false;
				setCursor(Qt::ArrowCursor);
			}
		}
	}
}

// pos in global virtual desktop coordinates
bool JVMdiWidget::leftBorderHit(const QPoint &pos)
{
	const QRect &rect = this->geometry();
//	qDebug() << "rect = " << rect;
//	qDebug() << "pos = " << pos;
	if (pos.x() >= rect.x() && pos.x() <= rect.x() + CONST_DRAG_BORDER_SIZE)
	{
		return true;
	}
	return false;
}

bool JVMdiWidget::rightBorderHit(const QPoint &pos)
{
	const QRect &rect = this->geometry();
	int tmp = rect.x() + rect.width();
	if (pos.x() <= tmp && pos.x() >= (tmp - CONST_DRAG_BORDER_SIZE))
	{
		return true;
	}
	return false;
}

bool JVMdiWidget::topBorderHit(const QPoint &pos)
{
	const QRect &rect = this->geometry();
	if (pos.y() >= rect.y() && pos.y() <= rect.y() + CONST_DRAG_BORDER_SIZE)
	{
		return true;
	}
	return false;
}

bool JVMdiWidget::bottomBorderHit(const QPoint &pos)
{
	const QRect &rect = this->geometry();
	int tmp = rect.y() + rect.height();

	if (pos.y() <= tmp && pos.y() >= (tmp - CONST_DRAG_BORDER_SIZE))
	{
		return true;
	}
	return false;
}

void JVMdiWidget::mousePressEvent(QMouseEvent *event)
{
	if (isMaximized()) {
		return;
	}
	m_bMousePressed = true;
	m_bMouseRelease = false;
	m_StartGeometry = parentWidget()->geometry();
	m_MinnumSize = this->minimumSize();
    QPoint &&MousePos = QPoint(event->x(), event->y());

	if (leftBorderHit(MousePos) && topBorderHit(MousePos))
	{
		m_bDragTop = true;
		m_bDragLeft = true;
		setCursor(Qt::SizeFDiagCursor);
	}
	else if (rightBorderHit(MousePos) && topBorderHit(MousePos))
	{
		m_bDragRight = true;
		m_bDragTop = true;
		setCursor(Qt::SizeBDiagCursor);
	}
	else if (leftBorderHit(MousePos) && bottomBorderHit(MousePos))
	{
		m_bDragLeft = true;
		m_bDragBottom = true;
		setCursor(Qt::SizeBDiagCursor);
	}
	else if (rightBorderHit(MousePos) && bottomBorderHit(MousePos))
	{
		m_bDragRight = true;
		m_bDragBottom = true;
		setCursor(Qt::SizeFDiagCursor);
	}
	else {
		if (topBorderHit(MousePos))
		{
			m_bDragTop = true;
			setCursor(Qt::SizeVerCursor);	//上下箭头
		}
		else if (leftBorderHit(MousePos))
		{
			m_bDragLeft = true;
			setCursor(Qt::SizeHorCursor);
		}
		else if (rightBorderHit(MousePos))
		{
			m_bDragRight = true;
			setCursor(Qt::SizeHorCursor);
		}
		else if (bottomBorderHit(MousePos))
		{
			m_bDragBottom = true;
			setCursor(Qt::SizeVerCursor);
		}
	}
}
void JVMdiWidget::mouseReleaseEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	if (isMaximized())
	{
		return;
	}

	m_bMousePressed = false;
	m_bMouseRelease = true;
	bool bSwitchBackCursorNeeded = m_bDragTop || m_bDragLeft || m_bDragRight || m_bDragBottom;
	m_bDragTop = false;
	m_bDragLeft = false;
	m_bDragRight = false;
	m_bDragBottom = false;
	if (bSwitchBackCursorNeeded)
	{
		setCursor(Qt::ArrowCursor);
	}
}

void JVMdiWidget::focusInEvent(QFocusEvent *event)
{
	ui->widget_border->setStyleSheet("background-color: rgb(20, 227, 254);color: rgb(0, 0, 0); ");
	QWidget::focusInEvent(event);
}
void JVMdiWidget::focusOutEvent(QFocusEvent *event)
{
	ui->widget_border->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0); ");
	QWidget::focusOutEvent(event);
}
