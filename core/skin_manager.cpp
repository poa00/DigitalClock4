#include <QDir>
#include "../skin/iclock_skin.h"
#include "skin_manager.h"

SkinManager::SkinManager(QObject *parent)
  : QObject(parent) {
}

void SkinManager::AddSkinDir(const QString& dir) {
  skin_dirs_.append(dir);
}

void SkinManager::DelSkinDir(const QString& dir) {
  skin_dirs_.removeOne(dir);
}

void SkinManager::ListSkins() {
  for (auto& s_dir : skin_dirs_) {
    QDir d(s_dir);
    QStringList f_dirs = d.entryList(QStringList("*"),
                                     QDir::NoDotAndDotDot | QDir::AllDirs);
    for (auto& f_dir : f_dirs) {
      QString skin_root = QDir(s_dir).filePath(f_dir);
      IClockSkin* tmp = CreateSkin(skin_root);
      if (!tmp) continue;
      skins_[tmp->GetInfo()[SI_NAME]] = skin_root;
      delete tmp;
    }
  }
  emit SearchFinished(skins_.keys());
}

void SkinManager::FindSkin(const QString& skin_name) {
  emit SkinFound(skins_[skin_name]);
}
