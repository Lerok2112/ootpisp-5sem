#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QMessageBox>
#include <QCloseEvent>

#include <QFontDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QSettings>


QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fileName=QString(), QWidget *parent = nullptr);
    ~TextEditor();
    void loadFile(const QString &fileName);



private slots:
    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void documentModified();

    void on_actionSelect_Font_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    bool on_actionSave_triggered();

    bool on_actionSave_As_triggered();

private:
    Ui::TextEditor *ui;
    QString file_path_;
    void setFileName(const QString &str);

protected:
    void closeEvent(QCloseEvent *e);

};
#endif // TEXTEDITOR_H
