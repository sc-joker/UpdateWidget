#include "UpgradeWidget.h"
#include "ui_UpgradeWidget.h"
#include <math.h>
#include <QPainter>
#include <QPen>

#define PI		3.14
#define RAD		(PI / 180)

UpgradeWidget::UpgradeWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::UpgradeWidget),
	m_number(0)
{
	ui->setupUi(this);

	m_timer = new QTimer;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
}

UpgradeWidget::~UpgradeWidget()
{
	delete ui;

	if (NULL != m_timer)
	{
		m_timer->stop();
		delete m_timer;
	}
}

void UpgradeWidget::startTimer()
{
	if (NULL != m_timer)
		m_timer->start(TIMEOUT);
}

void UpgradeWidget::stopTimer()
{
	if (NULL != m_timer)
		m_timer->stop();
}

void UpgradeWidget::timerSlot()
{
	m_number = (m_number + 1) % 8;
	update();
}

void UpgradeWidget::paintEvent(QPaintEvent *)
{
	QPainter paint(this);
	QPen pen;

	pen.setColor(Qt::red);
	pen.setWidth(5);
	paint.setPen(pen);
	paint.setBrush(QBrush(Qt::red));

	QPoint  center(210, 200);
	int radius = 50;
//	paint.drawEllipse(center, 2, 2);

	int rads[8] = {0, 45, 90, 135, 180, 225, 270, 315};

	for (int i = 0; i <= m_number; i++)
	{
		int pointRad = (i == m_number) ? 5 : 2;
		int x = center.x() + (radius * cos(rads[i] * RAD));
		int y = center.y() + (radius * sin(rads[i] * RAD));
		paint.drawEllipse(x, y, pointRad, pointRad);		//drasw point
//		paint.drawPoint(x, y);
	}


}
