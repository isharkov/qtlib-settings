#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief default constructor
 * MainWindow options readed there from file
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->closeBtn, SIGNAL(clicked(bool)), this, SLOT(closeHandle()));
    m_settings = new QtLib::Settings("settings.ini", this);
    m_settings->restoreObject(this);
    ui->valueInput->setText(QString().sprintf("%d", m_value));
}

/**
 * @brief destructor
 * MainWindow options writed there to file
 */
MainWindow::~MainWindow()
{
    m_value = ui->valueInput->text().toInt();
    m_settings->saveObject(this);
    m_settings->deleteLater();
    delete ui;
}

/**
 * @brief Return saved object name
 * Reimplementation AbstractSettings class methods
 * @return
 */
const QString MainWindow::getName() const
{
    return QString("Mainwindow");
}

/**
 * @brief MainWindow::setSettings
 * @param map
 */
void MainWindow::setSettings(const QMap<QString, QVariant> map)
{
    m_value = map.value("value").toInt();
    return;
}

/**
 * @brief MainWindow::getSettings
 * @return
 */
const QMap<QString, QVariant> MainWindow::getSettings(void) const
{
   QMap<QString, QVariant> map;
   map["value"] = m_value;
   return map;
}

/**
 * @brief MainWindow::closeHandle
 */
void MainWindow::closeHandle()
{
    this->close();
}
