#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow() {
	setWindowTitle(tr("Number Slider"));
	setFixedSize(300, 300);
	
	num1 = 0;
	num2 = 0;
	num3 = 0;

	numType = 10;
	
	numLabel = new QLabel(this);
	numLabel->setGeometry(140, 90, 200, 160);
	numLabel->setFont(QFont("Courier", 50, QFont::Bold));
	numLabel->setText( "0" );

	num1Slider = new QSlider(Qt::Vertical, this);
	num1Slider->setGeometry(110, 90, 20, 160);
	num1Slider->setRange(0, 9);
	num1Slider->setValue(num1);
	connect(num1Slider, SIGNAL(valueChanged(int)), this, SLOT(changeNum(int)));
	
	num2Slider = new QSlider(Qt::Vertical, this);
	num2Slider->setGeometry(60, 90, 20, 160);
	num2Slider->setRange(0, 9);
	num2Slider->setValue(num2);
	connect(num2Slider, SIGNAL(valueChanged(int)), this, SLOT(changeNum(int)));
	
	num3Slider = new QSlider(Qt::Vertical, this);
	num3Slider->setGeometry(10, 90, 20, 160);
	num3Slider->setRange(0, 9);
	num3Slider->setValue(num3);
	connect(num3Slider, SIGNAL(valueChanged(int)), this, SLOT(changeNum(int)));

	numSlider = new QSlider(Qt::Vertical, this);
	numSlider->setGeometry(270, 90, 20, 160);
	numSlider->setRange(0, 999);
	numSlider->setValue(0);

	num1Label = new QLabel(this);
	num1Label->setGeometry(110, 250, 20, 20);
	num1Label->setText(QString::number(num1));
	num1Label->setFont(QFont("Times", 20, QFont::Bold));

	num2Label = new QLabel(this);
	num2Label->setGeometry(60, 250, 20, 20);
	num2Label->setText(QString::number(num2));
	num2Label->setFont(QFont("Times", 20, QFont::Bold));

	num3Label = new QLabel(this);
	num3Label->setGeometry(10, 250, 20, 20);
	num3Label->setText(QString::number(num3));
	num3Label->setFont(QFont("Times", 20, QFont::Bold));

	decButton = new QPushButton(tr("Dec"), this);
	decButton->setGeometry(10, 10, 280, 30);
	decButton->setVisible(false);
	connect(decButton, SIGNAL(clicked()), this, SLOT(decButtonClick()));

	hexButton = new QPushButton(tr("Hex"), this);
	hexButton->setGeometry(10, 10, 280, 30);
	connect(hexButton, SIGNAL(clicked()), this, SLOT(hexButtonClick()));

}

int MainWindow::getNum() {
	QString n(QString::number(num3, numType) + QString::number(num2, numType) + QString::number(num1, numType));

	return n.toInt(0, numType);
}

void MainWindow::changeNum(int) {
	num1 = num1Slider->value();
	num2 = num2Slider->value();
	num3 = num3Slider->value();

	num1Label->setText(QString::number(num1, numType));
	num2Label->setText(QString::number(num2, numType));
	num3Label->setText(QString::number(num3, numType));

	num1Slider->setRange(0, numType - 1);
	num2Slider->setRange(0, numType - 1);
	num3Slider->setRange(0, numType - 1);

	numSlider->setRange(0, numType*numType*numType - 1);
	numSlider->setValue(getNum());
	
	numLabel->setText( QString::number(getNum(), numType) );
}

void MainWindow::decButtonClick() {
	numType = 10;
	decButton->setVisible(false);
	hexButton->setVisible(true);
	changeNum(1);
}

void MainWindow::hexButtonClick() {
	numType = 16;
	decButton->setVisible(true);
	hexButton->setVisible(false);
	changeNum(1);
}