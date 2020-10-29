#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidget>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    QTableWidget *tabelle;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addZeile();


private slots:
    void on_btn_add_clicked();
    void on_btn_save_clicked();
    //void on_btn_load_clicked();
};
#endif // MAINWINDOW_H
