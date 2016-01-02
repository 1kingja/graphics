#include <Qt\qapplication.h>
#include <MeGlWindow.h>
#include <MeWidget.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MeWidget widg;
	widg.show();
	return app.exec();
}