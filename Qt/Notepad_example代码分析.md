# Notepad example代码分析

参见：  
[代码来源](https://doc.qt.io/qt-6/qtwidgets-tutorials-notepad-example.html)  
[QFile|Qt Core](https://doc.qt.io/qt-6/qfile.html)  
[QFileDialog|Qt Widgets](https://doc.qt.io/qt-6/qfiledialog.html)  
[QMessageBox|Qt Widgets](https://doc.qt.io/qt-6/qmessagebox.html)  
[QTextStream|Qt Core](https://doc.qt.io/qt-6/qtextstream.html)  

## 新建文件

```C++
void Notepad::newDocument()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}
```

## 打开文件

```C++
void Notepad::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file"); //打开“选择文件”对话框，选择后返回选中的文件名
    QFile file(fileName);
    currentFile = fileName;         //注：currentFile是此类中的数据成员
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //QIODevice::ReadOnly和QIODevice::Text都是打开模式，其他打开模式详见https://doc.qt.io/qt-6/qiodevicebase.html#OpenModeFlag-enum
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        //warning是QMessageBox的一种类型，其他类型参见https://doc.qt.io/qt-6/qmessagebox.html#static-public-members
        return;
    }
    setWindowTitle(fileName);   //可选，改变窗口标题

    QTextStream in(&file);          //读取文件内容的一种方法，行一      //用QFile类对象的地址初始化QTextStream类对象，输入输出都在该文件（前提是文件可读/可写）
    QString text = in.readAll();    //读取文件内容的一种方法，行二

    ui->textEdit->setText(text);
    file.close();
}
```  

## 保存文件  

```C++
void Notepad::save()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        //QFile::Text其实就是QIODevice::Text,因为头文件经过层层include,两者实际来自同一头文件
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}
```  

## 另存为

```C++
void Notepad::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}
```  

## 打印

不理解

```C++
void Notepad::print()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)
    QPrinter printDev;
#if QT_CONFIG(printdialog)
    QPrintDialog dialog(&printDev, this);
    if (dialog.exec() == QDialog::Rejected)
        return;
#endif // QT_CONFIG(printdialog)
    ui->textEdit->print(&printDev);
#endif // QT_CONFIG(printer)
}
```  

## 退出应用

```C++
void Notepad::exit()
{
    QCoreApplication::quit();
}
```  

## 复制、粘贴、剪切、撤销、重做

不理解

```C++
void Notepad::copy()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->copy();
#endif
}

void Notepad::cut()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->cut();
#endif
}

void Notepad::paste()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->paste();
#endif
}

void Notepad::undo()
{
     ui->textEdit->undo();
}

void Notepad::redo()
{
    ui->textEdit->redo();
}
```  

## 切换字体

```C++
void Notepad::selectFont()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui->textEdit->setFont(font);
}
```  
