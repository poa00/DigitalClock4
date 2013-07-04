#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../core/clock_settings.h"
#include "../core/skin_manager.h"
#include "../skin/skin_drawer.h"
#include "digital_clock.h"
#include "tray_control.h"

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow(QWidget* parent = 0);

protected:
  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);

private slots:
  void SettingsListener(Options opt, const QVariant& value);
  void ShowSettingsDialog();
  void EndSettingsEdit();
  void ShowAboutDialog();
  void DisplayMenu(const QPoint& pos);

private:
  void ConnectAll();
  void SetWindowFlag(Qt::WindowFlags flag, bool set);

  ClockSettings* settings_;
  SkinManager* skin_manager_;
  SkinDrawer* drawer_;
  DigitalClock* d_clock_;
  TrayControl* tray_control_;
  QPoint drag_position_;
  QTimer* settings_timer_;
};

#endif // MAIN_WINDOW_H
