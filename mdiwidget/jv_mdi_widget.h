#ifndef JV_MDI_WIDGET_H
#define JV_MDI_WIDGET_H

#include <QWidget>
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>


namespace Ui {
class JVMdiWidget;
}


class  JVMdiWidget : public QWidget
{
    Q_OBJECT

public:
    JVMdiWidget(QWidget *parent);
    ~JVMdiWidget();

	void setContent(QWidget *w);

	QWidget *getBorder();	//获取边框，可设样式
	void checkBorderDragging(QPoint pos);

signals:
	void sgnClose();

private slots:


private:
    Ui::JVMdiWidget *ui;

	
    bool leftBorderHit(const QPoint &pos);
    bool rightBorderHit(const QPoint &pos);
    bool topBorderHit(const QPoint &pos);
    bool bottomBorderHit(const QPoint &pos);


	QRect m_StartGeometry;	//MdiAear区域
    QSize m_MinnumSize;	//MdiWidget 最小 size
    const quint8 CONST_DRAG_BORDER_SIZE = 6;
	bool m_bMousePressed;
	bool m_bMouseRelease;
    bool m_bDragTop;
    bool m_bDragLeft;
    bool m_bDragRight;
    bool m_bDragBottom;
	QPoint m_PressGlobalPos;


protected:
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;
	virtual void closeEvent(QCloseEvent *event) override;
	virtual void focusInEvent(QFocusEvent *event);
	virtual void focusOutEvent(QFocusEvent *event);


};

#endif // JV_MDI_WIDGET_H
