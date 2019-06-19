#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abstractsettings.h"
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, private QtLib::AbstractSettings
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    // Reimplementation AbstractSettings
    const QString getName(void) const;
    void setSettings(const QMap<QString, QVariant> map);
    const QMap<QString, QVariant> getSettings(void) const;


private slots:
    void closeHandle(void);

private:
    Ui::MainWindow *ui;
    QtLib::Settings *m_settings;
    int m_value = 55;       // saved value with default value
};

#endif // MAINWINDOW_H
