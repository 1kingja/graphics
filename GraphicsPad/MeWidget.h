#pragma once
#include <QtGui\qwidget.h>
class DebugSlider;

class MeWidget : public QWidget
{
	Q_OBJECT

	DebugSlider* lightXSlider;
	DebugSlider* lightYSlider;
	DebugSlider* lightZSlider;
private slots:
	void sliderValueChanged();

public:
	MeWidget();
};

