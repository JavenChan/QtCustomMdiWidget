/*************************************************
Copyright:FX110.com
Author:JavenChan
Date:2019-07-23
Description:可伸缩QDockWidget的标题栏控件
**************************************************/

#include "jv_mdiarea.h"
#include <QDebug>
#include <QTextEdit>

JVMdiArea::JVMdiArea(QWidget *parent) :
	QMdiArea(parent)
{
	m_WidgetVec.clear();
	setStyleSheet("background-color:rgb(0,0,0);");

}

void JVMdiArea::outPutVecSize()
{
	qDebug() << "m_WidgetVec Size " << m_WidgetVec.size();
}
void JVMdiArea::addChartWindow(QWidget *widget)
{

    JVMdiWidget *m_widget = new JVMdiWidget(window());
    m_widget->setContent(widget);

    addSubWindow(m_widget,Qt::FramelessWindowHint);
    m_WidgetVec.emplace_back(m_widget);
    m_widget->show();

	
    connect(m_widget, &JVMdiWidget::sgnClose, this, [&] {
		//对删除框做处理
        auto it = std::find(m_WidgetVec.begin(), m_WidgetVec.end(), (JVMdiWidget *)sender());
		if (it != m_WidgetVec.end())
		{
			m_WidgetVec.erase(it);
		}
		outPutVecSize();
		
	});
	
}

bool JVMdiArea::eventFilter(QObject *obj, QEvent *event) {
	if (isMaximized()) {
		return QWidget::eventFilter(obj, event);
	}
	// check mouse move event when mouse is moved on any object
	if (event->type() == QEvent::MouseMove) {
		QMouseEvent *pMouse = dynamic_cast<QMouseEvent *>(event);
        if (pMouse) {
			for (auto mdi : m_WidgetVec)
			{
				if (obj == mdi->getBorder())
                {
					mdi->checkBorderDragging(pMouse->pos());
				}
			}
		}
	}

	return QWidget::eventFilter(obj, event);
}
