/*
    Digital Clock: skin draw engine
    Copyright (C) 2013-2016  Nick Korotysh <nick.korotysh@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "vector_skin.h"

#include <QFile>
#include <QSvgRenderer>
#include <QPainter>

namespace skin_draw {

ISkin::QPixmapPtr VectorSkin::ResizeImage(QChar ch, qreal zoom)
{
  QString& img_file = image_files_[ch];
  if (!QFile::exists(img_file)) return QPixmapPtr();

  QSvgRenderer renderer(img_file);
  QPixmapPtr result(new QPixmap(renderer.defaultSize() * zoom * device_pixel_ratio_));
  QPainter painter(result.data());
  painter.setCompositionMode(QPainter::CompositionMode_Source);
  painter.fillRect(result->rect(), Qt::transparent);
  painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
  renderer.render(&painter);
  painter.end();
  result->setDevicePixelRatio(device_pixel_ratio_);
  return result;
}

} // namespace skin_draw
