#ifndef LVGLEVENTCHECKBOX_H
#define LVGLEVENTCHECKBOX_H

#include "LVGLEvent.h"

class LVGLEventCheckBox : public LVGLEvent {
 public:
  LVGLEventCheckBox();
  void eventRun(lv_obj_t *obj) override;
  QStringList objCode(const QString& objName) override;
  QString eventHeadCode() override;
  QStringList eventCode() override;
};

#endif  // LVGLEVENTCHECKBOX_H