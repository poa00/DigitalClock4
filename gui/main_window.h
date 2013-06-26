#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../core/clock_settings.h"
#include "../core/skin_manager.h"
#include "../skin/skin_drawer.h"
#include "digital_clock.h"

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

signals:

public slots:
  void SettingsListener(Options opt, const QVariant& value);

private:
  void ConnectAll();
  void SetWindowFlag(Qt::WindowFlags flag, bool set);

  ClockSettings settings_;
  SkinManager skin_manager_;
  SkinDrawer drawer_;
  DigitalClock* d_clock_;
};

#endif // MAIN_WINDOW_H
