#include "BackupPresenter.h"

BackupPresenter::BackupPresenter(IBackupView &view) :
    _view(&view)
{
    _driveManager = new DriveManager();

    SetupSignals();

    _driveManager->RequestDriveList();
}

void BackupPresenter::SetupSignals()
{
    connect(_driveManager, SIGNAL(DriveListChanged(std::vector<DriveInfo>)), this, SLOT(DriveListChanged(std::vector<DriveInfo>)));
    connect(_view, SIGNAL(DriveSelectionChanged(int)), this, SLOT(DriveSelectionChanged(int)));

    connect(_view, &IBackupView::StartTransfer, this, &BackupPresenter::StartTransfer);
}

void BackupPresenter::StartTransfer()
{
}

void BackupPresenter::DriveListChanged(std::vector<DriveInfo> driveList)
{
    _driveList = driveList;
    _view->SetDriveList(driveList);

    if(!_driveList.empty())
    {
        _view->SetCurrentFolder(driveList.at(0).DrivePath);
    }
    else
    {
        _view->SetCurrentFolder("");
    }
}

void BackupPresenter::DriveSelectionChanged(int driveIndex)
{
    if(_driveList.empty())
    {
        return;
    }

    _view->SetCurrentFolder(_driveList.at(driveIndex).DrivePath);
}