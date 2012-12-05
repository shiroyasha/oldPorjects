#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand ( time(NULL) );

    ui->prijavi->setEnabled(false);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::init()
{

    uradjeni = 0;
    neuradjeni = 0;
    nebitni = 0;

    std::ifstream ulaz("fajl1.dat");

    char proba = 0;
    ulaz >> proba;

    for( int i = 0; i < 790; ++i)
    {
        ulaz >> m_status[i];

        if(m_status[i] == 'u') uradjeni++;
        else if( m_status[i] == 'n') neuradjeni++;
        else if( m_status[i] == '0') nebitni++;
    }

    ulaz.close();

    ui->label->setText( "Uradjeno : " + QString::number(uradjeni) );
    ui->label_2->setText( "Neuradjeni : " + QString::number(neuradjeni) );
    ui->label_3->setText( "Nebitni : " + QString::number(nebitni) );
}

void MainWindow::on_napravi_clicked()
{
    int pomocni = 10;

    while( pomocni > 0 )
    {
        int broj = rand() % 790 + 1;
        std::cout << broj << std::endl;
        if( m_status[broj] == 'n')
        {
            switch( pomocni )
            {
            case 10:
                {
                    ui->checkBox->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 9:
                {
                    ui->checkBox_2->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 8:
                {
                    ui->checkBox_3->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 7:
                {
                    ui->checkBox_4->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 6:
                {
                    ui->checkBox_5->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 5:
                {
                    ui->checkBox_6->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 4:
                {
                    ui->checkBox_7->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 3:
                {
                    ui->checkBox_8->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 2:
                {
                    ui->checkBox_9->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            case 1:
                {
                    ui->checkBox_10->setText( "z " + QString::number( broj));
                    m_trenutni[pomocni] = broj;
                    break;
                }
            }
            pomocni--;
        }
    }
    ui->prijavi->setEnabled(true);
}

void MainWindow::on_prijavi_clicked()
{
    if( ui->checkBox->isChecked() == true ) m_status[ m_trenutni[1] ] = 'u';
    else if( ui->checkBox_11->isChecked() == true ) m_status[ m_trenutni[1] ] = '0';
    else m_status[ m_trenutni[1] ] = 'n';

    if( ui->checkBox_2->isChecked() == true ) m_status[ m_trenutni[2] ] = 'u';
    else if( ui->checkBox_12->isChecked() == true ) m_status[ m_trenutni[2] ] = '0';
    else m_status[ m_trenutni[2] ] = 'n';

    if( ui->checkBox_3->isChecked() == true ) m_status[ m_trenutni[3] ] = 'u';
    else if( ui->checkBox_13->isChecked() == true ) m_status[ m_trenutni[3] ] = '0';
    else m_status[ m_trenutni[3] ] = 'n';

    if( ui->checkBox_4->isChecked() == true ) m_status[ m_trenutni[4] ] = 'u';
    else if( ui->checkBox_14->isChecked() == true ) m_status[ m_trenutni[4] ] = '0';
    else m_status[ m_trenutni[4] ] = 'n';

    if( ui->checkBox_5->isChecked() == true ) m_status[ m_trenutni[5] ] = 'u';
    else if( ui->checkBox_15->isChecked() == true ) m_status[ m_trenutni[5] ] = '0';
    else m_status[ m_trenutni[5] ] = 'n';

    if( ui->checkBox_6->isChecked() == true ) m_status[ m_trenutni[6] ] = 'u';
    else if( ui->checkBox_16->isChecked() == true ) m_status[ m_trenutni[6] ] = '0';
    else m_status[ m_trenutni[6] ] = 'n';

    if( ui->checkBox_7->isChecked() == true ) m_status[ m_trenutni[7] ] = 'u';
    else if( ui->checkBox_17->isChecked() == true ) m_status[ m_trenutni[7] ] = '0';
    else m_status[ m_trenutni[7] ] = 'n';

    if( ui->checkBox_8->isChecked() == true ) m_status[ m_trenutni[8] ] = 'u';
    else if( ui->checkBox_18->isChecked() == true ) m_status[ m_trenutni[8] ] = '0';
    else m_status[ m_trenutni[8] ] = 'n';

    if( ui->checkBox_9->isChecked() == true ) m_status[ m_trenutni[9] ] = 'u';
    else if( ui->checkBox_19->isChecked() == true ) m_status[ m_trenutni[9] ] = '0';
    else m_status[ m_trenutni[9] ] = 'n';

    if( ui->checkBox_10->isChecked() == true ) m_status[ m_trenutni[10] ] = 'u';
    else if( ui->checkBox_20->isChecked() == true ) m_status[ m_trenutni[10] ] = '0';
    else m_status[ m_trenutni[10] ] = 'n';

    std::ofstream izlaz("fajl1.dat");

    for( int i = 0; i < 790; ++i)
    {
        izlaz << m_status[i];
    }
    izlaz.close();

    init();

    ui->prijavi->setEnabled(false);
}
