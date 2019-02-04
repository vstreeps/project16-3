#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
class QLabel;
class QSlider;
class QPushButton;
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow();
		
	private slots:
		void changeNum(int _num0);
		void decButtonClick();
		void hexButtonClick();

	protected:
		int getNum();
		
	private:
		int num1, num2, num3;
		int numType;
		QString strNum;
		QSlider *num1Slider, *num2Slider, *num3Slider, *numSlider;
		QLabel *numLabel;
		QLabel *num1Label, *num2Label, *num3Label;
		QPushButton *decButton, *hexButton;
};
#endif
