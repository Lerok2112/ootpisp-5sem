#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(const QString &fileName,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));

    setWindowTitle("TextEditor[*]"); //при изменении документа появляется звездочка возле названия

    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));

    loadFile(fileName);

}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()  //новый документ
{
    TextEditor *window = new TextEditor;
    window->show();

}

void TextEditor::on_actionClose_triggered()
{
    this->close();
}

void TextEditor::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void TextEditor::documentModified() {
    setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *e)   //окно при закрытии файла
{
    if(ui->textEdit->document()->isModified())
        {
            switch(QMessageBox::warning(this, "Document Modified",
               "The document has been modified. "
               "Do you want to save your changes?\n"
               "You will lose unsaved changes.",
               QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::No ))
            {
            case QMessageBox::Yes:
                on_actionSave_triggered();
            case QMessageBox::No:
                e->accept();
                break;
            case QMessageBox::Cancel:
                e->ignore();
                break;
            }
        }
        else
        {
            e->accept();
        }

}

void TextEditor::on_actionSelect_Font_triggered()  //выбор шрифта
{
    bool ok;
      QFont font = QFontDialog::getFont(&ok, this);
      if (ok) {
          ui->textEdit->setFont(font);
        } else return;

}

void TextEditor::on_actionAbout_Qt_triggered() //Справка о QT
{
    qApp->aboutQt();
}

void TextEditor::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void TextEditor::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void TextEditor::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void TextEditor::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void TextEditor::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("О приложении"),
                    tr("Приложение является простейшим текстовым редактором на QT."
                       "Написала студентка ПО-3 Овсейчук В."));

}

void TextEditor::loadFile(const QString &fileName)
{
    if (fileName.isNull()) {
            return (setFileName(QString()));
        }
    else {
            QFile file(fileName);
            file_path_ = fileName;
            if(!file.open(QFile::ReadOnly | QFile::Text)) {
                  QMessageBox::warning(this,"..","file not open");
                  return (setFileName(QString()));
                }
            QTextStream in(&file);
            QString text = in.readAll();
            ui->textEdit->setText(text);
            file_path_=fileName;
            file.close();
            setFileName(fileName);
            setWindowModified(false);

    }
}

void TextEditor::setFileName(const QString &str)
{
    file_path_ = str;
    setWindowTitle(QString("%1[*] - %2")
                   .arg(file_path_.isNull()?"untitled":QFileInfo(file_path_).fileName())
                   .arg(QApplication::applicationName())
);
}

void TextEditor::on_actionOpen_triggered()  //ОТКРЫТИЕ документа
{
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull()) {
        return; }
    if (file_path_.isNull() && (ui->textEdit->document()->isModified())) {
       loadFile(fileName); }
    else {
        TextEditor *window = new TextEditor(fileName);
        window->show();
    }
}

bool TextEditor::on_actionSave_triggered()  //СОХРАНЕНИЕ ФАЙЛА
{
    if (file_path_.isNull()) {
            return (on_actionSave_As_triggered());
        }
        else {
            QFile file(file_path_);
            if(!file.open(QFile::WriteOnly | QFile::Text)) {
                QMessageBox::warning(this,"..","file not open");
                return false;
              }
            QTextStream out(&file);
            QString text = ui->textEdit->toPlainText();
            out << text;
            file.flush();
            file.close();
            setWindowModified(false);
            return true;
        }
}

bool TextEditor::on_actionSave_As_triggered()    //ЗАПРАШИВАЕТ У ПОЛЬЗОВАТЕЛЯ ИМЯ ФАЙЛА И ВЫЗЫВАЕТ ФУНК-ИЮ СОХРАНЕНИЯ
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
           file_path_.isNull()?QDir::currentPath():file_path_, "Text documents (*.txt)");
        if (fileName.isNull()) {   //если имя файла не получено -- файл не был сохранен
            return false;
        }
        else {
            setFileName(fileName);
            return on_actionSave_triggered();
        }
}
