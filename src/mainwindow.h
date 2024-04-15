#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QJsonObject>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QTimer>

#include "autostart.h"
#include "displaymanager.h"
#include "displaytab.h"
#include "entryeditor.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit mainWindow(QWidget *parent = nullptr);
  ~mainWindow();

  QSystemTrayIcon systray;

private:
  void setupFromConfig();
  QJsonObject generateConfig();
  void writeConfig();

  void addEntry(programInfo info);
  void removeEntry(QListWidgetItem *item);

  Ui::mainWindow *ui;

  DisplayManager manager;
  QStringList displayNames;
  QTimer timer;

  QMenu systrayMenu;

  QString m_configDir;
  QString m_configPath;

  bool m_loaded;
private slots:
  void updateSaturation();
  void defaultSaturationChanged(const QString &name, int value);

  /*we have to keep the function in case VIBRANT_LINUX_NO_XCB is defined
  otherwise moc_mainwindow will contain an undefined refernece to it*/
  void on_vibranceFocusToggle_toggled(bool checked);
  void on_addProgram_clicked();
  void on_delProgram_clicked();
  void on_programs_doubleClicked(const QModelIndex &index);

  void on_actionShowHideWindow_triggered();
  void on_actionExit_triggered();
  void on_actionAbout_triggered();
  void on_actionRunOnStartup_triggered(bool checked);

  void iconActivated(QSystemTrayIcon::ActivationReason reason);
};

#endif // MAINWINDOW_H
