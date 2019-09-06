#ifndef JV_MDIAREA_H
#define JV_MDIAREA_H

#include <QWidget>
#include <QDesktopWidget>
#include <QMdiArea>
#include <QMouseEvent>
#include <iostream>
#include "jv_mdi_widget.h"
using namespace std;

class JVMdiArea : public QMdiArea
{
	Q_OBJECT

public:
    explicit JVMdiArea(QWidget *parent = nullptr);

	void addChartWindow(QWidget *widget);

	void outPutVecSize();
protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);


private:
    std::vector<JVMdiWidget *> m_WidgetVec;

};

#endif // JV_MDIAREA_H
