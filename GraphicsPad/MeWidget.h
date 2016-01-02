#pragma once
#include <QtGui\qwidget.h>
class DebugSlider;
class MeGlWindow;

class MeWidget : public QWidget
{
	Q_OBJECT

	DebugSlider* lightXSlider;
	DebugSlider* lightYSlider;
	DebugSlider* lightZSlider;

	MeGlWindow* meGlWindow;

private slots:
	void sliderValueChanged();

public:
	MeWidget();
};

