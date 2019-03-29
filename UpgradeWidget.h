#ifndef UPGRADEWIDGET_H
#define UPGRADEWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class UpgradeWidget;
}

class UpgradeWidget : public QWidget
{
	Q_OBJECT

#define TIMEOUT				(200)

public:
	explicit UpgradeWidget(QWidget *parent = 0);
	~UpgradeWidget();

	void				startTimer();
	void				stopTimer();

private slots:
	void				timerSlot();

protected:
	void				paintEvent(QPaintEvent *);

private:
	Ui::UpgradeWidget *ui;

	int					m_number;
	QTimer				*m_timer;
};

#endif // UPGRADEWIDGET_H
