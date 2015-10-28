#ifndef IBACKUPVIEW_H
#define IBACKUPVIEW_H

#include <QWidget>

#include <Interfaces/IDriveManager.h>

class IBackupView : public QWidget
{
    Q_OBJECT

public:
    virtual void SetDriveList(std::vector<DriveInfo> driveList) = 0;
    virtual void SetCurrentFolder(std::string folderPath) = 0;
     virtual void SetItemList(std::vector<std::string> fileList) = 0;

signals:
    void StartTransfer();

    void DriveSelectionChanged(int driveIndex);
    void FolderSelectionChanged();

    void AddDestinationClicked();
};

#endif //IBACKUPVIEW_H
