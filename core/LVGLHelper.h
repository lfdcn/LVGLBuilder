#ifndef LVGLHELPER_H
#define LVGLHELPER_H
#include <QComboBox>
#include <QSet>

#include "lvgl/lvgl.h"

class MainWindow;
class LVGLObject;
class LVGLSimulator;
class LVGLEvent;

class LVGLHelper {
 public:
  ~LVGLHelper(){};
  LVGLHelper(const LVGLHelper&) = delete;
  LVGLHelper operator=(const LVGLHelper&) = delete;
  static LVGLHelper& getInstance() {
    static LVGLHelper instance;
    return instance;
  }
  // get
  MainWindow* getMainW() { return m_pMainW; }
  const QString generateFileName() {
    return QString("Page_%1").arg(++m_filecount);
  }
  QStringList& pageName();
  QMap<LVGLObject*, int>& getBtnGoPage() { return m_btnGoPage; }
  bool IsBtngoPageEmpty() { return m_btnGoPage.isEmpty(); }
  QList<QString>& getSaveFontName() { return m_saveFontN; }
  LVGLSimulator* getcursim();
  QMap<lv_obj_t*, QList<LVGLEvent*>>& getObjEvents() { return m_objEvents; }
  QMap<lv_obj_t*, QString>& getTimeCmd() { return m_timeCmd; }
  bool getNeedSetTime() { return m_needSetTime; }
  int getLoadMethod() { return m_loadMethod; }
  int getExportMethod() { return m_exportMethod; }
  QString getStringWithSymbol(const QString& s);

  // set
  void setMainW(MainWindow* m) { m_pMainW = m; }
  void reduceFileindex() { --m_filecount; }
  void setNeedSetTime(bool b) { m_needSetTime = b; }
  void setLoadMethod(int method) { m_loadMethod = method; }
  void setExportMethod(int method) { m_exportMethod = method; }

  // other
  void updatetabDate();
  int getobjeventsize() {
    int size = 0;
    auto iter = m_objEvents.begin();
    for (; iter != m_objEvents.end(); ++iter) size += iter.value().size();
    return size;
  }

 private:
  LVGLHelper()
      : m_pMainW(nullptr),
        m_filecount(0),
        m_needSetTime(false),
        m_loadMethod(0),
        m_exportMethod(0) {
    m_saveFontN.push_back("lv_font_123abc_16");
  }

  MainWindow* m_pMainW;
  int m_filecount;
  QStringList pagelist;
  QMap<LVGLObject*, int> m_btnGoPage;
  QList<QString> m_saveFontN;
  QMap<lv_obj_t*, QList<LVGLEvent*>> m_objEvents;
  QMap<lv_obj_t*, QString> m_timeCmd;
  bool m_needSetTime;
  int m_loadMethod;
  int m_exportMethod;
};
#endif
