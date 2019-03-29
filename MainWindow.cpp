#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "UpgradeWidget.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_flag(true)
{
	ui->setupUi(this);

	connect(ui->showButton, SIGNAL(clicked(bool)), this, SLOT(startStop()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::startStop()
{
	if (m_flag)
	{
		ui->showButton->setText("stop");
		ui->showWidget->startTimer();
		m_flag = !m_flag;
	} else
	{
		ui->showButton->setText("start");
		ui->showWidget->stopTimer();
		m_flag = !m_flag;
	}
}
