#pragma once
#include <QtWidgets>

class LampScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_image;
	QLabel* m_info;
	QPushButton* m_pb_close;
	//int m_lamp_id;
public:
	LampScreen(QWidget* wgt = 0);
	void setLabelText(const QString& str);
	~LampScreen();
signals:
	void signalClosed();
};
