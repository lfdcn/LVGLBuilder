#ifndef EVENTSELECTWIDGET_H
#define EVENTSELECTWIDGET_H

#include <QDialog>

class EventSettingWidgeet;
class LVGLEvent;

extern int Index;

QT_BEGIN_NAMESPACE
namespace Ui {
class EventSelectWIdget;
}
QT_END_NAMESPACE

class EventSelectWIdget : public QDialog {
  Q_OBJECT

 public:
  EventSelectWIdget(QWidget *parent = nullptr);
  ~EventSelectWIdget();
  void setTextList(const QStringList &list);
  QStringList textList();

 private slots:
  void on_selectbtn_clicked();
  void on_cancelbtn_clicked();
  void slotSetWFinished();

 private:
  void getEvent(LVGLEvent *&ev, int index);

 private:
  Ui::EventSelectWIdget *ui;
  EventSettingWidgeet *m_setWidget;
  LVGLEvent *m_ev;
};
#endif  // EVENTSELECTWIDGET_H
