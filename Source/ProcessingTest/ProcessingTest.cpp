#include <memory>
#include <thread>

#include <OCui.h>

#include <QtConcurrent/QtConcurrentRun>
#include <QDebug>

#include "Views/ProcessingView.h"
#include "Presenters/ProcessingPresenter.h"

#include <Image/FramePool.h>

class ProcessingTest : public OCui::GUIApplication
{
	std::shared_ptr<IProcessingView> _view;
	std::shared_ptr<IProcessingPresenter> _presenter;

public:
	ProcessingTest(int& argc, char** argv) : OCui::GUIApplication(argc, argv, "ProcessingTest")
	{
		_view = std::make_shared<ProcessingView>();
		_presenter = std::make_shared<ProcessingPresenter>(*_view);

		SetLayout(*static_cast<QWidget*>(_view.get()));
		ShowMaximized();

		QtConcurrent::run(_presenter.get(), &IProcessingPresenter::Test);
	}
};

int main(int argc, char** argv)
{
	ProcessingTest* app = new ProcessingTest(argc, argv);
	app->Run();

	if (app != nullptr)
	{
		delete app;
	}

	return 0;
}