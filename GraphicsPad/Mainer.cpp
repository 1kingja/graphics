#include <Qt\qapplication.h>
#include <MeGlWindow.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MeGlWindow window;
	window.show();
	return app.exec();
}