#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTableWidget>
#include<QStatusBar>
#include<QFile>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::addZeile(){
    auto lange=ui->lineEdit_ID->text().trimmed();
    if(lange.count()==4){
        //anzahl der Reihen anpassen
        int anzahlReihen=ui->table_pro->rowCount();
        ui->table_pro->setRowCount(anzahlReihen+1);
        auto witem=new QTableWidgetItem(ui->lineEdit_ID->text());

        //ID füllen
        ui->table_pro->setItem(anzahlReihen,0,witem);
        //Bezeichnung füllen
        ui->table_pro->setItem(anzahlReihen,1,new QTableWidgetItem(ui->lineEdit_bez->text()));
        //Preis füllen
        ui->table_pro->setItem(anzahlReihen,2,new QTableWidgetItem(ui->lineEdit_preis->text()));


        //IDNr. leeren
        ui->lineEdit_ID->clear();
        //Bezeichnung leeren
        ui->lineEdit_bez->clear();
        //Preis leeren
        ui->lineEdit_preis->clear();

        //flag setzen das IDNr. nicht verandert werden kann
        witem->setFlags(witem->flags() & ~Qt::ItemIsEditable);


    }else {
        ui->statusbar->showMessage(tr("Fehler: IDNr. muss 4 Zeichen lang sein!"),1000);
    }
}

void MainWindow::on_btn_add_clicked(){
    addZeile();
}

void MainWindow::on_btn_save_clicked(){
    int rows = ui->table_pro->rowCount();
    int columns = ui->table_pro->columnCount();

    //Liste in der Datei speichern
    QFile file("warenliste.txt");
    //wenn öffne der Datei erfolgreich
    //nur schreibzugriff -->write only
    //inhalt der datei überschreiben -->truncate
    if(file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)){
        //schreibe liste in datei

        //öffnet textstream
        QTextStream out(&file);
        //schleife über alle elemente in der tabelle

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                    out<< ui->table_pro->item(i,j)->text();
                    //out<< liste->item(i)->text();
                    out<<",";
            }
            out<<"\n";             // (optional: for new line segmentation)
        }


        // von puffer (out) wirklich in datei schreiben
        file.flush();

        //Datei schließen !!nicht vergesen!!
        file.close();
    }

}
/*
void MainWindow::on_btn_load_clicked()
{
    //Liste aus der datei laden/öffnen
    QFile file("warenliste.txt");
    //wenn öffne der Datei erfolgreich
    if(file.open(QFile::ReadOnly | QFile::Text)){
        //liste löschen
        tabelle->clear();
        //lese aus datei in liste
        QTextStream in(&file);
        int i,j;

        while(!in.atEnd()){
            i++;
            while(getchar()!='\n') {
                tabelle->setItem(i,j,temp); //in.readLine().trimmed());
                j++;

            }
            in<<"\n";
        }

        //File schließen
        file.close();
    } //if ende
}


*/
