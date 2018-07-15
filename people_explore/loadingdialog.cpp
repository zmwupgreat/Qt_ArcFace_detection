#include "loadingdialog.h"
#include "ui_loadingdialog.h"

LoadingDialog::LoadingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}

LoadingDialog::~LoadingDialog()
{
    delete ui;
}
