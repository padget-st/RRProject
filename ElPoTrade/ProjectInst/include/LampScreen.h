#pragma once
#include <QtWidgets>

class LampScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_image;
	QLabel* m_info;
	QPushButton* m_pb_close;
public:
	LampScreen(QWidget* wgt = 0);
	void setLabelImage(const QPixmap&);
	void setLabelText(const QString&);
	~LampScreen();
signals:
	void signalClosed();
};
